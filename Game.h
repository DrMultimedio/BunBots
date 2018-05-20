#ifndef __GAME_H__
#define __GAME_H__



#include <irrlicht.h>
#include <vector> 
#include <string>
#include "GameObject.h"
#include "TextedGameObject.h"
#include "GameObjectOverworld.h"
#include "Player.h"
#include "World.h"
#include "Bola.h"
#include "GUIimg.h"



class Game {
    protected:
	    const f32 MOVEMENT_SPEED = 10.0f;
        World* world = nullptr;
        //FightMode* fightmode;
        int bricks = 25;
        int rowQuantity = 11; 
        IrrlichtDevice* device;
        IVideoDriver* driver;
	    ISceneManager* smgr;
	    IGUIEnvironment* guienv;
        MyEventReceiver* receiver; 
        GUIimg* lostText;
        GUIimg* textoVidas;
        bool started = false;
        int lifes = 3;
    public: 
        Game();
        void swap();
        void draw();
        void update();
        void loop();
        void drop();
        void restart();
        ~Game();
};

#endif