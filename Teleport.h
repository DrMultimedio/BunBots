#ifndef __TELEPORT_H__
#define __TELEPORT_H__

#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "World.h"

class Teleport : public GameObjectOverworld{
	private:
        World* worldToTp;
        
    public:
        ChangeWorld();
};

#endif