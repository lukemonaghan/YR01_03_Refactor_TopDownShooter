////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#ifndef _BULLET_H_
#define _BULLET_H_

#include "Maths\Vector2.h"
#include "Maths\Maths.h"
#include "Instances\Instance.h"
#include "GraphicItems\Texture.h"
#include "Maps\Map1.h"

class cBullet : public cInstance {
public:
	cBullet();
	cBullet(unsigned int id,int iX, int iY,float dir,int damage,float spd);
	//Member Functions
	unsigned int Create();
	int Update(const float &dt,cMap1 *ThisMap);
	void Draw();
private:
	int iDamage;
	float fSpeed;
	cTexture Sprite;
	Vector2 vDir;
};

#endif