////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#ifndef _ENEMY
#define _ENEMY

#include "AIE.h"
#include "GraphicItems/Texture.h"
#include "Instances/Instance.h"
#include "Instances/Children/Player.h"
#include "Maths/Vector2.h"
#include "Maps/Map1.h"

#include <random>

class cEnemy: public cInstance {
public:
	cEnemy();
	cEnemy(unsigned int id,int iX, int iY);
	//Member Functions
	unsigned int Create();
	bool Update(cPlayer &plr,cMap1 *Map,float dt);
	void Shadow();
	void Draw();
	//public vars
	int Health;
private:
	unsigned char ucOpacity;
	cTexture Sprite;
	float fSpeedMax;
	float fSpeed;
	Vector2 tvect;
	bool check;
};

#endif