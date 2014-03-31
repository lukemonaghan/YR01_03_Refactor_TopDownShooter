
#include <stdio.h>

#include "GameState/GameManager.h"
#include "GameState/States/HelpState.h"
#include "GameState/States/MenuState.h"

cHelpState cHelpState::m_HelpState;

void cHelpState::Init(cGameManager* game){
	Cursor.Load();
	Background.Init(game);
	Title.uiSprite = CreateSprite( "./images/Menus/Title.png", 988 , 113, true );
	Help1.uiSprite = CreateSprite( "./images/Menus/Help.png" , game->iScreenWidth*0.8 , game->iScreenHeight*0.8 , true );
	Help2.uiSprite = CreateSprite( "./images/Menus/Help2.png", game->iScreenWidth*0.8 , game->iScreenHeight*0.8 , true );
	ButtonExit.LoadTex();
	ButtonExit.Init   ("Exit"   ,game->iScreenWidth-90     ,game->iScreenHeight*0.6    ,144,122,ButtonExit.GetSpriteID(true),ButtonExit.GetSpriteID(false));
	ButtonBack.Init   ("Back"   ,90                        ,game->iScreenHeight*0.6    ,144,122,ButtonExit.GetSpriteID(true),ButtonExit.GetSpriteID(false));
	printf("CHelpState Init\n");
}

void cHelpState::Cleanup(){
	printf("CHelpState Cleanup\n");

}

void cHelpState::Pause(){
}

void cHelpState::Resume(){;
}

void cHelpState::HandleEvents(cGameManager* game){
}

void cHelpState::Update(cGameManager* game) {
	Cursor.Update();

	Cursor.GetPos(m_x,m_y);
	v2Offset.x =(float) m_x - (game->iScreenWidth*0.5f);
	v2Offset.y =(float) m_y - (game->iScreenHeight*0.5f);
	v2Offset = v2Offset / 32.0f;
	if (GetMouseButtonDown(MOUSE_BUTTON_1) && !bClicked){
		bClicked = true;
		bHelp = !bHelp;
	}
	if (!GetMouseButtonDown(MOUSE_BUTTON_1) && bClicked){
		bClicked = false;
	}
}

void cHelpState::Draw(cGameManager* game){
	Background.Update(v2Offset,game->iScreenWidth*0.5f,game->iScreenHeight*0.5f);

	Title.DrawTex(game->iScreenWidth*0.5-v2Offset.x,game->iScreenHeight*0.1-v2Offset.y);

	switch (bHelp){
	case 0:
		Help1.DrawTex(game->iScreenWidth*0.5-v2Offset.x,game->iScreenHeight*0.5-v2Offset.y);
		break;
	case 1:
		Help2.DrawTex(game->iScreenWidth*0.5-v2Offset.x,game->iScreenHeight*0.5-v2Offset.y);
		break;
	}

	if (ButtonExit.Update(v2Offset,m_x,m_y)){
		game->bRunning = false;
	}
	if (ButtonBack.Update(v2Offset,m_x,m_y)){
		game->ChangeState( cMenuState::Instance() );
	}
	Cursor.Draw();
}
