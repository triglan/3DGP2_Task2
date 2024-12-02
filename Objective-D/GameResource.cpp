#include "GameResource.h"
#include <random>
// �� ������ ���ҽ��� �����Ѵ�.
// �⺻������ ���� ���ҽ��̸�, ResourceManager.h�� ���� extern ������ ��, �� ���Ͽ� �Ʒ��� ���� �����ϸ� �ȴ�.
// Scene::Init()���� ����ȴ�.

Mesh* HelicopterBodyMesh, * HelicopterHeadMesh;
Mesh* TerrainMesh;
Mesh* GunMesh;

// �Ž��� ���⼭ �ε��Ѵ�.
void LoadMesh(ID3D12Device* Device, ID3D12GraphicsCommandList* CmdList) {
	ImportMesh(Device, CmdList, GunMesh, "Resources//Models//model.bin", MESH_TYPE_BIN);

	ImportMesh(Device, CmdList, HelicopterBodyMesh, "Resources//Models//GunShip.bin", MESH_TYPE_BIN);
	ImportMesh(Device, CmdList, HelicopterHeadMesh, "Resources//Models//Rotor.bin", MESH_TYPE_BIN);
	ImportMesh(Device, CmdList, TerrainMesh, "Resources//Models//terrain.bin", MESH_TYPE_BIN);
}
/////////////////////////////////////////////////////////////////////////////////


Texture* Tex;
Texture* LineTex, * GuideTex;
Texture* HelicopterTex, * WoodTex, * SkyboxTex, * TerrainTex;

// �ý�ó�� ���⼭ �ε��Ѵ�.
void LoadTexture(ID3D12Device* Device, ID3D12GraphicsCommandList* CmdList) {
	ImportTexture(Device, CmdList, Tex, L"Resources//Image//Gun.jpg", TEXTURE_TYPE_WIC);
	//ImportTexture(Device, CmdList, SkyboxTex, L"Resources//Image//SkyBox_0.dds", TEXTURE_TYPE_DDS);
	ImportTexture(Device, CmdList, WoodTex, L"Resources//Image//Wood.jpg", TEXTURE_TYPE_WIC);

	ImportTexture(Device, CmdList, LineTex, L"Resources//SystemResources//Textures//line_tex.png", TEXTURE_TYPE_WIC);
	ImportTexture(Device, CmdList, GuideTex, L"Resources//Image//guide.png", TEXTURE_TYPE_WIC);
	ImportTexture(Device, CmdList, TerrainTex, L"Resources//Image//grass.jpg", TEXTURE_TYPE_WIC);
	ImportTexture(Device, CmdList, HelicopterTex, L"Resources//Image//GunShip.png", TEXTURE_TYPE_WIC);
	ImportTexture(Device, CmdList, SkyboxTex, L"Resources//Image//skytex.png", TEXTURE_TYPE_WIC);
}
/////////////////////////////////////////////////////////////////////////////////


Object_Shader* ObjectShader;
Boundbox_Shader* BoundboxShader;
Image_Shader* ImageShader;
Line_Shader* LineShader;

// ���̴��� ���⼭ �ε��Ѵ�.
void LoadShader(ID3D12RootSignature* RootSignature, ID3D12Device* Device, ID3D12GraphicsCommandList* CmdList) {
	// �Ϲ� ������ ���̴� ����
	ObjectShader = new Object_Shader();
	// �⺻ ���������� ����
	ObjectShader->CreateDefaultPS(Device, RootSignature);
	// ���� �˻� ������ ���������� ����
	ObjectShader->CreateNoneDepthPS(Device, RootSignature);

	// �̹��� ��¿� ���������� ����
	ImageShader = new Image_Shader();
	ImageShader->CreateNoneDepthPS(Device, RootSignature);

	// �ٿ��ڽ� ���̴� ����
	BoundboxShader = new Boundbox_Shader();
	BoundboxShader->CreateWireframePS(Device, RootSignature);
	BoundboxShader->CreateDefaultPS(Device, RootSignature);

	// ���� �귯�� ��¿� ���̴� ����
	LineShader = new Line_Shader();
	LineShader->CreateNoneDepthPS(Device, RootSignature);
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// ���ε� ���۸� ó���ϱ� ���� ����
std::vector<Mesh*> LoadedMeshList;
std::vector<Texture*> LoadedTextureList;

Mesh* ImagePannel;
Mesh* SkyboxMesh;
Mesh* BoundMesh;
Mesh* BoundingSphereMesh;

// �⺻ ���� �Ž� �ε�
void LoadSystemMesh(ID3D12Device* Device, ID3D12GraphicsCommandList* CmdList) {
	ImagePannel = new Mesh;
	ImagePannel->CreateImagePannelMesh(Device, CmdList);
	LoadedMeshList.emplace_back(ImagePannel);

	// ��ī�̹ڽ� ��¿� �Ž� ����
	SkyboxMesh = new Mesh;
	SkyboxMesh->CreateSkyboxMesh(Device, CmdList);
	LoadedMeshList.emplace_back(SkyboxMesh);

	// �ٿ��ڽ� ��¿� �Ž� ����
	BoundMesh = new Mesh;
	BoundMesh->CreateBoundboxMesh(Device, CmdList);
	LoadedMeshList.emplace_back(BoundMesh);

	// �ٿ�彺��� ��¿� �Ž� ����
	BoundingSphereMesh = new Mesh(Device, CmdList, "Resources//SystemResources//Models//BoundingSphereMesh.txt", MESH_TYPE_TEXT);
	LoadedMeshList.emplace_back(BoundingSphereMesh);
}

// ���ε� ���۸� �����ϰ�, ���͸� ����.
void ClearUploadBuffer() {
	for (auto const& MeshPtr : LoadedMeshList)
		MeshPtr->ReleaseUploadBuffers();

	for (auto const& TexturePtr : LoadedTextureList)
		TexturePtr->ReleaseUploadBuffers();

	LoadedMeshList.clear();
	LoadedTextureList.clear();
}