#pragma once
#include "GameObject.h"
#include "CameraUtil.h"
#include "GameResource.h"
#include "TransformUtil.h"
#include "TerrainUtil.h"


class Terrain : public GameObject {
public:
	TerrainUtil terrainUtil;

	//Terrain(int x, int z) {
	//	// 터레인 정보를 터레인 충돌처리 유틸에 전달한다.
	//	Transform::Move(TranslateMatrix, x, -50.0, z);
	//	Transform::Scale(ScaleMatrix, 30.0, 30.0, 30.0);
	//	terrainUtil.InputData(TranslateMatrix, RotateMatrix, ScaleMatrix, TerrainMesh);
	//}
	Terrain() {
		// 터레인 정보를 터레인 충돌처리 유틸에 전달한다.
		Transform::Move(TranslateMatrix, 0, -20.0, 0);
		Transform::Scale(ScaleMatrix, 30.0, 30.0, 30.0);
		terrainUtil.InputData(TranslateMatrix, RotateMatrix, ScaleMatrix, TerrainMesh);
	}

	// 터레인 객체에서 재정의 되어이어야 함
	TerrainUtil GetTerrain() {
		return terrainUtil;
	}

	void Render() {
		InitRenderState(RENDER_TYPE_3D_STATIC);
		FlipTexture(FLIP_TYPE_V);
		Render3D(TerrainMesh, TerrainTex);
		//terrainUtil.InputData(TranslateMatrix, RotateMatrix, ScaleMatrix, TerrainMesh);
	}
};