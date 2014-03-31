#include "Instances/Children/Pickup.h"

cPickup::cPickup(){
	vect.x = 0;
	vect.y = 0;
}
cPickup::cPickup(cTexture cT_Tex, float fX, float fY,int actionID){
	Tex = cT_Tex;
	vect.x = fX;
	vect.y = fY;
	uiAction = actionID;
}
unsigned int cPickup::Check(const Vector2 &otherVect){
	LengthVec.x = vect.x - otherVect.x;
	LengthVec.y = vect.y - otherVect.y;
	if (LengthVec.Magnitude() < 16){
		return uiAction;
	}
	return 0;
}
void cPickup::Draw(){
	SetSpriteUVCoordinates(Tex.uiSprite,Tex.UV.u,Tex.UV.v,Tex.UV.u+Tex.UVInc.u,Tex.UV.v+Tex.UVInc.v);
	Tex.DrawTex(vect.x,vect.y);
}
