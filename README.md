# StarMadeNative

JNI native library (FastNoiseSIMD) for **StarMade**. Current runtime target is **Java 21** — use a **JDK 21** install for `jni.h` when compiling so the ABI matches the runtime.

### Recommended compilers / IDEs

- Windows — Visual Studio 2015+ (toolset `v140`+; override with Gradle `-PstarMadeNativeMsbuildToolset=v143` if needed)
- Linux — GCC / CodeBlocks, or `make`
- macOS — Xcode or `clang` (Command Line Tools)

## Notes

Set **`JAVA_HOME`** to your JDK 21 root before building from an IDE or terminal (Windows: Visual Studio picks up `JAVA_HOME` for `$(JAVA_HOME)\include` in the `.vcxproj`).

**CodeBlocks:** the `.cbp` assumes a JDK at `../java/jdk-21/` (symlink or copy your JDK 21 there), or change **Project → Build options → Search directories** to your `include` and `include/linux` paths.

![CBP JDK Settings](http://i.imgur.com/codt2kl.png)

## Building from the StarMade Gradle project

From the game repo (sibling `StarMadeNative` checkout by default):

- **Current host only:** `./gradlew buildStarMadeNative` then `./gradlew syncStarMadeNative`  
  On macOS this produces the universal `.dylib`; on Linux, `libStarMadeNative64.so`; on Windows x64, `StarMadeNative64.dll`. Each platform’s sync task copies into `src/main/resources/native/...` and `build/publish/native/...`.

- **Per platform (when on that OS):**  
  `syncStarMadeNativeMacos` · `syncStarMadeNativeLinux` · `syncStarMadeNativeWindows` · optional `syncStarMadeNativeWindows32`

- **Properties:** `-PstarMadeNativeDir=path` if the native repo is not `../StarMadeNative`. On Windows, if MSBuild is not on `PATH`: `-PstarMadeNativeMsbuildExe=C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe`. If toolset `v140` is missing: `-PstarMadeNativeMsbuildToolset=v143` (match your VS install). Set **`JAVA_HOME`** before Gradle so MSBuild and `make` see the same JDK 21.

## Linux (64-bit)

From this repo with **`JAVA_HOME`** set to JDK 21:

```bash
export JAVA_HOME=/usr/lib/jvm/temurin-21-jdk-amd64   # or your JDK 21 path
make clean all
```

Override JNI include paths if needed:

```bash
make JAVADIR="$JAVA_HOME/include" JAVAOSDIR="$JAVA_HOME/include/linux" clean all
```

On non-Linux platforms the OS-specific include folder may differ (e.g. `include/FreeBSD`).

Output: `bin/Release/libStarMadeNative64.so` → game path `native/linux/libStarMadeNative64.so`.

Or use **`./gradlew syncStarMadeNativeLinux`** from the game repo on a Linux host (see Gradle section above).

## macOS — universal dylib (Intel + Apple Silicon)

Distribution builds should use a **fat/universal** `libStarMadeNative.dylib` containing **x86_64** (Intel Macs) and **arm64** (Apple Silicon). The same file is loaded on both; the FastNoiseSIMD sources select SSE/AVX on Intel and NEON on ARM at compile time.

**Option A — Command Line Tools (`clang`):** from this repo, with `JAVA_HOME` pointing at JDK 21:

```bash
export JAVA_HOME=$(/usr/libexec/java_home -v 21)
./build-macos-universal.sh
```

The universal library is written to `build/macos-universal/libStarMadeNative.dylib`. Check with `lipo -info build/macos-universal/libStarMadeNative.dylib` (expect `Architectures in the fat file: x86_64 arm64`).

**Option B — Xcode:** open `StarMadeNative.xcodeproj`, set **Architectures** to `arm64 x86_64`, set **`JAVA_HOME`** for header search paths (or use the same paths as in the project file), build **Release** with **Build Active Architecture Only = No** so both slices are produced, then use **lipo** if Xcode emits separate slices.

The game loads `native/macosx/libStarMadeNative.dylib` next to `StarMade.jar`. On macOS, **`./gradlew syncStarMadeNativeMacos`** (or **`syncStarMadeNative`**) from the game repo builds and copies that file (see Gradle section above).

## Windows (Visual Studio)

Set **`JAVA_HOME`** to JDK 21 (e.g. `C:\Program Files\Eclipse Adoptium\jdk-21...`). The `StarMadeNative.vcxproj` **IncludePath** uses `$(JAVA_HOME)\include` and `$(JAVA_HOME)\include\win32`.

Open `StarMadeNative.sln` or run MSBuild on `StarMadeNative.vcxproj` for **Release** and **x64** (64-bit: `StarMadeNative64.dll`). Gradle passes `/p:IncludePath=...` if you use `syncStarMadeNativeWindows`. Output is typically `x64/Release/StarMadeNative64.dll` → `native/windows/x64/StarMadeNative64.dll`.
