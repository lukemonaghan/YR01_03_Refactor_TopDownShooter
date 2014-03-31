#include "GraphicItems/Slider.h"

void cSlider::Load(float fX, float fY,char* String,int max){
	cString = String;
	Pos.x = fX;
	Pos.y = fY;
	fMax = max;
	fCurrent = fMax;
	uiBar.uiSprite    = CreateSprite( "./images/Menus/Slider/Bar.png"   ,392 ,12, true );
	uiSlider.uiSprite = CreateSprite( "./images/Menus/Slider/Slider.png",10  ,16, true );
}
int cSlider::Update(int current,bool clickable){
	if (clickable){
		int m_x,m_y;
		GetMouseLocation(m_x,m_y);
		if (m_x < (Pos.x+196) && m_x > (Pos.x-196) && 
		    m_y < (Pos.y+ 12) && m_y > (Pos.y- 12)   ){
			if (GetMouseButtonDown(MOUSE_BUTTON_1)){
				fCurrent = ((m_x - (Pos.x-196))/310)*fMax;
				fCurrent = (int)fCurrent;
				if (fCurrent > fMax){
					fCurrent = fMax;
				}
			}
		}
	}else{
		fCurrent = current;	
	}
	return fCurrent;
}

void cSlider::Draw(float fX, float fY,int iRot,bool flip){
	Pos.x = fX;
	Pos.y = fY;
	if (flip){
		SetSpriteUVCoordinates(uiBar.uiSprite,1,0,0,1);
	}else{
		SetSpriteUVCoordinates(uiBar.uiSprite,0,0,1,1);
	}
	uiBar.DrawTex   (                      fX       ,fY,iRot);
	uiSlider.DrawTex((310*(fCurrent/fMax))+fX-160   ,fY,iRot);
	DrawInt(fCurrent,(310*(fCurrent/fMax))+fX-160-16,fY-48);
	if (fCurrent > (fMax/2)){
	DrawString(cString,Pos.x-196,fY-48);
	}else{
	DrawString(cString,Pos.x+64,fY-48);
	}
}