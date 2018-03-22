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
#include "MyGUI.h"

class World :public GameObjectOverWorld{
protected:
        //la clase world tendra un array de NPCs, Props, y Teleports
        irr::gui::IGUIEnvironment* guienv;
        std::vector <NPC*> npcs ;
        std::vector <Prop*> props ;
        std::vector <Teleport*> teleports;
        Player* player;
        irr::core::vector3df newPlayerPosition; //posicion del jugador al entrar al mundo
        MyGUI gui = NULL;;
public: 
        World(irr::gui::IGUIEnvironment* guienv);

        void loadWorld(); //cargara el mundo
        void  addNPC(NPC* n); //anyadir NPC, devuelve la posicion si todo correcto
        void  addProp(Prop* p); //anyadir prop, devuelve la posicion si todo correcto
        void  addTeleport(Teleport* t); //anyadir tp, devuelve la posicion si todo correcto
        void  addPlayer(Player* j);  //anyadir tp, devuelve la posicion si todo correcto
        void  createNPC(std::string name, std::string Text, int shape);
        void CheckTextPrompt();

};


#endif