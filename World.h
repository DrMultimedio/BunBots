#ifndef __WORLD_H__
#define __WORLD_H__



#include <irrlicht.h>
#include <vector>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "Player.h"
#include "Bola.h"
#include "Ladrillo.h"
#include "GUIText.h"

#include "MyEventReceiver.h"

class World :public GameObjectOverWorld{
protected:
        irr::gui::IGUIEnvironment* guienv;
        std::vector <Ladrillo*> ladrillos ;
        Player* player;
        Bola* bola;
        GUIText* gui; 
        MyEventReceiver* receiver;
        irr::IrrlichtDevice* device;

        //variables de texto 
        bool loss = false;
        //variables tiempo
        u32 now;
        u32 then;
        f32 stopwatch;
        f32 frameDeltaTime;
        f32 MOVEMENT_SPEED = 10.0f;
public: 
        World(irr::gui::IGUIEnvironment* guienv,  MyEventReceiver* r, irr::IrrlichtDevice* d);
        void loadWorld(); //cargara el mundo
        void addBola(Bola* p); //anyadir prop, devuelve la posicion si todo correcto
        void addLadrillo(Ladrillo* p); //anyadir prop, devuelve la posicion si todo correcto
        void addPlayer(Player* j);  //anyadir tp, devuelve la posicion si todo correcto
        void Update();
        bool getLoss();
        int getVidas();
        void restart();
        ~World();

};


#endif