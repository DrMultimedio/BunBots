#ifndef __WORLD_H__
#define __WORLD_H__

#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "NPC.h"
#include "Prop.h"
#include "Teleport.h"

class World :public GameObjectOverworld{
        protected:
                //la clase world tendra un array de NPCs, Props, y Teleports
                NPC[] npcs;
                Prop[] props;
                Teleport[] teleports;
        public: 
                void loadWorld(); //cargara el mundo



};


#endif