
#include <iostream>

 #include "World.h"

//constructor por defecto
World::World(irr::gui::IGUIEnvironment* guienv, MyEventReceiver* r){
    
    gui = MyGUI(guienv,r );
    receiver = r; 
}


void World::addNPC(NPC* n){
    npcs.push_back(n);
    
}

void World::addProp(Prop* p){
    props.push_back(p);

}

void World::addTeleport(Teleport* t){
    teleports.push_back(t);

}
void World::addPlayer(Player* j){
    player = j;

}

void World::CheckTextPrompt(){
    for(int i = 0; i < npcs.size() ; i++){


        if(abs(player->getPosition().X - npcs.at(i)->getPosition().X)< 20 && abs(player->getPosition().Y - npcs.at(i)->getPosition().Y) < 20 ) {
            //npcs[i]->talk(guienv); //Cambiar at(i) por [i]
            gui.promptText(npcs[i]);
    }


    }
}
