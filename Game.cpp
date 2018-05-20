#include "Game.h"
#include "driverChoice.h"
Game::Game()
{

	// ask user for driver
    //definimos receiver 
    receiver = new MyEventReceiver;    
    //inicializamos el dispositivo
	this->device = createDevice(video::EDT_OPENGL,
	core::dimension2d<u32>(800, 600), 16, false, false, false, receiver);
    device->setWindowCaption(L"BunBots, el videojuego");

    //definimos driver, escenas y gui 

    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();

    //agregamos objetos
    textoVidas = new GUIimg(guienv, driver, "Materials/3.png");
	lostText = new GUIimg(guienv,driver, 0 , 0 , 800, 600);
	world = new World(guienv, receiver, device);

	Player* jugador = new Player();
	jugador->addPlayerModel(smgr, driver);

	world->addPlayer(jugador);
	printf("HELLO WORLD CON TOMATICO \n");

    //esto deberia ser un prop
	scene::ISceneNode * floor = smgr->addCubeSceneNode(600.0f, 0, 0, core::vector3df(0, -4.0f, 0), core::vector3df(0, 0, 0), core::vector3df(1.0f, 0.000166f, 1.0f));
	if (floor)
	{
		floor->setMaterialTexture(0, driver->getTexture("Materials/cespe2.jpg"));
		floor->setMaterialFlag(video::EMF_LIGHTING, false);
	}

	/*
	To be able to look we create a camera looking at 0, 30, -40 from 0,5,0.
    Creamos una camara
	*/
	smgr->addCameraSceneNode(0, vector3df(0,150,-20), vector3df(0,0,0));
	

    //agregamos modelo a jugador
	int initialOffset = 40;
	bricks = 12;
	for(int i = 0; i < bricks ; i++){
		int row = i/rowQuantity; 
		int offset = i%rowQuantity;
		irr::core::vector3df pos((offset*22.0f+initialOffset)-150, 0.0f, 80.0f - row * 22 );
		Ladrillo* ladrillo = new Ladrillo();
		ladrillo->addModelLadrillo(smgr, driver, pos);
		world->addLadrillo(ladrillo);
	}
	Bola* bola = new Bola();
	bola->addModelBola(smgr, driver);
	world->addBola(bola);

}
void Game::restart(){
	std::cout<<"Reiniciando juego...\n";
	std::cout<<"Borrando mundo...\n";
	delete world;
	world = nullptr;
	std::cout<<"Creando nuevo mundo...\n";
	world = new World(guienv, receiver, device);
	std::cout<<"Creando nuevo jugador...\n";
	Player* jugador = new Player();
	jugador->addPlayerModel(smgr, driver);
	std::cout<<"Añadiendo jugador a mundo...\n";
	world->addPlayer(jugador);
	std::cout<<"Creando ladrillos y añadiendolos al mundo...\n";
	int initialOffset = 40;
	for(int i = 0; i < bricks ; i++){
		int row = i/rowQuantity; 
		int offset = i%rowQuantity;
		irr::core::vector3df pos((offset*22.0f+initialOffset)-150, 0.0f, 80.0f - row * 22 );
		Ladrillo* ladrillo = new Ladrillo();
		ladrillo->addModelLadrillo(smgr, driver, pos);
		world->addLadrillo(ladrillo);
	}
	std::cout<<"Creando bola y añadiendola al mundo...\n";
	Bola* bola = new Bola();
	bola->addModelBola(smgr, driver);
	world->addBola(bola);
}
void Game::loop(){
	while(device->run())
	{
		//TODO: Pintar las vidas
		driver->beginScene(true, true, SColor(255,200,101,100));

        Game::update();

        Game::draw();

		driver->endScene();

    }
}
void Game::update(){
	if(started){
		if(!world->getLoss()&&!world->getWin()){
			world->Update();
			int vidas = world->getVidas();
			switch (vidas) {
				case 0:
					textoVidas->promptImage("Materials/0.png");
					break;
				case 1:
					textoVidas->promptImage("Materials/1.png");
					break;
				case 2:
					textoVidas->promptImage("Materials/2.png");
					break;
				case 3:
					textoVidas->promptImage("Materials/3.png");
					break;

			}
			//textoVidas->promptImage(std::to_string(vidas));
		}
		else{
			bool brestart = false;
			if(world->getLoss()){
				lostText->promptImage ("Materials/perdido.png");
				if(receiver->IsKeyDown(irr::KEY_KEY_Z)){
					lostText->promptImage ("Materials/nada.png");
					brestart = true;
				}
			}
			else if(world->getWin()){
				lostText->promptImage ("Materials/ganador.png");
				if(receiver->IsKeyDown(irr::KEY_KEY_Z)){
					bricks+=10;
					world->faster();
					lostText->promptImage ("Materials/nada.png");
					brestart = true;
				}
			}
			if(brestart){
			restart();	
			}		
		}
		
	}
		else{
			lostText->promptImage ("Materials/empezar.png");
			if(receiver->IsKeyDown(irr::KEY_KEY_Z)){
				started = true;
				lostText->promptImage ("Materials/nada.png");
			}
		}
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
	delete receiver;
    delete textoVidas;
}