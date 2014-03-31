#ifndef _SLIDER_H_
#define _SLIDER_H_

#include "GraphicItems/Texture.h"
#include "GlobalFunctions.h"
#include "Maths/Vector2.h"

class cSlider{
public:
	cSlider(){};
	void Load(float fX, float fY,char* String,int max = 100);
	void Draw(float fX, float fY, int iRot = 0,bool flip = false);
	int Update(int current = 0,bool clickable = false);
private:
	float fMax,fCurrent;
	cTexture uiBar,uiSlider;
	Vector2 Pos;
	char* cString;
};				

#endif