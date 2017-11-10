#include <d3d9.h>
#include <d3dx9.h>

class SourceRect : public RECT {
public:
	void Set(int pLeft, int pTop, int pRight, int pBottom) {
		this->left = pLeft;
		this->top = pTop;
		this->right = pRight;
		this->bottom = pBottom;
	}
	void Set(RECT pRect) {
		Set(pRect.left, pRect.top, pRect.right, pRect.bottom);
	}
};

typedef SourceRect UNIT_SOURCERECT;