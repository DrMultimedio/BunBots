#include <irrlicht.h>
#include "driverChoice.h"
#include <stdio.h>
#include <string.h>

#include "Game.h"



int main(){

	Game* game = new Game();
	
	game->loop();

	game->drop();
 
	delete game;

	return 0;

}

