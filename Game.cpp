#include "Game.h"
#include "driverChoice.h"
Game::Game()
{
	// ask user for driver
	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
    //definimos receiver 
    MyEventReceiver* receiver = new MyEventReceiver;    


    //inicializamos el dispositivo
	this->device = createDevice(driverType,
        core::dimension2d<u32>(800, 600), 16, false, false, false, receiver);
    
    
    device->setWindowCaption(L"BunBots, el videojuego");

    //definimos driver, escenas y gui 

    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();

    //agregamos objetos

	world = new World(guienv, receiver, device);

	NPC* enepece = new NPC("Paco", "Soy un ielico \n Del planeta de los ielicos \n");
	NPC* enepeceh = new NPC("Juanito", "Soy otro ielico \n Del planeta de los ielicos \n");

	Player* jugador = new Player();

	world->addNPC(enepece);
	world->addNPC(enepeceh);

	world->addPlayer(jugador);
	printf("HELLO WORLD CON TOMATICO \n");

    //esto deberia ser un prop
	scene::ISceneNode * floor = smgr->addCubeSceneNode(600.0f, 0, 0, core::vector3df(0, -4.0f, 0), core::vector3df(0, 0, 0), core::vector3df(1.0f, 0.000166f, 1.0f));
	if (floor)
	{
		floor->setMaterialTexture(0, driver->getTexture("Materials/cespe.jpg"));
		floor->setMaterialFlag(video::EMF_LIGHTING, false);
	}

	/*
	To be able to look we create a camera looking at 0, 30, -40 from 0,5,0.
    Creamos una camara
	*/
	smgr->addCameraSceneNode(0, vector3df(0,200,-20), vector3df(0,5,0));
	
    //agregamos modelo a los npcs
	enepece->modelNPC(smgr, driver);
	enepeceh->modelNPC(smgr, driver);
	enepeceh->setPosition(0.0, 0.0, -30.0);

    //agregamos modelo a jugador
	jugador->addPlayerModel(smgr, driver);


}

void Game::loop(){
	while(device->run())
	{
        Game::update();

		driver->beginScene(true, true, SColor(255,200,101,100));

        Game::draw();

		driver->endScene();

    }

}


void Game::update(){

		world->Update();

}


void Game::draw(){
    		/*
		Anything can be drawn between a beginScene() and an endScene()
		call. The beginScene() call clears the screen with a color and
		the depth buffer, if desired. Then we let the Scene Manager and
		the GUI Environment draw their content. With the endScene()
		call everything is presented on the screen.
		*/

		smgr->drawAll();
		guienv->drawAll();

}

void Game::drop(){
    device->drop();
}
Game::~Game(){
	delete world;
	delete reciever;
}