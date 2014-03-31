#include "GraphicItems/Background.h"

void cBackground::Init(cGameManager* game){
	TexBackground.uiSprite = CreateSprite("Images/Menus/Background.png"       ,game->iScreenWidth,game->iScreenHeight,true);
	TexOverlay1.uiSprite   = CreateSprite("Images/Menus/BackgroundOverlay.png",game->iScreenWidth+100,game->iScreenHeight+100,true);
}								   
								   
void cBackground::Update(Vector2 v2Offset,float fX, float fY){	
	TexBackground.DrawTex(fX,fY,0);
	TexOverlay1.DrawTex(fX+v2Offset.x,fY+v2Offset.y);
	TexOverlay1.DrawTex(fX+(v2Offset.x*2 ),fY+(v2Offset.y*2 ));
	TexOverlay1.DrawTex(fX+(v2Offset.x*4 ),fY+(v2Offset.y*4 ));
	TexOverlay1.DrawTex(fX+(v2Offset.x*6 ),fY+(v2Offset.y*6 ));
	TexOverlay1.DrawTex(fX+(v2Offset.x*8 ),fY+(v2Offset.y*8 ));
}