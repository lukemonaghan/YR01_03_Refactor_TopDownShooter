#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "GameState\GameManager.h"
#include "Texture.h"
#include "Button.h"
#include "maths\Vector2.h"

class cBackground{
public:
	cBackground(){};
	void Init(cGameManager* game);
	void Update(Vector2 v2Offset,float fX, float fY);
private:
	cTexture TexBackground;
	cTexture TexOverlay1;
};
#endif