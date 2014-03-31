
#ifndef _HELPSTATE_H_
#define _HELPSTATE_H_

#include "GameState/States/GameState.h"
#include "GraphicItems/Background.h"
#include "GraphicItems/Button.h"
#include "GraphicItems/Texture.h"
#include "GraphicItems/Cursor.h"

class cHelpState : public cGameState
{
public:
	void Init(cGameManager* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(cGameManager* game);
	void Update(cGameManager* game);
	void Draw(cGameManager* game);

	static cHelpState* Instance() {return &m_HelpState;}

protected:
	cHelpState() { }

private:
	static cHelpState m_HelpState;
	int m_x, m_y;
	bool bClicked;
	bool bHelp;
	Vector2 v2Offset;

	cTexture Title;
	cBackground Background;
	cCursor Cursor;

	cTexture Help1;
	cTexture Help2;

	cButton ButtonExit;
	cButton ButtonBack;
};

#endif