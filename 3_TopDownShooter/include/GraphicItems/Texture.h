////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include "Maths/Vector2.h"
#include "AIE.h"

class cTexture{
public:
	//Constructor
	cTexture();
//Member Functions
	void DrawTex(float x,float y, float rot = 0.0f);
	unsigned int GetSpriteID();
	void IncU();
	void IncV();
	void DIncU();
	void DIncV();
//Vars
	unsigned int uiSprite;
	Vector2 UV;
	Vector2 UVInc;
	float AniTimer;
};

#endif