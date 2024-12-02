#pragma once
#include <tchar.h>

// ī�޶� ��� ����
// ī�޶� Ŭ���� ��� �Լ� Update(float FT)���� ������ �� ����ϴ� ������ Ŭ�����̴�. ī�޶� Ŭ�������� �ڼ��� �����ϵ��� �Ѵ�.
enum class CamMode{ TRACK_MODE };

// ���α׷� ���� �� ����� ������ ����� �����Ѵ�.
// START_WITH_FULL_SCREEN �ɼ� Ȱ��ȭ �� ����� �ػ󵵷� ����ȴ�.
constexpr int START_UP_WIDTH = 1500;
constexpr int START_UP_HEIGHT = 800;

// Ǯ��ũ�� ���� ������ ���� �����Ѵ�.
constexpr bool START_WITH_FULL_SCREEN = false;

// �ִ� ������ ������ �����Ѵ�. 0���� ���� �� �ִ� ���������� �����Ѵ�.
constexpr float FRAME_LIMITS = 0;

// �ٿ��ڽ� ǥ�� ���θ� �����Ѵ�.
#define SHOW_BOUND_BOX

// ���� ���忡 ����� ���̾ �����Ѵ�. �� �κп��� �ݵ�� EOL(End Of Layer)ǥ�⸦ �ؾ��Ѵ�.
// UI�� ��� ���� �ֻ�� ���̾ �߰��ϴ� ���� �����Ѵ�.
enum LayerEnum
{ LAYER1, LAYER2, LAYER3, EOL };

// ���� ��ġ ���� ũ�� ����, �⺻�� 200
constexpr int DELETE_LOCATION_BUFFER_SIZE = 200;

// ����ǥ���� ���ڿ��� �����Ѵ�. �ݵ�� �Ʒ��� ���� �������� �����ؾ� �Ѵ�.
constexpr TCHAR TitleName[] = _T("Objective-D(");