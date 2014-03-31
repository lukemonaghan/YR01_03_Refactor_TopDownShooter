
#include <stdio.h>

#include "GameState/GameManager.h"
#include "GameState/States/GameState.h"
#include "GameState/States/SplashState.h"
#include "GameState/States/PlayState.h"
#include "GameState/States/MenuState.h"

cSplashState cSplashState::m_SplashState;

void cSplashState::Init(cGameManager* game){
	Cursor.Load();
	Background.Init(game);
	Title.uiSprite = CreateSprite( "./images/Menus/Title.png",988 , 113, true );
	AIE.  uiSprite   = CreateSprite( "./images/Menus/AIE.png", 214, 128, true );
	printf("CIntroState Init\n");	
}

void cSplashState::Cleanup(){
	printf("CIntroState Cleanup\n");
}

void cSplashState::Pause(){
}

void cSplashState::Resume(){
}

void cSplashState::HandleEvents(cGameManager* game){
	if (fTimer>1.0f){
	game->ChangeState( cMenuState::Instance() );
	}
}

void cSplashState::Update(cGameManager* game) {
	fTimer+=game->fDeltaTime;

	Cursor.Update();

	Cursor.GetPos(m_x,m_y);
	v2Offset.x =(float) m_x - (game->iScreenWidth*0.5f);
	v2Offset.y =(float) m_y - (game->iScreenHeight*0.5f);
	v2Offset = v2Offset / 32.0f;
}

void cSplashState::Draw(cGameManager* game) {
	Background.Update(v2Offset,game->iScreenWidth*0.5f,game->iScreenHeight*0.5f);
	Title.DrawTex(game->iScreenWidth*0.5f-v2Offset.x,game->iScreenHeight*0.1f-v2Offset.y);
	AIE.DrawTex  (game->iScreenWidth*0.5f-v2Offset.x,game->iScreenHeight*0.9f-v2Offset.y);
	Cursor.Draw();
}
