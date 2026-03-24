# StarMade targets Java 25 — JNI headers must match the JDK used to run the game.
# Set JAVA_HOME, or pass JAVADIR= / JAVAOSDIR= on the make command line (Gradle does this).
JAVADIR ?= $(JAVA_HOME)/include
JAVAOSDIR ?= $(JAVA_HOME)/include/linux

# set the compiler
CC = g++
# set the cpu bits
ARCH = -m64
# set the compiler options
OPTS = -Wall -std=c++11 -fpic -march=core-avx2 -O3
.DEFAULT_GOAL := all

all: generate

generate:
	@if [ -z "$(strip $(JAVADIR))" ] || [ -z "$(strip $(JAVAOSDIR))" ]; then \
		echo "Error: set JAVA_HOME to JDK 25+ or pass JAVADIR and JAVAOSDIR to make."; exit 1; \
	fi
	@test -f "$(JAVADIR)/jni.h" || (echo "Error: jni.h not found under JAVADIR=$(JAVADIR) (need JDK 25+)"; exit 1)
	mkdir -p obj/Release/FastNoiseSIMD
	mkdir -p bin/Release
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_avx2.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx2.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_internal.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_internal.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_sse2.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse2.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_sse41.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse41.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD_JNI.cpp -o obj/Release/FastNoiseSIMD_JNI.o
	${CC} -shared  obj/Release/FastNoiseSIMD/FastNoiseSIMD.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx2.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_internal.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse2.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse41.o obj/Release/FastNoiseSIMD_JNI.o  -o bin/Release/libStarMadeNative64.so ${ARCH} -s
	@echo "Built all files successfully."
	@echo "libStarMadeNative64.so can be found in bin/Release"
clean:
	rm -r ./bin ./obj
	@echo "Cleaned."
