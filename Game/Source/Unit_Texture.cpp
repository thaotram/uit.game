#include "Unit_Texture.h"

map<string, Unit_Texture*> Unit_Texture::Unit_Textures;

Unit_Texture * Unit_Texture::GetTexture(string pName)
{
	return Unit_Textures.find(pName) == Unit_Textures.end() ?
		new Unit_Texture(pName) : Unit_Textures.at(pName);
}

Unit_Texture::Unit_Texture(string pName) {
	pName = "Resources/" + pName + ".png";
	D3DXIMAGE_INFO		pImageInfo;
	LPCSTR				pSrcFile = pName.c_str();
	D3DXGetImageInfoFromFileA(pSrcFile, &pImageInfo);
	//auto mm = (LPDIRECT3DTEXTURE9)this;
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
		&mSelf						// [Out] Đại diện cho đối tượng Unit_Texture
	);
}

LPDIRECT3DTEXTURE9 Unit_Texture::operator&()
{
	return mSelf;
}
