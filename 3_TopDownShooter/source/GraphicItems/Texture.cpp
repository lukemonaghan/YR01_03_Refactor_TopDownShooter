#include "GraphicItems/Texture.h"
#include "AIE.h"

//Constructor/Destructor
cTexture::cTexture(){
	uiSprite = 0;
	UV.v = 0;
	UV.u = 0;
	UVInc.u = 1;
	UVInc.v = 1;
	AniTimer= 0;
}
//Draw
void cTexture::DrawTex(float x, float y,float rot){
	RotateSprite(uiSprite,rot);
	MoveSprite(uiSprite,x,y);
	DrawSprite(uiSprite);

}
unsigned int cTexture::GetSpriteID(){
	return uiSprite;
}
//UV increment and Dincrement
void cTexture::IncU(){
	UV.u+=UVInc.u;
	if (UV.u>1.0f){
		UV.u=0.0f;
	}
}
void cTexture::IncV(){
	UV.v+=UVInc.v;
	if (UV.v>1.0f){
		UV.v=0.0f;
	}
}
void cTexture::DIncU(){
	UV.u-=UVInc.u;
	if (UV.u<0.0f){
		UV.u=1.0f-UVInc.u;
	}
}
void cTexture::DIncV(){
	UV.v-=UVInc.v;
	if (UV.v<0.0f){
		UV.v=1.0f-UVInc.v;
	}
}