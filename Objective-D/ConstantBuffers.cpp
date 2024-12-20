#include "ConstantBuffers.h"
#include "CBVUtil.h"

CBV FlipCBV; // texture flip data
CBV LightCBV;  // light data
CBV BoolLightCBV;  // light bool data
CBV FogCBV; // fog data

// 상수버퍼로 사용할 버퍼 및 힙을 설정한다.
void CreateConstantBufferResource(ID3D12Device* Device) {
	// texture flipdata
	TEXTURE_FLIP_DATA TextureFlipData[4]{ {0, 0}, {1, 0}, {0, 1}, {1, 1} };
	ReserveConstantBuffer(FlipCBV, 4);
	for (int i = 0; i < 4; ++i)
		CBVUtil::Create(Device, &TextureFlipData[i], sizeof(TEXTURE_FLIP_DATA), FlipCBV, i);

	// light data
	LIGHT_DATA LighData{
		{1.0f, -1.0f, 0.0f },  // Light Position
		0.0, // padding1

		{1.0f, 0.9f, 0.8f },  // Light Color
		0.0, // padding2

		{0.1f, 0.1f, 0.1f },  // Ambient Light Color
		2.5,  // Shadow Strength
	};
	ReserveConstantBuffer(LightCBV, 1);
	CBVUtil::Create(Device, &LighData, sizeof(LIGHT_DATA), LightCBV, 0);

	// light bool data
	USE_LIGHT_DATA UselightData[2]{ {0}, {1} };
	ReserveConstantBuffer(BoolLightCBV, 2);
	for (int i = 0; i < 2; ++i)
		CBVUtil::Create(Device, &UselightData[i], sizeof(USE_LIGHT_DATA), BoolLightCBV, i);

	// fog data
	FOG_DATA FogData{
		{0.5, 0.5, 0.5}, // Fog Color
		0.0,   //   padding1

		500.0, // Fog Start
		{0.0, 0.0, 0.0}, // padding2

		1000.0, // FogEnd
		{0.0, 0.0, 0.0} // padding3
	};
	ReserveConstantBuffer(FogCBV, 1);
	CBVUtil::Create(Device, &FogData, sizeof(FOG_DATA), FogCBV, 0);
}