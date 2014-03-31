
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState/States/GameState.h"
#include "GlobalFunctions.h"

#include "Controllers/BulletController.h"
#include "Controllers/EnemyController.h"
#include "Controllers/PickupController.h"
#include "Controllers/WeaponController.h"

#include "Instances/Children/Player.h"
#include "GraphicItems/Slider.h"
#include "GraphicItems/Cursor.h"

#include "Maps/Map1.h"

class cPlayState : public cGameState{
public:
	void Init(cGameManager* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(cGameManager* game);
	void Update(cGameManager* game);
	void Draw(cGameManager* game);

	static cPlayState* Instance() {return &m_PlayState;}

protected:
	cPlayState() { }
private:
	static cPlayState m_PlayState;
	int m_x, m_y;
	int rad;

	Vector2 v2Offset;
	cTexture HUD;
	cSlider EnergySlider;
	cSlider HealthSlider;
	cCursor Cursor;

	cMap1 Map;
	cPlayer Player;
	cEnemyController EnemyCon;
	cBulletController BulletCon;
	cPickupController PickupCon;
	cWeaponController WeaponCon;
};	

#endif
