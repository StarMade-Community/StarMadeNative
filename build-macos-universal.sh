#!/usr/bin/env bash
# Universal (arm64 + x86_64) libStarMadeNative.dylib using clang from Xcode Command Line Tools.
# One fat binary for Apple Silicon (arm64) and Intel Macs (x86_64).
# Requires JAVA_HOME (e.g. same JDK as the game). Headers must match the JVM that loads the library.
set -eo pipefail

JAVA_HOME="${JAVA_HOME:-$(/usr/libexec/java_home 2>/dev/null || true)}"
if [[ -z "${JAVA_HOME}" || ! -f "${JAVA_HOME}/include/jni.h" ]]; then
  echo "Set JAVA_HOME to a JDK with include/jni.h" >&2
  exit 1
fi

SRC_DIR="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="${SRC_DIR}/build/macos-universal"
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}/arm64" "${BUILD_DIR}/x86_64"

COMMON_FLAGS=(
  -std=c++11
  -O3
  -fPIC
  -Wall
  -mmacosx-version-min=11.0
  "-I${JAVA_HOME}/include"
  "-I${JAVA_HOME}/include/darwin"
  "-I${SRC_DIR}"
  "-I${SRC_DIR}/FastNoiseSIMD"
)

SOURCES=(
  "FastNoiseSIMD/FastNoiseSIMD.cpp"
  "FastNoiseSIMD/FastNoiseSIMD_internal.cpp"
  "FastNoiseSIMD/FastNoiseSIMD_sse2.cpp"
  "FastNoiseSIMD/FastNoiseSIMD_sse41.cpp"
  "FastNoiseSIMD/FastNoiseSIMD_avx2.cpp"
  "FastNoiseSIMD_JNI.cpp"
)

build_slice() {
  local arch="$1"
  local outdir="$2"
  shift 2
  mkdir -p "${outdir}"
  local objects=()
  local src base obj
  for src in "${SOURCES[@]}"; do
    base=$(basename "${src}" .cpp)
    obj="${outdir}/${base}.o"
    # shellcheck disable=SC2068
    clang++ -arch "${arch}" "${COMMON_FLAGS[@]}" $@ -c "${SRC_DIR}/${src}" -o "${obj}"
    objects+=("${obj}")
  done
  clang++ -arch "${arch}" -dynamiclib -mmacosx-version-min=11.0 \
    -undefined dynamic_lookup \
    "${objects[@]}" -o "${outdir}/libStarMadeNative.dylib"
}

build_slice arm64 "${BUILD_DIR}/arm64"
build_slice x86_64 "${BUILD_DIR}/x86_64" -march=core-avx2

OUTPUT="${BUILD_DIR}/libStarMadeNative.dylib"
lipo -create \
  "${BUILD_DIR}/arm64/libStarMadeNative.dylib" \
  "${BUILD_DIR}/x86_64/libStarMadeNative.dylib" \
  -output "${OUTPUT}"

echo "Built ${OUTPUT}"
lipo -info "${OUTPUT}"
