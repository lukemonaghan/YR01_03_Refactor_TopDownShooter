#ifndef _PICKUP_H_
#define _PICKUP_H_

#include "Instances/Instance.h"
#include "GraphicItems/Texture.h"
#include "Maths/Vector2.h"

class cPickup : public cInstance{
public:
	cPickup();
	cPickup(cTexture cT_Tex, float fX, float fY,int actionID);
	unsigned int Check(const Vector2 &otherVect);
	void Draw();
private:
	Vector2 LengthVec;
	cTexture Tex;
	unsigned int uiAction;
};

#endif