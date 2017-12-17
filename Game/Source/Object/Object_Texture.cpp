#include "Object_Texture.h"

map<string, Object_Texture*> Object_Texture::Object_Textures;

Object_Texture * Object_Texture::GetTexture(string pName) {
	if (Object_Textures.find(pName) == Object_Textures.end()) {
		Object_Textures[pName] = new Object_Texture(pName);
	}
	return Object_Textures.at(pName);
}

Object_Texture::Object_Texture(string pName) {
	pName = "Resources/" + pName + ".png";
	D3DXIMAGE_INFO		pImageInfo;
	LPCSTR				pSrcFile = pName.c_str();
	D3DXGetImageInfoFromFileA(pSrcFile, &pImageInfo);
	D3DXCreateTextureFromFileExA
	(
		GameGlobal::GetDevice(),		// Đại diện cho thiết bị
		pSrcFile,						// Đường dẫn đến file
		pImageInfo.Width,
		pImageInfo.Height,
		D3DX_FROM_FILE,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0xffff00ff,						// Màu trong suốt có dạng 0x12345678 (32 bit tất cả)
		NULL,							// [Out] Thông tin của hình ảnh
		NULL,
		&mNow						// [Out] Đại diện cho đối tượng Object_Texture
	);
}

LPDIRECT3DTEXTURE9 Object_Texture::operator&()
{
	return mNow;
}
