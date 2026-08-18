# StarMade targets Java 21 — JNI headers must match the JDK used to run the game.
# Set JAVA_HOME, or pass JAVADIR= / JAVAOSDIR= on the make command line (Gradle does this).
JAVADIR ?= $(JAVA_HOME)/include
JAVAOSDIR ?= $(JAVA_HOME)/include/linux

# set the compiler
CC = g++
# set the cpu bits
ARCH = -m64
# Common flags shared by every translation unit.
COMMON_OPTS = -Wall -std=c++11 -fpic -O3
# FastNoiseSIMD dispatches to hand-written SSE2/SSE4.1/AVX2/AVX512 code paths at
# runtime via CPUID (see FastNoiseSIMD::GetFastestSIMD), so each ISA-specific file
# below is compiled with ONLY the instruction-set flag it needs — matching the
# per-file flags already used by StarMadeNative.cbp and StarMadeNative.vcxproj.
# Compiling every file with one blanket -march would let the compiler emit e.g.
# AVX instructions inside the "SSE2 fallback" object file, which then crashes with
# SIGILL on any CPU that doesn't support AVX — exactly the case that fallback
# exists to handle.
SSE2_OPTS = -msse2
SSE41_OPTS = -msse4.1
AVX2_OPTS = -march=core-avx2
AVX512_OPTS = -mavx512f
.DEFAULT_GOAL := all

all: generate

generate:
	@if [ -z "$(strip $(JAVADIR))" ] || [ -z "$(strip $(JAVAOSDIR))" ]; then \
		echo "Error: set JAVA_HOME to JDK 21+ or pass JAVADIR and JAVAOSDIR to make."; exit 1; \
	fi
	@test -f "$(JAVADIR)/jni.h" || (echo "Error: jni.h not found under JAVADIR=$(JAVADIR) (need JDK 21+)"; exit 1)
	mkdir -p obj/Release/FastNoiseSIMD
	mkdir -p bin/Release
	${CC} ${COMMON_OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD.o
	${CC} ${COMMON_OPTS} ${AVX2_OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_avx2.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx2.o
	${CC} ${COMMON_OPTS} ${AVX512_OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_avx512.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx512.o
	${CC} ${COMMON_OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_internal.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_internal.o
	${CC} ${COMMON_OPTS} ${SSE2_OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_sse2.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse2.o
	${CC} ${COMMON_OPTS} ${SSE41_OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_sse41.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse41.o
	${CC} ${COMMON_OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD_JNI.cpp -o obj/Release/FastNoiseSIMD_JNI.o
	${CC} -shared  obj/Release/FastNoiseSIMD/FastNoiseSIMD.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx2.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx512.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_internal.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse2.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse41.o obj/Release/FastNoiseSIMD_JNI.o  -o bin/Release/libStarMadeNative64.so ${ARCH} -s
	@echo "Built all files successfully."
	@echo "libStarMadeNative64.so can be found in bin/Release"
clean:
	rm -r ./bin ./obj
	@echo "Cleaned."
