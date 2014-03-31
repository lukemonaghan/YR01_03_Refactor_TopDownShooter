
#ifndef _OPTIONSTATE_H_
#define _OPTIONSTATE_H_

#include "GameState/States/GameState.h"
#include "GraphicItems/Background.h"
#include "GraphicItems/Button.h"
#include "GraphicItems/Cursor.h"
#include "GraphicItems/Slider.h"

class cOptionState : public cGameState
{
public:
	void Init(cGameManager* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(cGameManager* game);
	void Update(cGameManager* game);
	void Draw(cGameManager* game);

	static cOptionState* Instance() {return &m_OptionState;}

protected:
	cOptionState() { }
private:
	static cOptionState m_OptionState;
	int m_x, m_y;
	Vector2 v2Offset;

	cTexture Title;
	cBackground Background;
	cCursor Cursor;

	cSlider SliderEnemies;
	cSlider SliderPickups;
		
	cButton ButtonEnemies;
	cButton ButtonPickups;

	cButton ButtonExit;
	cButton ButtonBack;
};

#endif