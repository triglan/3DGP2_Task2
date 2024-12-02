#include "Mode1.h"
#include "MouseUtil.h"

#include "Control.h"
#include "Skybox.h"
#include "enemy.h"
#include "Terrain.h"
#include "CameraController.h"

// �ش� cpp���ϰ� h������ Ư���� ��带 �����ϰ�, �ش� ��忡 �����ϴ� ��ü���� ��Ʈ���ϱ� ���� �����̴�.
// �ݵ�� cpp, h���Ϸ� �и��Ǿ��־�� �ϸ�, �� ��忡 ���� ���ӽ����̽��� ���еǾ���Ѵ�.
// ���Ӹ��::Start() ������ ��� �Լ� ���ӽ����̽��� ��� �̸��� �ۼ��ϴ� ���� �����Ѵ�
// �Ʒ��� ���� ������ ��� ���� �Լ� �� ��Ʈ�ѷ� �Լ��� �ۼ����ֱ⸸ �ϸ� �����ӿ�ũ�� �˾Ƽ� ���ش�.
// ���α׷� ���� �� �Ʒ��� �Լ����� [ DirectX 3D ] -> [ Main ] -> Scene.cpp�� �ִ� Init() �Լ����� ����ȴ�.
// �Ǵ� ��� ���� �� ����ȴ�.
// ���� ������ Scene.cpp���� �����ϵ��� �Ѵ�.

// ������ ��� �ڵ� �ۼ��� ���� [ Template ] ���Ϳ� ���ø��� ����� �ξ����� ������ �� �Լ� �̸��� ���ӽ����̽� �̸��� �ٲٸ� �ȴ�.

void Mode1::Start() {
	// ���� ȭ�鿡���� ����� ȸ������ ����
	SetBackgroundColor(0.3, 0.31, 0.3);
	// �ʿ��� ��ü �߰�
	scene.AddObject(new CameraController, "cam_controller", LAYER_1);
	scene.AddObject(new Control, "control", LAYER_1);
	scene.AddObject(new Skybox, "Skybox", LAYER_1);
	scene.AddObject(new Enemy, "enemy", LAYER_1);
	for (int i = 0; i < 25; ++i)
		scene.AddObject(new Terrain(i / 5 * 120 - 360, i % 5 * 120), "terrain", LAYER_1);
	//scene.AddObject(new Terrain, "terrain", LAYER_1);
	// scene�� ��Ʈ�ѷ� �� ��� �Ҹ��� ���
	RegisterController();

	// ��� �̸��� Scene�� ���
	scene.RegisterModeName("Mode1");
}

void Mode1::Destructor() {
	// ���⿡ ��� ���� �� �ʿ��� �۾� �߰� (���ҽ� �޸� ���� ��)
}

void Mode1::KeyboardController(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {
	// esc ���� �� ���α׷� ����
	if (nMessageID == WM_KEYDOWN && wParam == VK_ESCAPE)
		scene.SwitchMode(HomeMode::Start);//Home���� �̵�

	// ��ü�� Ű���� �Է�
	scene.InputKey(hWnd, nMessageID, wParam, lParam, "control");
	scene.InputKey(hWnd, nMessageID, wParam, lParam, "cam_controller");
}

//  ���콺 ����� ������ ��ü �����ͷ� �����Ѵ�
void Mode1::MouseMotionController(HWND hWnd) {
	// ���콺 ��ǥ�� ����Ʈ ��ǥ�� ��ȯ�Ѵ�.
	mouse.UpdateMousePosition(hWnd);

	// ��ü�� ���콺 ��� �Է�
	scene.InputMouseMotion(hWnd, "control");
	scene.InputMouseMotion(hWnd, "cam_controller");
}

// ���콺 ��ư Ŭ�� �̺�Ʈ�� ������ ��ü �����ͷ� �����Ѵ�
void Mode1::MouseController(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {
	// ��ü�� ���콺 �Է�
	scene.InputMouse(hWnd, nMessageID, wParam, lParam, "control");
	scene.InputMouse(hWnd, nMessageID, wParam, lParam, "cam_controller");
}

// scene�� ��Ʈ�ѷ� �� ��� �Ҹ��� ���
void Mode1::RegisterController() {
	scene.RegisterKeyController(KeyboardController);
	scene.RegisterMouseController(MouseController);
	scene.RegisterMouseMotionController(MouseMotionController);
	scene.RegisterDestructor(Destructor);
}