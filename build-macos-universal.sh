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

# FastNoiseSIMD dispatches to hand-written SSE2/SSE4.1/AVX2/AVX512 code paths at
# runtime via CPUID, so each ISA-specific file gets ONLY the instruction-set flag
# it needs (matching the per-file flags in StarMadeNative.cbp/.vcxproj). Building
# all of them with one blanket -march would let the compiler emit e.g. AVX
# instructions inside the "SSE2 fallback" object file, which then crashes with
# SIGILL on any Mac whose CPU doesn't support AVX — exactly the case that
# fallback exists to handle.
X86_SOURCES=(
  "FastNoiseSIMD/FastNoiseSIMD_sse2.cpp:-msse2"
  "FastNoiseSIMD/FastNoiseSIMD_sse41.cpp:-msse4.1"
  "FastNoiseSIMD/FastNoiseSIMD_avx2.cpp:-march=core-avx2"
  "FastNoiseSIMD/FastNoiseSIMD_avx512.cpp:-mavx512f"
)

ARM_SOURCES=(
  "FastNoiseSIMD/FastNoiseSIMD_neon.cpp"
)

build_slice() {
  local arch="$1"
  local outdir="$2"
  mkdir -p "${outdir}"
  local objects=()
  local src base obj isa_flag

  # Compile common sources for all architectures
  for src in "${COMMON_SOURCES[@]}"; do
    base=$(basename "${src}" .cpp)
    obj="${outdir}/${base}.o"
    clang++ -arch "${arch}" "${COMMON_FLAGS[@]}" -c "${SRC_DIR}/${src}" -o "${obj}"
    objects+=("${obj}")
  done

  # Compile architecture-specific SIMD sources, each with only its own ISA flag
  if [[ "${arch}" == "x86_64" ]]; then
    for entry in "${X86_SOURCES[@]}"; do
      src="${entry%%:*}"
      isa_flag="${entry#*:}"
      base=$(basename "${src}" .cpp)
      obj="${outdir}/${base}.o"
      clang++ -arch "${arch}" "${COMMON_FLAGS[@]}" "${isa_flag}" -c "${SRC_DIR}/${src}" -o "${obj}"
      objects+=("${obj}")
    done
  elif [[ "${arch}" == "arm64" ]]; then
    for src in "${ARM_SOURCES[@]}"; do
      base=$(basename "${src}" .cpp)
      obj="${outdir}/${base}.o"
      clang++ -arch "${arch}" "${COMMON_FLAGS[@]}" -c "${SRC_DIR}/${src}" -o "${obj}"
      objects+=("${obj}")
    done
  fi

  clang++ -arch "${arch}" -dynamiclib -mmacosx-version-min=11.0 \
    -undefined dynamic_lookup \
    "${objects[@]}" -o "${outdir}/libStarMadeNative.dylib"
}

build_slice arm64 "${BUILD_DIR}/arm64"
build_slice x86_64 "${BUILD_DIR}/x86_64"

OUTPUT="${BUILD_DIR}/libStarMadeNative.dylib"
lipo -create \
  "${BUILD_DIR}/arm64/libStarMadeNative.dylib" \
  "${BUILD_DIR}/x86_64/libStarMadeNative.dylib" \
  -output "${OUTPUT}"

echo "Built ${OUTPUT}"
lipo -info "${OUTPUT}"
