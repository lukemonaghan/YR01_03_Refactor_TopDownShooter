
#include <stdio.h>
#include "AIE.h"
#include "GameState/GameManager.h"
#include "GameState/States/GameState.h"
#include "GameState/States/SplashState.h"

#include <iostream>
#include <time.h>

cGameManager::cGameManager(int argc, char *argv[] ){
	//get external screen size
	bool fulscr = false;
	srand((unsigned int)time(NULL));
	if (argc > 1){
		for (int i = 1; i < argc; i++) {
			if (argc == 6){
				if (_strcmpi(argv[i], "-window") == 0 || _strcmpi(argv[i], "-w") == 0 && _strcmpi(argv[i+3], "-fullscreen") == 0 || _strcmpi(argv[i+3], "-f") == 0){
					if (i + 2 <= argc - 1){
						i++;
						iScreenWidth = atoi(argv[i]);
						i++;
						iScreenHeight = atoi(argv[i]);
						i++;
						i++;
						fulscr = (bool)atoi(argv[i]);
					}else{
						std::cout << "Error with variables" << std::endl
								  << "-window 1280 780 -fullscreen 0"  << std::endl
								  << "Closing Down now" << std::endl;
						bRunning=false;
					}
				}
			}else if (_strcmpi(argv[i], "-window") == 0 || _strcmpi(argv[i], "-w") == 0){
				if (i + 2 <= argc - 1){
					i++;
					iScreenWidth = atoi(argv[i]);
					i++;
					iScreenHeight = atoi(argv[i]);
				}else{
					std::cout << "Error with variables" << std::endl
							  << "-window 1280 780"  << std::endl
							  << "Closing Down now" << std::endl;
					bRunning=false;
				}
			}else if (_strcmpi(argv[i], "-fullscreen") == 0 || _strcmpi(argv[i], "-f") == 0){
				if (i + 1 <= argc - 1){
					i++;
					fulscr = (bool)atoi(argv[i]);
					iScreenWidth = 1280;
					iScreenHeight = 780;
				}else{
					std::cout << "Error with Fullscreen params" << std::endl
							  << "-fullscreen 0"  << std::endl
							  << "Closing Down now" << std::endl;
					bRunning=false;
				}
			}
		}
	}else{
		iScreenWidth = 1280;
		iScreenHeight = 780;
	}
	bRunning = true;
	std::cout << iScreenWidth << " : " << iScreenHeight << std::endl;
	//Create OpenGL Viewport
	Initialise(  iScreenWidth, iScreenHeight, fulscr, " - Assignment 3 - Top Down Shooter - Luke Monaghan - " );
	SetBackgroundColour( SColour(0,0,0,0));
	//Setup Variables
	fDeltaTime = GetDeltaTime();
	iEnemiesBegin = 1;
	iPickupsBegin = 1;
	//Set state to splash state
	ChangeState(cSplashState::Instance());
}
void cGameManager::Run(){
	while ( bRunning == true && FrameworkUpdate() == false){
		fDeltaTime = GetDeltaTime();
		ClearScreen();
		HandleEvents();
		Update();
		Draw();
	}
	Cleanup();
}
void cGameManager::Cleanup(){
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
	Shutdown();
}

void cGameManager::ChangeState(cGameState* state) {
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
	states.push_back(state);
	states.back()->Init(this);
}

void cGameManager::PushState(cGameState* state){
	if ( !states.empty() ) {
		states.back()->Pause();
	}
	states.push_back(state);
	states.back()->Init(this);
}

void cGameManager::PopState(){
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void cGameManager::HandleEvents() {
	states.back()->HandleEvents(this);
}

void cGameManager::Update() {
	states.back()->Update(this);
}

void cGameManager::Draw() {
	states.back()->Draw(this);
}
