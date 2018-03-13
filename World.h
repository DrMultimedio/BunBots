#ifndef __WORLD_H__
#define __WORLD_H__



#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "Teleport.h"

//#include "NPC.h"
//#include "Prop.h"

class World :public GameObjectOverWorld{
        protected:
                //la clase world tendra un array de NPCs, Props, y Teleports
                //NPC npcs[3] ;
                //Prop props[3] ;
                Teleport teleports[3];
        public: 
                void loadWorld(); //cargara el mundo



};


#endif