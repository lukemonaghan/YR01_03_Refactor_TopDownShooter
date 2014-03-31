
#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include "GameState/GameManager.h"
#include "GraphicItems/Texture.h"

class cGameState{
public:
	virtual void Init(cGameManager* game) = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(cGameManager* game) = 0;
	virtual void Update(cGameManager* game) = 0;
	virtual void Draw(cGameManager* game) = 0;

	void ChangeState(cGameManager* game, cGameState* state) {game->ChangeState(state);}
protected:
	cGameState() { }
};

#endif