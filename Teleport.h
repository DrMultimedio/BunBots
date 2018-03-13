#ifndef __TELEPORT_H__
#define __TELEPORT_H__

#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"

//#include "Prop.h"

class World;

class Teleport : public GameObjectOverWorld{
    //la clase teleport servira para cambiar de mapa, de forma que podremos usarla para hacer puertas, caminos 
    //a otros mapas, entre otros. 
	private:
        World* worldToTp = nullptr; //el mundo al que llevara el tp
        core::vector3df newPlayerPosition; //posicion del jugador despues de haber sido teleportado
        //Prop door;
    public:
        Teleport() = default;
        void ChangeWorld();
};

#endif