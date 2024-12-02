#pragma once
#include <d3d12.h>
#include <vector>
#include "ConstantBufferData.h"

typedef struct {
	std::vector<ID3D12DescriptorHeap*> Heap;
	std::vector<ID3D12Resource*> Buffer;
	int SignatureIndex;
}CBV;

// flip CBV
extern CBV FlipCBV;

// light CBV
extern CBV LightCBV;

// light bool info CBV
extern CBV BoolLightCBV;

// fog cbv
extern CBV FogCBV;


// CBV ���� ���� �Լ���
void CreateConstantBufferResource(ID3D12Device* Device);
inline void ReserveConstantBuffer(CBV& CBV_Struct, int ReserveSize) {
	CBV_Struct.Buffer.reserve(ReserveSize);
	CBV_Struct.Heap.reserve(ReserveSize);
}