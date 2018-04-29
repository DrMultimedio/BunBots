#ifndef __BOLA_H__
#define __BOLA_H__

#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "TextedGameObject.h"
#include <iostream>
class Bola : public GameObjectOverWorld {
	private:
		std::string name;
		irr::core::vector3df pos;
		irr::core::vector3df speed;
		irr::core::vector3df acceleration;
		bool loss = false;
		int lifes = 3; 
	public:
        Bola();
        Bola (std::string n, std::string t);
		int getVidas(); 
		void addModelBola(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux);
		void addModelBola(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux, irr::core::vector3df position);
		void update();
		void crash();
		bool getLoss();
		void restart();
};

#endif