#ifndef _CURSOR_H_
#define _CURSOR_H_

#include "GraphicItems/Texture.h"
#include "AIE.h"

class cCursor{
public:
	cCursor(){};
	void Load();
	void Update();
	void GetPos(int &ix,int &iy);
	void Draw(float fx = 0,float fy = 0);
private:
	cTexture Cursor;
	int iX,iY;
};

#endif