
#include <stdio.h>

#include "GameState/GameManager.h"
#include "GameState/States/GameState.h"
#include "GameState/States/MenuState.h"
#include "GameState/States/PlayState.h"
#include "GameState/States/OptionState.h"
#include "GameState/States/HelpState.h"

cMenuState cMenuState::m_MenuState;

void cMenuState::Init(cGameManager* game){
	Cursor.Load();
	MoveCamera(0,0);
	Title.uiSprite = CreateSprite( "./images/Menus/Title.png", 988 , 113, true );
	Background.Init(game);
	ButtonPlay.LoadTex();
	ButtonPlay.Init      ("Play"      ,game->iScreenWidth*0.5    ,game->iScreenHeight*0.6    ,288,244,ButtonPlay.GetSpriteID(true),ButtonPlay.GetSpriteID(false));
	ButtonOptions.Init   ("Options"   ,game->iScreenWidth*0.5+225,game->iScreenHeight*0.6+140,288,244,ButtonPlay.GetSpriteID(true),ButtonPlay.GetSpriteID(false));
	ButtonHelp.Init      ("Help"      ,game->iScreenWidth*0.5+225,game->iScreenHeight*0.6-140,288,244,ButtonPlay.GetSpriteID(true),ButtonPlay.GetSpriteID(false));
	ButtonCustomize.Init ("Customize" ,game->iScreenWidth*0.5-225,game->iScreenHeight*0.6-140,288,244,ButtonPlay.GetSpriteID(true),ButtonPlay.GetSpriteID(false));
	ButtonHighScores.Init("HighScores",game->iScreenWidth*0.5-225,game->iScreenHeight*0.6+140,288,244,ButtonPlay.GetSpriteID(true),ButtonPlay.GetSpriteID(false));
	ButtonExit.Init      ("Exit"      ,game->iScreenWidth-90     ,game->iScreenHeight*0.6    ,144,122,ButtonPlay.GetSpriteID(true),ButtonPlay.GetSpriteID(false));
	printf("CMenuState Init\n");
}

void cMenuState::Cleanup(){
	//DestroySprite(BackGround.uiSprite);
	printf("CMenuState Cleanup\n");
}

void cMenuState::Pause(){
}

void cMenuState::Resume(){
	Cursor.GetPos(m_x,m_y);
}

void cMenuState::HandleEvents(cGameManager* game){
}

void cMenuState::Update(cGameManager* game) {
	Cursor.Update();

	Cursor.GetPos(m_x,m_y);
	v2Offset.x =(float) m_x - (game->iScreenWidth*0.5f);
	v2Offset.y =(float) m_y - (game->iScreenHeight*0.5f);
	v2Offset = v2Offset / 32.0f;
}

void cMenuState::Draw(cGameManager* game){
	Background.Update(v2Offset,game->iScreenWidth*0.5,game->iScreenHeight*0.5);

	Title.DrawTex(game->iScreenWidth*0.5-v2Offset.x,game->iScreenHeight*0.1-v2Offset.y);

	if (ButtonExit.Update(v2Offset,m_x,m_y)){
		game->bRunning = false;
	}
	if (ButtonPlay.Update(v2Offset,m_x,m_y)){
		game->ChangeState( cPlayState::Instance() );
	}
	if (ButtonOptions.Update(v2Offset,m_x,m_y)){
		game->ChangeState( cOptionState::Instance() );
	}
	if (ButtonHelp.Update(v2Offset,m_x,m_y)){
		game->ChangeState( cHelpState::Instance() );
	}
	if (ButtonCustomize.Update(v2Offset,m_x,m_y)){
		game->ChangeState( cOptionState::Instance() );
	}
	if (ButtonHighScores.Update(v2Offset,m_x,m_y)){
		game->ChangeState( cOptionState::Instance() );
	}
	Cursor.Draw();
}


