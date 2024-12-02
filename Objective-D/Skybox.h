#pragma once
#include "GameObject.h"
#include "CameraUtil.h"

class Skybox : public GameObject {
public:
	Skybox() {
		Transform::Scale(ScaleMatrix, 200.0, 200.0, 200.0);

	}

	void Render() {
		//RenderType = RENDER_TYPE_PERS;
		//DisableLight(CmdList);
		//ObjectAlpha = 1.0f;
		//camera.SetToDefaultMode();
		//SetColor(0.0, 0.0, 0.0);
		FlipTexture(RENDER_TYPE_3D_STATIC);
		FlipTexture(FLIP_TYPE_V);
		Render3D(SkyboxMesh, SkyboxTex);
	}
};