/* JNI bindings for FastNoiseSIMD (javah-style; use #include <jni.h> for all platforms — Apple’s JavaVM/jni.h path is obsolete with modern JDKs). */
#include <jni.h>
/* Header for class org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD */

#ifndef _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
#define _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NewFastNoiseSIMD
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewFastNoiseSIMD
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    GetSIMDLevel
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_GetSIMDLevel
  (JNIEnv *, jclass);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    SetSIMDLevel
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_SetSIMDLevel
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeFree
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFree
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetSeed
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetSeed
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeGetSeed
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeGetSeed
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFrequency
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFrequency
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetNoiseType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetNoiseType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetAxisScales
 * Signature: (JFFF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetAxisScales
  (JNIEnv *, jclass, jlong, jfloat, jfloat, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalOctaves
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalOctaves
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalLacunarity
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalLacunarity
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalGain
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalGain
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetCellularReturnType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularReturnType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetCellularDistanceFunction
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularDistanceFunction
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetCellularNoiseLookupType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularNoiseLookupType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetCellularNoiseLookupFrequency
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularNoiseLookupFrequency
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetCellularDistance2Indicies
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularDistance2Indicies
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetCellularJitter
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularJitter
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetPerturbType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetPerturbAmp
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbAmp
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetPerturbFrequency
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFrequency
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetPerturbFractalOctaves
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFractalOctaves
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetPerturbFractalLacunarity
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFractalLacunarity
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetPerturbFractalGain
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFractalGain
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetPerturbNormaliseLength
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbNormaliseLength
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeFillNoiseSet
 * Signature: (J[FIIIIII)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSet
  (JNIEnv *, jclass, jlong, jfloatArray, jint, jint, jint, jint, jint, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeFillSampledNoiseSet
 * Signature: (J[FIIIIIII)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillSampledNoiseSet
  (JNIEnv *, jclass, jlong, jfloatArray, jint, jint, jint, jint, jint, jint, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeFillNoiseSetVector
 * Signature: (J[FJFFF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSetVector
  (JNIEnv *, jclass, jlong, jfloatArray, jlong, jfloat, jfloat, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeFillSampledNoiseSetVector
 * Signature: (J[FJFFF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillSampledNoiseSetVector
  (JNIEnv *, jclass, jlong, jfloatArray, jlong, jfloat, jfloat, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NewVectorSet
 * Signature: (I[FIII)J
 */
JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewVectorSet
  (JNIEnv *, jclass, jint, jfloatArray, jint, jint, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    FreeVectorSet
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_FreeVectorSet
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
/* Header for class org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_PerturbType */

#ifndef _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_PerturbType
#define _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_PerturbType
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif
#endif
/* Header for class org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_CellularReturnType */

#ifndef _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_CellularReturnType
#define _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_CellularReturnType
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif
#endif
/* Header for class org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_CellularDistanceFunction */

#ifndef _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_CellularDistanceFunction
#define _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_CellularDistanceFunction
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif
#endif
/* Header for class org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_FractalType */

#ifndef _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_FractalType
#define _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_FractalType
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif
#endif
/* Header for class org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NoiseType */

#ifndef _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NoiseType
#define _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NoiseType
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif
#endif
