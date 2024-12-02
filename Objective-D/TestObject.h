#pragma once
#include "GameObject.h"
#include "MouseUtil.h"
#include "CameraUtil.h"
#include <cmath>

class TestObject : public GameObject {
public:
	XMFLOAT3 Position{0.0, 0.0, 0.0};
	XMFLOAT3 Rotation{};
	XMFLOAT3 RotationDest{};
	XMFLOAT3 Size{ 0.5, 0.5, 0.5 };

	LineBrush line;

	OOBB oobb;
	bool move{}, moveback{};

	TestObject() {
		line.SetColor(1.0, 1.0, 1.0);
		camera.Move(XMFLOAT3(0.0, 0.0, -2.0));
		Position.z = 5.0;
	}

	void InputMouseMotion(HWND hwnd, POINT MotionPosition) {
		if (GetCapture() == hwnd) {
			mouse.HideCursor();
			GetCapture();

			XMFLOAT2 Delta = mouse.GetMotionDelta(MotionPosition, 0.5);
			mouse.UpdateMotionPosition(MotionPosition);
			UpdateMotionRotation(RotationDest, Delta.x, Delta.y);
		}
	}

	void InputMouse(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {
		switch (nMessageID) {
		case WM_LBUTTONDOWN:
			mouse.StartMotionCapture(hWnd);
			break;

		case WM_LBUTTONUP:
			mouse.EndMotionCapture();
			break;

		case WM_RBUTTONDOWN:
			move = true;
			break;

		case WM_RBUTTONUP:
			move = false;
			break;

		case WM_MBUTTONDOWN:
			moveback = true;
			break;

		case WM_MBUTTONUP:
			moveback = false;
			break;
		}
	}

	void Update(float FT) {
		Rotation.x = std::lerp(Rotation.x, RotationDest.x, FT * 10);
		Rotation.y = std::lerp(Rotation.y, RotationDest.y, FT * 10);


		if (move) Position.z += FT * 10;
		if (moveback) Position.z -= FT * 10;
		//camera.Rotate(Rotation.x, Rotation.y, Rotation.z);
	}

	void Render() {
		/*InitRenderState(RENDER_TYPE_3D);
		SetLightUse(DISABLE_LIGHT);
		Transform::Scale(ScaleMatrix, 20.0, 20.0, 20.0);
		Render3D(SkyboxMesh, SkyboxTex, 1.0, false);*/

		// �� ���
		InitRenderState(RENDER_TYPE_3D);
		Transform::Move(TranslateMatrix, Position.x, Position.y, Position.z);
		Transform::Rotate(RotateMatrix, Rotation.x, Rotation.y, 0.0);
		Transform::Scale(ScaleMatrix, 0.4, 0.4, 0.4);
		FlipTexture(FLIP_TYPE_V);
		Render3D(GunMesh, Tex);

		oobb.Update(GunMesh, TranslateMatrix, RotateMatrix, ScaleMatrix);
		oobb.Render();

		// �̹��� ���, �̹��� ��Ⱦ�� �ڵ����� ����ȴ�.
		InitRenderState(RENDER_TYPE_2D);
		Transform::Move2D(TranslateMatrix, -0.5, 0.5);
		Transform::Scale2D(ScaleMatrix, 0.5, 0.5);
		Render2D(WoodTex);
	}
};