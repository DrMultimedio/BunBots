#include <irrlicht.h>
#include "driverChoice.h"
#include <stdio.h>
#include <string.h>

#include "Game.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


int main(){

	Game* game = new Game();
	
	game->loop();

	game->drop();
 
	delete game;

	return 0;

}

