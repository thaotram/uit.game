#include "Sprite.h"

Sprite::Sprite(const char* filePath, D3DCOLOR colorKey)
{
	this->InitializeSprite(filePath, colorKey);
}
Sprite::~Sprite()
{
	if (mTexture != NULL) mTexture->Release();
}

void Sprite::InitializeSprite(const char* filePath, D3DCOLOR colorKey) {
	mSpriteHandler = GameGlobal::GetCurrentSpriteHandler();

	D3DXGetImageInfoFromFileA(filePath, &mImageInfo);

	mPosition = D3DXVECTOR3(0, 0, 0);
	mRotationCenter = D3DXVECTOR2(mPosition.x, mPosition.y);

	mScaling = D3DXVECTOR2(1, 1);
	mTranslation = D3DXVECTOR2(0, 0);
	mRotation = 0;

	mSourceRect.left = 0;
	mSourceRect.right = mImageInfo.Width;
	mSourceRect.top = 0;
	mSourceRect.bottom = mImageInfo.Height;

	D3DXCreateTextureFromFileExA
	(
		GameGlobal::GetCurrentDevice(), // Đại diện cho thiết bị
		filePath,						// Đường dẫn đến file
		mImageInfo.Width,
		mImageInfo.Height,
		D3DX_FROM_FILE,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		colorKey,						// Màu trong suốt có dạng 0x12345678 (32 bit tất cả)
		&mImageInfo,					// [Out] Thông tin của hình ảnh
		NULL,
		&mTexture						// [Out] Đại diện cho đối tượng Texture
	);
}

void Sprite::Draw()
{
	D3DXVECTOR2 scalingCenter = D3DXVECTOR2(mPosition.x, mPosition.y);
	D3DXVECTOR3 center = D3DXVECTOR3(
		0.0f, // 1.0f * (mSourceRect.right - mSourceRect.left) / 2,
		0.0f, // 1.0f * (mSourceRect.bottom - mSourceRect.top) / 2,
		0.0f
	);
	D3DXVECTOR2 scaling = D3DXVECTOR2(
		mScaling.x * (mIsFlipHorizontal ? -1 : 1),	// Chiều ngang
		mScaling.y * (mIsFlipVertical ? -1 : 1)	// Chiều dọc
	);

	D3DXMatrixTransformation2D(
		&mMatrix,				// [D3DXMATRIX *]: kết quả của phép biến đổi
		&scalingCenter,			// [D3DXVECTOR2 *]: trung tâm của phép biến đổi scaling
		0,						// [FLOAT]: hệ số quay khi scaling?
		&scaling,				// [D3DXVECTOR2 *]
		&mRotationCenter,		// [D3DXVECTOR2 *] 
		mRotation,				// [FLOAT]: góc quay (đơn vị radian)
		&mTranslation			// [D3DXVECTOR2 *]: tịnh tiến
	);

	D3DXMATRIX oldMatrix;
	mSpriteHandler->GetTransform(&oldMatrix);

	mSpriteHandler->SetTransform(&mMatrix);
	mSpriteHandler->Draw(
		mTexture,
		&mSourceRect,
		&center,
		&mPosition,
		D3DCOLOR_ARGB(255, 255, 255, 255)
	);

	mSpriteHandler->SetTransform(&oldMatrix);
}

D3DXIMAGE_INFO Sprite::GetImageInfo()
{
	return mImageInfo;
}
LPDIRECT3DTEXTURE9 Sprite::GetTexture()
{
	return mTexture;
}

void Sprite::SetRectWithSize(LONG top, LONG left, LONG width, LONG height)
{
	mSourceRect.left = left;
	mSourceRect.right = left + width;
	mSourceRect.top = top;
	mSourceRect.bottom = top + height;
}
void Sprite::SetRect(LONG top, LONG left, LONG bottom, LONG right)
{
	mSourceRect.left = left;
	mSourceRect.right = right;
	mSourceRect.top = top;
	mSourceRect.bottom = bottom;
}
void Sprite::SetRect(RECT rect)
{
	mSourceRect = rect;
}

bool Sprite::isRect(RECT rect)
{
	if (rect.left == rect.right) return false;
	if (rect.top == rect.bottom) return false;
	return true;
}

void Sprite::SetPosition(float x, float y)
{
	mPosition = D3DXVECTOR3(x, y, 0);
}
void Sprite::SetPosition(D3DXVECTOR2 pos)
{
	this->SetPosition(pos.x, pos.y);
}
void Sprite::SetPositionTo(float x, float y)
{
	mPosition += D3DXVECTOR3(x, y, 0);
}
void Sprite::SetPosition(D3DXVECTOR3 pos)
{
	mPosition = pos;
}
D3DXVECTOR3 Sprite::GetPosition()
{
	return mPosition;
}

void Sprite::SetScale(float x, float y)
{
	Sprite::SetScale(D3DXVECTOR2(x, y));
}
void Sprite::SetScale(D3DXVECTOR2 scaling)
{
	mScaling = scaling;
}
void Sprite::SetTranslation(D3DXVECTOR2 translation)
{
	mTranslation = translation;
}
D3DXVECTOR2 Sprite::GetScale()
{
	return mScaling;
}
D3DXVECTOR2 Sprite::GetTranslation()
{
	return mTranslation;
}

D3DXVECTOR2 Sprite::GetRotationCenter()
{
	return mRotationCenter;
}
void Sprite::SetRotation(float rotation)
{
	mRotation = rotation;
}
void Sprite::SetRotationCenter(D3DXVECTOR2 rotationCenter)
{
	mRotationCenter = rotationCenter;
}
float Sprite::GetRotation()
{
	return mRotation;
}

void Sprite::FlipHorizontal(bool flag)
{
	mIsFlipHorizontal = flag;
}
void Sprite::FlipVertical(bool flag)
{
	mIsFlipVertical = flag;
}
bool Sprite::IsFlipHorizontal()
{
	return mIsFlipHorizontal;
}
bool Sprite::IsFlipVertical()
{
	return mIsFlipVertical;
}