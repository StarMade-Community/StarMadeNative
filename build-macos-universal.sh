#!/usr/bin/env bash
# Universal (arm64 + x86_64) libStarMadeNative.dylib using clang from Xcode Command Line Tools.
# One fat binary for Apple Silicon (arm64) and Intel Macs (x86_64).
# Requires JAVA_HOME (Java 21+, ideally same JDK major as the game runtime).
# Headers should match the JVM major version that loads the library.
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

COMMON_SOURCES=(
  "FastNoiseSIMD/FastNoiseSIMD.cpp"
  "FastNoiseSIMD/FastNoiseSIMD_internal.cpp"
  "FastNoiseSIMD_JNI.cpp"
)

X86_SOURCES=(
  "FastNoiseSIMD/FastNoiseSIMD_sse2.cpp"
  "FastNoiseSIMD/FastNoiseSIMD_sse41.cpp"
  "FastNoiseSIMD/FastNoiseSIMD_avx2.cpp"
)

build_slice() {
  local arch="$1"
  local outdir="$2"
  shift 2
  mkdir -p "${outdir}"
  local objects=()
  local src base obj

  # Compile common sources for all architectures
  for src in "${COMMON_SOURCES[@]}"; do
    base=$(basename "${src}" .cpp)
    obj="${outdir}/${base}.o"
    # shellcheck disable=SC2068
    clang++ -arch "${arch}" "${COMMON_FLAGS[@]}" $@ -c "${SRC_DIR}/${src}" -o "${obj}"
    objects+=("${obj}")
  done

  # Compile x86-specific sources only for x86_64
  if [[ "${arch}" == "x86_64" ]]; then
    for src in "${X86_SOURCES[@]}"; do
      base=$(basename "${src}" .cpp)
      obj="${outdir}/${base}.o"
      # shellcheck disable=SC2068
      clang++ -arch "${arch}" "${COMMON_FLAGS[@]}" $@ -c "${SRC_DIR}/${src}" -o "${obj}"
      objects+=("${obj}")
    done
  fi

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
