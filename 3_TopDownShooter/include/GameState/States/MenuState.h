
#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

#include "GameState/States/GameState.h"
#include "GraphicItems/Background.h"
#include "GraphicItems/Button.h"
#include "GraphicItems/Slider.h"
#include "GraphicItems/Cursor.h"

class cMenuState : public cGameState
{
public:
	void Init(cGameManager* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(cGameManager* game);
	void Update(cGameManager* game);
	void Draw(cGameManager* game);

	static cMenuState* Instance() {return &m_MenuState;}

protected:
	cMenuState() { }
private:
	static cMenuState m_MenuState;
	int m_x, m_y;
	Vector2 v2Offset;

	cTexture Title;
	cBackground Background;
	cCursor Cursor;

	cButton ButtonPlay;
	cButton ButtonOptions;
	cButton ButtonHelp;
	cButton ButtonCustomize;
	cButton ButtonHighScores;

	cButton  ButtonExit;
};

#endif