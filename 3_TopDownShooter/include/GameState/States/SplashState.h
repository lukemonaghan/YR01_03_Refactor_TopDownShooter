
#ifndef _INTROSTATE_H_
#define _INTROSTATE_H_

#include "GameState/States/GameState.h"
#include "GraphicItems/Texture.h"
#include "GraphicItems/Background.h"
#include "GraphicItems/Cursor.h"

class cSplashState : public cGameState
{
public:
	void Init(cGameManager* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(cGameManager* game);
	void Update(cGameManager* game);
	void Draw(cGameManager* game);

	static cSplashState* Instance() {return &m_SplashState;}
protected:
	cSplashState() { }
private:
	static cSplashState m_SplashState;

	float fTimer;
	int m_x, m_y;

	Vector2 v2Offset;
	cTexture Title;
	cTexture AIE;
	cBackground Background;
	cCursor Cursor;
};

#endif