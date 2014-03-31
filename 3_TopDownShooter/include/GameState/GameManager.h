
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>

class cGameState;

class cGameManager{
public:
	cGameManager(int argc, char *argv[] );
	void Run();
	void Cleanup();

	void ChangeState(cGameState* state);
	void PushState(cGameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	float fDeltaTime;
	unsigned int iScreenWidth;
	unsigned int iScreenHeight;
	bool bRunning;
	int iEnemiesBegin;
	int iPickupsBegin;
private:
	// the stack of states
	std::vector<cGameState*> states;
};

#endif
