#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "Unit_Animation.h"
#include "Unit.h"
#include "GameGlobal.h"
#include "GameLog.h"

using namespace std;

class Texture {
public:
	static LPDIRECT3DTEXTURE9 Get (string filePath) {
		LPDIRECT3DTEXTURE9  oTexture;
		D3DXIMAGE_INFO		pImageInfo;
		LPCSTR				pSrcFile = filePath.c_str();
		D3DXGetImageInfoFromFileA(pSrcFile, &pImageInfo);

		D3DXCreateTextureFromFileExA
		(
			GameGlobal::GetCurrentDevice(), // Đại diện cho thiết bị
			pSrcFile,						// Đường dẫn đến file
			pImageInfo.Width,
			pImageInfo.Height,
			D3DX_FROM_FILE,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0x12345678,						// Màu trong suốt có dạng 0x12345678 (32 bit tất cả)
			NULL,							// [Out] Thông tin của hình ảnh
			NULL,
			&oTexture						// [Out] Đại diện cho đối tượng Texture
		);
		return oTexture;
	};
};

typedef Texture UNIT_TEXTURE;