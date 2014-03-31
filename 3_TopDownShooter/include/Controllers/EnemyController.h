////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#ifndef _ENEMYCON_H_
#define _ENEMYCON_H_

#include "AIE.h"
#include "Instances/Children/Enemy.h"
#include "Instances/Children/Player.h"
#include "Controllers/PickupController.h"

#include <vector>

class cEnemyController{
public:
	cEnemyController(){};
	void Setup(int Enemies = 1);
	void CreateEnemy();
	int GetSize();

	void Update(cPlayer *Plr,cMap1 *map,cPickupController *PickCon,float dt);
	int Check(Vector2 vect,float rad);
	void Draw();

	void Health(int tid,int damage);
	void Cleanup();
private:
	std::vector <cEnemy> Enemies;
	int texID;
	int iEnemies;
};

#endif