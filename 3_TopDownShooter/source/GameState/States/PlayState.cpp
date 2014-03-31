
#include <stdio.h>

#include "GameState/GameManager.h"
#include "GameState/States/GameState.h"
#include "GameState/States/PlayState.h"
#include "GameState/States/MenuState.h"
#include "Maths/Maths.h"

cPlayState cPlayState::m_PlayState;

void cPlayState::Init(cGameManager* game){
	rad = Maxf(game->iScreenWidth,game->iScreenHeight);
	Cursor.Load();
	HUD.uiSprite = CreateSprite( "./images/Menus/HUD.png", game->iScreenWidth+100,game->iScreenHeight+100, true );
	EnergySlider.Load(0,0,"",Player.GetMaxEnergy());
	HealthSlider.Load(0,0,"",Player.fHealth);
	Map.MapCreate();
	Player.LoadPlayer();
	EnemyCon.Setup(game->iEnemiesBegin);
	EnemyCon.Update(&Player,&Map,&PickupCon,game->fDeltaTime);
	BulletCon.Setup();
	PickupCon.Setup(game->iPickupsBegin);
	printf("CPlayState Init\n");
}

void cPlayState::Cleanup(){
	BulletCon.Cleanup();
	EnemyCon.Cleanup();
	Player.Cleanup();
	PickupCon.Cleanup();
	printf("CPlayState Cleanup\n");
}

void cPlayState::Pause(){
}

void cPlayState::Resume(){
}

void cPlayState::HandleEvents(cGameManager* game){
}

void cPlayState::Update(cGameManager* game){
	Cursor.Update();

	Cursor.GetPos(m_x,m_y);
	//add this into cursor as a function "UpdateOffset();"
	v2Offset.x = (float) m_x - (game->iScreenWidth*0.5f);
	v2Offset.y = (float) m_y - (game->iScreenHeight*0.5f);
	v2Offset = v2Offset / 32.0f;
	//to add to weaponcontroller
	if (GetMouseButtonDown(MOUSE_BUTTON_1)){
		BulletCon.CreateBullet(Player.vect,1200,Player.fRot,game->fDeltaTime);
	}
	PickupCon.Update(&Player,&WeaponCon);
	Player.Update(game->fDeltaTime,game->iScreenWidth,game->iScreenHeight,&Map);
	//make this a check so health can be private
	if (Player.fHealth < 0.0f){
		game->ChangeState( cMenuState::Instance() );
	}

	EnemyCon.Update(&Player,&Map,&PickupCon,game->fDeltaTime);
	BulletCon.Update(game->fDeltaTime,&Map,&EnemyCon);

	EnergySlider.Update(Player.GetEnergy());
	HealthSlider.Update(Player.fHealth);
}

void cPlayState::Draw(cGameManager* game){
	Map.MapDraw(Player.vect,rad);
	
	Player.Shadow();

	PickupCon.Draw();
	Player.Draw();
	//Weapon.Draw();
	Player.DrawHead();

	EnemyCon.Draw();
	BulletCon.Draw();

	HUD.DrawTex(Player.vect.x+v2Offset.x,Player.vect.y+v2Offset.y);

	EnergySlider.Draw(Player.vect.x+v2Offset.x-(game->iScreenWidth*0.5)+170,Player.vect.y+v2Offset.y+(game->iScreenHeight*0.48));
	HealthSlider.Draw(Player.vect.x+v2Offset.x+(game->iScreenWidth*0.5)-170,Player.vect.y+v2Offset.y+(game->iScreenHeight*0.48),0,true);

	Cursor.Draw(Player.vect.x-(game->iScreenWidth*0.5),Player.vect.y-(game->iScreenHeight*0.5));
}

