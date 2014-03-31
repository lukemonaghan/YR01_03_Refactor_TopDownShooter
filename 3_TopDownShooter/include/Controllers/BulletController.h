////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#ifndef _BULLETCON_H_
#define _BULLETCON_H_

#include "AIE.h"
#include "Instances/Children/Bullet.h"
#include "Controllers/EnemyController.h"

#include <vector>

class cBulletController{
public:
	cBulletController(){};
	void Setup();
	void CreateBullet(const Vector2 &Pos,float spd,float dir,float dt);
	void Update(float dt,cMap1 *map,cEnemyController *enemycon);
	void Draw();
	int  GetSize();
	void Cleanup();
private:
	std::vector <cBullet> Bullets;
	int bullid;
};

#endif