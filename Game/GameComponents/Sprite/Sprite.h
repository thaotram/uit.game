#ifndef __SPRITE__
#define __SPRITE__
#include <d3d9.h>
#include <d3dx9.h>

#include "../Game/GameGlobal.h"

class Sprite
{
protected:
	// Chỉ dùng cho kế thừa - không thể truy cập từ bên ngoài
	void InitializeSprite(const char* filePath, D3DCOLOR colorKey = NULL);

	D3DXVECTOR3             mPosition;			// Vị trí của sprite, gốc là chính giữa hình ảnh
	RECT                    mSourceRect;		// Hình chữ nhật cắt ra từ ảnh texture

	bool                    mIsFlipVertical;	// Lật theo chiều dọc
	bool					mIsFlipHorizontal;	// Lật theo chiều ngang
	float                   mRotation;			// Góc quay của Sprite tính theo radian

	D3DXVECTOR2             mScaling;			// Vector tùy chỉnh độ phóng to / thu nhỏ của texture
	D3DXVECTOR2             mTranslation;		// Vector tịnh tiến hình ảnh
	D3DXVECTOR2             mRotationCenter;	// Điểm trung tâm trong phép xoay hình (origin vector)

	D3DXIMAGE_INFO          mImageInfo;			// Thông tin hình ảnh được lấy
	LPD3DXSPRITE            mSpriteHandler;		// SpriteHandler hỗ trợ vẽ hình
	LPDIRECT3DTEXTURE9      mTexture;			// [*] Dùng khi vẽ
	D3DXMATRIX              mMatrix;			// [*] Dùng khi vẽ
public:
	Sprite(const char* filePath, D3DCOLOR colorKey = NULL);
	~Sprite();

	void Draw();

	LPDIRECT3DTEXTURE9 GetTexture();
	D3DXIMAGE_INFO GetImageInfo();

	void SetRectWithSize(LONG top, LONG left, LONG width, LONG height);
	void SetRect(LONG top, LONG left, LONG bottom, LONG right);
	void SetRect(RECT);
	bool Sprite::isRect(RECT rect);

	void SetPosition(D3DXVECTOR3 pos);
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR2 pos);
	D3DXVECTOR3 GetPosition();

	void SetScale(float x, float y);
	void SetScale(D3DXVECTOR2 scaling);
	void SetTranslation(D3DXVECTOR2 translation);
	D3DXVECTOR2 GetScale();
	D3DXVECTOR2 GetTranslation();

	D3DXVECTOR2 GetRotationCenter();
	// Đơn vị radian
	void SetRotation(float rotation);
	void SetRotationCenter(D3DXVECTOR2 rotationCenter);
	float GetRotation();

	// Chiều ngang
	void FlipHorizontal(bool flag);
	// Chiều dọc
	void FlipVertical(bool flag);
	bool IsFlipHorizontal();
	bool IsFlipVertical();

};
#endif