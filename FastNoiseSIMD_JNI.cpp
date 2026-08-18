/*
StarMade Native Library
Copyright(C) 2016 Schine, GmbH

This program is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/

#include "FastNoiseSIMD_JNI.h"
#include "FastNoiseSIMD/FastNoiseSIMD.h"
#include <string.h>

#define L_2_FNP(l) reinterpret_cast<FastNoiseSIMD*>(l)
#define L_2_VSP(l) reinterpret_cast<FastNoiseVectorSet*>(l)

JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_GetSIMDLevel(JNIEnv*, jclass)
{
	return FastNoiseSIMD::GetSIMDLevel();
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_SetSIMDLevel(JNIEnv*, jclass, jint level)
{
	FastNoiseSIMD::SetSIMDLevel(level);
}

JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewFastNoiseSIMD(JNIEnv*, jclass, jint seed)
{
	return reinterpret_cast<jlong>(FastNoiseSIMD::NewFastNoiseSIMD(seed));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFree(JNIEnv*, jclass, jlong p)
{
	delete L_2_FNP(p);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetSeed(JNIEnv*, jclass, jlong p, jint seed)
{
	L_2_FNP(p)->SetSeed(seed);
}

JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeGetSeed(JNIEnv*, jclass, jlong p)
{
	return L_2_FNP(p)->GetSeed();
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFrequency(JNIEnv*, jclass, jlong p, jfloat freq)
{
	L_2_FNP(p)->SetFrequency(freq);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetNoiseType(JNIEnv*, jclass, jlong p, jint noiseType)
{
	L_2_FNP(p)->SetNoiseType(static_cast<FastNoiseSIMD::NoiseType>(noiseType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetAxisScales(JNIEnv*, jclass, jlong p, jfloat xScale, jfloat yScale, jfloat zScale)
{
	L_2_FNP(p)->SetAxisScales(xScale, yScale, zScale);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalOctaves(JNIEnv*, jclass, jlong p, jint octaves)
{
	L_2_FNP(p)->SetFractalOctaves(static_cast<unsigned int>(octaves));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalLacunarity(JNIEnv*, jclass, jlong p, jfloat lacunarity)
{
	L_2_FNP(p)->SetFractalLacunarity(lacunarity);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalGain(JNIEnv*, jclass, jlong p, jfloat gain)
{
	L_2_FNP(p)->SetFractalGain(gain);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalType(JNIEnv*, jclass, jlong p, jint fractalType)
{
	L_2_FNP(p)->SetFractalType(static_cast<FastNoiseSIMD::FractalType>(fractalType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularDistanceFunction(JNIEnv*, jclass, jlong p, jint cellularDistanceFunction)
{
	L_2_FNP(p)->SetCellularDistanceFunction(static_cast<FastNoiseSIMD::CellularDistanceFunction>(cellularDistanceFunction));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularReturnType(JNIEnv*, jclass, jlong p, jint cellularReturnType)
{
	L_2_FNP(p)->SetCellularReturnType(static_cast<FastNoiseSIMD::CellularReturnType>(cellularReturnType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularNoiseLookupType(JNIEnv* jEnv, jclass, jlong p, jint noiseType)
{
	L_2_FNP(p)->SetCellularNoiseLookupType(static_cast<FastNoiseSIMD::NoiseType>(noiseType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularNoiseLookupFrequency(JNIEnv* jEnv, jclass, jlong p, jfloat freq)
{
	L_2_FNP(p)->SetCellularNoiseLookupFrequency(freq);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularDistance2Indicies(JNIEnv* jEnv, jclass, jlong p, jint cellularDistanceIndex0, jint cellularDistanceIndex1)
{
	L_2_FNP(p)->SetCellularDistance2Indicies(cellularDistanceIndex0, cellularDistanceIndex1);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularJitter(JNIEnv* jEnv, jclass, jlong p, jfloat jitter)
{
	L_2_FNP(p)->SetCellularJitter(jitter);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbType(JNIEnv* jEnv, jclass, jlong p, jint perturbType)
{
	L_2_FNP(p)->SetPerturbType(static_cast<FastNoiseSIMD::PerturbType>(perturbType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFrequency(JNIEnv* jEnv, jclass, jlong p, jfloat perturbFreq)
{
	L_2_FNP(p)->SetPerturbFrequency(perturbFreq);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbAmp(JNIEnv* jEnv, jclass, jlong p, jfloat perturbAmp)
{
	L_2_FNP(p)->SetPerturbAmp(perturbAmp);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFractalOctaves(JNIEnv* jEnv, jclass, jlong p, jint perturbOctaves)
{
	L_2_FNP(p)->SetPerturbFractalOctaves(perturbOctaves);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFractalLacunarity(JNIEnv* jEnv, jclass, jlong p, jfloat perturbFractalLacunarity)
{
	L_2_FNP(p)->SetPerturbFractalLacunarity(perturbFractalLacunarity);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbFractalGain(JNIEnv* jEnv, jclass, jlong p, jfloat perturbFractalGain)
{
	L_2_FNP(p)->SetPerturbFractalGain(perturbFractalGain);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetPerturbNormaliseLength(JNIEnv* jEnv, jclass, jlong p, jfloat perturbNormaliseLength)
{
	L_2_FNP(p)->SetPerturbNormaliseLength(perturbNormaliseLength);
}

// These four Fill* bindings run once per noise layer per terrain chunk request (a hot path -
// see NoiseBuffers/TerrainGenerator* on the Java side), and make no other JNI calls between
// acquiring and releasing the array, so GetPrimitiveArrayCritical is safe here and avoids the
// extra copy GetFloatArrayElements is otherwise free to make on every call.
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSet(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jint xStart, jint yStart, jint zStart, jint xSize, jint ySize, jint zSize)
{
	float* arrayP = static_cast<float*>(jEnv->GetPrimitiveArrayCritical(noiseSet, nullptr));

	L_2_FNP(p)->FillNoiseSet(arrayP, xStart, yStart, zStart, xSize, ySize, zSize);

	jEnv->ReleasePrimitiveArrayCritical(noiseSet, arrayP, 0);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillSampledNoiseSet(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jint xStart, jint yStart, jint zStart, jint xSize, jint ySize, jint zSize, jint sampleScale)
{
	float* arrayP = static_cast<float*>(jEnv->GetPrimitiveArrayCritical(noiseSet, nullptr));

	L_2_FNP(p)->FillSampledNoiseSet(arrayP, xStart, yStart, zStart, xSize, ySize, zSize, sampleScale);

	jEnv->ReleasePrimitiveArrayCritical(noiseSet, arrayP, 0);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSetVector(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jlong pVS, jfloat xOffset, jfloat yOffset, jfloat zOffset)
{
	float* arrayP = static_cast<float*>(jEnv->GetPrimitiveArrayCritical(noiseSet, nullptr));

	L_2_FNP(p)->FillNoiseSet(arrayP, L_2_VSP(pVS), xOffset, yOffset, zOffset);

	jEnv->ReleasePrimitiveArrayCritical(noiseSet, arrayP, 0);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillSampledNoiseSetVector(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jlong pVS, jfloat xOffset, jfloat yOffset, jfloat zOffset)
{
	float* arrayP = static_cast<float*>(jEnv->GetPrimitiveArrayCritical(noiseSet, nullptr));

	L_2_FNP(p)->FillSampledNoiseSet(arrayP, L_2_VSP(pVS), xOffset, yOffset, zOffset);

	jEnv->ReleasePrimitiveArrayCritical(noiseSet, arrayP, 0);
}

JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewVectorSet(JNIEnv* jEnv, jclass, jint samplingScale, jfloatArray arraySet, jint sampleSizeX, jint sampleSizeY, jint sampleSizeZ)
{
	FastNoiseVectorSet* vectorSet = new FastNoiseVectorSet();

	int size = static_cast<int>(jEnv->GetArrayLength(arraySet));

	float* data = static_cast<float*>(jEnv->GetPrimitiveArrayCritical(arraySet, nullptr));

	float* dataCopy = new float[size];
	memcpy(dataCopy, data, size * sizeof(float));

	jEnv->ReleasePrimitiveArrayCritical(arraySet, data, JNI_ABORT);

	vectorSet->size = size / 3;
	vectorSet->sampleScale = static_cast<int>(samplingScale);
	vectorSet->sampleSizeX = sampleSizeX;
	vectorSet->sampleSizeY = sampleSizeY;
	vectorSet->sampleSizeZ = sampleSizeZ;
	vectorSet->xSet = dataCopy;
	vectorSet->ySet = vectorSet->xSet + vectorSet->size;
	vectorSet->zSet = vectorSet->ySet + vectorSet->size;

	return reinterpret_cast<jlong>(vectorSet);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_FreeVectorSet(JNIEnv* jEnv, jclass, jlong p)
{
	delete L_2_VSP(p);
}
