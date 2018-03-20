#ifndef __WORLD_H__
#define __WORLD_H__



#include <irrlicht.h>
#include <vector>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "Teleport.h"
#include "Player.h"

#include "NPC.h"
#include "Prop.h"


class World :public GameObjectOverWorld{
        protected:
                //la clase world tendra un array de NPCs, Props, y Teleports
                std::vector <NPC*> npcs ;
                std::vector <Prop*> props ;
                std::vector <Teleport*> teleports;
                Player* player;
                irr::core::vector3df newPlayerPosition; //posicion del jugador al entrar al mundo
        public: 
                World();

                void loadWorld(); //cargara el mundo
                int  addNPC(NPC* n); //anyadir NPC, devuelve la posicion si todo correcto
                int  addProp(Prop* p); //anyadir prop, devuelve la posicion si todo correcto
                int  addTeleport(Teleport* t); //anyadir tp, devuelve la posicion si todo correcto
                int  addPlayer(Player* j);  //anyadir tp, devuelve la posicion si todo correcto
                int  createNPC(std::string name, std::string Text, int shape);
                void CheckTextPrompt();

};


#endif