#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Texture.h"

class cButton{
public:
	cButton();
	void LoadTex();
	void Init(char* cText,unsigned int PosX, unsigned int PosY,float width, float height,unsigned int buttonID,unsigned int overlayID,int cTextVal = -1);
	unsigned int GetSpriteID(bool BGorHighlight);
	bool Update(const Vector2 &v2Offset,float m_x,float m_y,int cTextVal = -1,bool hold = false);
private:
	cTexture TexButton;
	cTexture TexOverlay;
	Vector2 Pos;
	int iLength;
	float fWidth,fHeight;
	char* cText;
	int cTextValue;
	bool bPressed,bDrawOverlay;
};


#endif