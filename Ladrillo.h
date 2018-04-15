#ifndef __LADRILLO_H__
#define __LADRILLO_H__

#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "TextedGameObject.h"

class Ladrillo : public GameObjectOverWorld {
	private:
		std::string name;
    
	public:
        Ladrillo();
        Ladrillo (std::string n, std::string t);

		void addModelLadrillo(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux);
		void addModelLadrillo(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux, irr::core::vector3df position);


};

#endif