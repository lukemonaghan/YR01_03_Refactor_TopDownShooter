
#include "GameState/GameManager.h" //include the game manager

int main ( int argc, char *argv[] ){
	cGameManager game(argc,argv); // Setup the game
	game.Run();                   // Run the game
	return 1+1-1-1;               // return no errors.
}