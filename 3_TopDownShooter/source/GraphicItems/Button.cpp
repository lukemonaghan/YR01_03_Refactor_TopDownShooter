#include "GraphicItems/Button.h"
#include "GlobalFunctions.h"
#include <string>

cButton::cButton(){
	fWidth = 280;
	fHeight = 244;
}
void cButton::LoadTex(){
	TexButton.uiSprite  = CreateSprite("Images/Menus/Button/Background.png",fWidth,fHeight,true);
	TexOverlay.uiSprite = CreateSprite("Images/Menus/Button/Overlay.png"   ,fWidth,fHeight,true);
}

void cButton::Init(char* Text,unsigned int PosX, unsigned int PosY,float width, float height,unsigned int buttonID,unsigned int overlayID,int cTextVal){
	bPressed = false;

	cText = Text;
	cTextValue = cTextVal;

	iLength = strlen(cText);
	Pos.x = PosX;
	Pos.y = PosY;

	fWidth  = width;
	fHeight = height;

	TexButton.uiSprite  = buttonID;
	SetSpriteScale(TexButton.uiSprite ,width,height);

	TexOverlay.uiSprite = overlayID;
	SetSpriteScale(TexOverlay.uiSprite,width,height);
}
unsigned int cButton::GetSpriteID(bool BGorHighlight){
	if (BGorHighlight){
		return TexButton.uiSprite;
	}else{
		return TexOverlay.uiSprite;
	}
}
bool cButton::Update(const Vector2 &v2Offset,float m_x,float m_y,int cTextVal,bool hold){
	SetSpriteScale(TexButton.uiSprite ,fWidth,fHeight);
	SetSpriteScale(TexOverlay.uiSprite,fWidth,fHeight);

	TexButton.DrawTex(Pos.x-v2Offset.x,Pos.y-v2Offset.y,0);
	DrawString(cText     , Pos.x-v2Offset.x-(iLength*9),Pos.y-16-v2Offset.y);
	if (cTextValue > 0){
		DrawInt(cTextValue   , Pos.x-v2Offset.x-(iLength*9),Pos.y+16-v2Offset.y);
	}

	if (m_x < (Pos.x-v2Offset.x+(fWidth *0.5f)) && m_x > (Pos.x-v2Offset.y-(fWidth *0.5f)) && 
		m_y < (Pos.y-v2Offset.x+(fHeight*0.5f)) && m_y > (Pos.y-v2Offset.y-(fHeight*0.5f))   ){
			TexOverlay.DrawTex(Pos.x-v2Offset.x,Pos.y-v2Offset.y,0);
			if (GetMouseButtonDown(MOUSE_BUTTON_1) && !hold && !bPressed){
				cTextValue = cTextVal;
				bPressed = true;
				return true;
			}else if (GetMouseButtonDown(MOUSE_BUTTON_1) && hold){
				cTextValue = cTextVal;
				return true;
			}else if (!GetMouseButtonDown(MOUSE_BUTTON_1)){
				bPressed = false;
			}
	}
	return false;
}