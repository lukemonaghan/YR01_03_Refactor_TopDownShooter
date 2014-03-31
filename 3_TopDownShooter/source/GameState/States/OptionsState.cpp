
#include <stdio.h>

#include "GameState/GameManager.h"
#include "GameState/States/GameState.h"
#include "GameState/States/OptionState.h"
#include "GameState/States/MenuState.h"

cOptionState cOptionState::m_OptionState;

void cOptionState::Init(cGameManager* game){
	Cursor.Load();
	Title.uiSprite = CreateSprite( "./images/Menus/Title.png", 988 , 113, true );

	Background.Init(game);
	ButtonEnemies.LoadTex();

	SliderPickups.Load(0,game->iScreenHeight*0.6-32,"Pickups",15);
	SliderEnemies.Load(0,game->iScreenHeight*0.6+32,"Enemies",15);

	ButtonExit.Init   ("Exit"   ,game->iScreenWidth-90     ,game->iScreenHeight*0.6    ,144,122,ButtonEnemies.GetSpriteID(true),ButtonEnemies.GetSpriteID(false));
	ButtonBack.Init   ("Back"   ,90                        ,game->iScreenHeight*0.6    ,144,122,ButtonEnemies.GetSpriteID(true),ButtonEnemies.GetSpriteID(false));
	printf("CMenuState Init\n");
}

void cOptionState::Cleanup(){
	DestroySprite(Title.uiSprite);
	printf("CMenuState Cleanup\n");

}

void cOptionState::Pause(){
}

void cOptionState::Resume(){
}

void cOptionState::HandleEvents(cGameManager* game){
}

void cOptionState::Update(cGameManager* game) {
	Cursor.Update();

	Cursor.GetPos(m_x,m_y);
	v2Offset.x =(float) m_x - (game->iScreenWidth*0.5f);
	v2Offset.y =(float) m_y - (game->iScreenHeight*0.5f);
	v2Offset = v2Offset / 32.0f;

	game->iPickupsBegin = SliderPickups.Update(game->iPickupsBegin,true);
	game->iEnemiesBegin = SliderEnemies.Update(game->iEnemiesBegin,true);
}

void cOptionState::Draw(cGameManager* game){
	Background.Update(v2Offset,game->iScreenWidth*0.5f,game->iScreenHeight*0.5f);

	Title.DrawTex(game->iScreenWidth*0.5-v2Offset.x,game->iScreenHeight*0.1-v2Offset.y);

	if (ButtonExit.Update(v2Offset,m_x,m_y)){
		game->bRunning = false;
	}
	if (ButtonBack.Update(v2Offset,m_x,m_y)){
		game->ChangeState( cMenuState::Instance() );
	}

	SliderPickups.Draw((game->iScreenWidth*0.3)-v2Offset.x,(game->iScreenHeight*0.4)-v2Offset.y);
	SliderEnemies.Draw((game->iScreenWidth*0.7)-v2Offset.x,(game->iScreenHeight*0.4)-v2Offset.y,0,true);

	Cursor.Draw();
}


