#include <irrlicht.h>
#include "driverChoice.h"
#include <stdio.h>
#include <string.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include "GameObject.h"
#include "TextedGameObject.h"
#include "GameObjectOverworld.h"

#include "Player.h"
//#include "Player.cpp"

#include "World.h"
//#include "Prop.h"
#include "Teleport.h"


#include "NPC.h"



class MyEventReceiver : public IEventReceiver{

	public:

		// This is the one method that we have to implement
		virtual bool OnEvent(const SEvent& event)
		{
			// Remember whether each key is down or up
			if (event.EventType == irr::EET_KEY_INPUT_EVENT)
				KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

			return false;
		}

		// This is used to check whether a key is being held down
		virtual bool IsKeyDown(EKEY_CODE keyCode) const
		{
			return KeyIsDown[keyCode];
		}

		MyEventReceiver()
		{
			for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
				KeyIsDown[i] = false;
		}
	private:
		private:
			// We use this array to store the current state of each key
			bool KeyIsDown[KEY_KEY_CODES_COUNT];
};






int main(){

	NPC enepece("Paco", "Soy un ielico");
	Player jugador = Player();
	printf("HELLO WORLD CON TOMATICO \n");


	// ask user for driver

	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
	if (driverType==video::EDT_COUNT)
		return 1;
	MyEventReceiver receiver;


	//createDevice( deviceType, WindowSize, bits, FullScreen, StencilBuffer, Vsync, Eventreciver)
	IrrlichtDevice* device = createDevice(driverType,
			core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
	if(!device) return -1;

	device->setWindowCaption(L"Hola mundillo");

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	scene::ISceneNode * floor = smgr->addCubeSceneNode(600.0f, 0, 0, core::vector3df(0, -4.0f, 0), core::vector3df(0, 0, 0), core::vector3df(1.0f, 0.000166f, 1.0f));
	if (floor)
	{
		floor->setMaterialTexture(0, driver->getTexture("Materials/cespe.jpg"));
		floor->setMaterialFlag(video::EMF_LIGHTING, false);
	}

	/*
	To be able to look we create a camera looking at 0, 30, -40 from 0,5,0.
	*/
	smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
	
	enepece.modelNPC(smgr, driver);
	jugador.addPlayerModel(smgr, driver);

	/*
	We have done everything, so lets draw it. We also write the current
	frames per second and the name of the driver to the caption of the
	window.
	*/
	int lastFPS = -1;

	// In order to do framerate independent movement, we have to know
	// how long it was since the last frame
	u32 then = device->getTimer()->getTime();

	// This is the movemen speed in units per second.
	const f32 MOVEMENT_SPEED = 10.0f;

	while(device->run())
	{
		// Work out a frame delta time.
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;

		/* Check if keys W, S, A or D are being held down, and move the
		sphere node around respectively. */


		if(receiver.IsKeyDown(irr::KEY_KEY_W))
			jugador.move('Z', 1,  frameDeltaTime);
		else if(receiver.IsKeyDown(irr::KEY_KEY_S))
			jugador.move('Z', -1,  frameDeltaTime);

		else if(receiver.IsKeyDown(irr::KEY_KEY_A))
			jugador.move('X', -1,  frameDeltaTime);
		else if(receiver.IsKeyDown(irr::KEY_KEY_D))
			jugador.move('X', +1,  frameDeltaTime);
		else if(receiver.IsKeyDown(irr::KEY_KEY_Z))
		
			enepece.promptText(guienv);







		/*
		Anything can be drawn between a beginScene() and an endScene()
		call. The beginScene() call clears the screen with a color and
		the depth buffer, if desired. Then we let the Scene Manager and
		the GUI Environment draw their content. With the endScene()
		call everything is presented on the screen.
		*/
		driver->beginScene(true, true, SColor(255,200,101,100));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();

		int fps = driver->getFPS();

		if (lastFPS != fps)
		{
			core::stringw tmp(L"Movement Example - Irrlicht Engine [");
			tmp += driver->getName();
			tmp += L"] fps: ";
			tmp += fps;

			device->setWindowCaption(tmp.c_str());
			lastFPS = fps;
		}



	}

	
	device->drop();
	
	return 0;
}

