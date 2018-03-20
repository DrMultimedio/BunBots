
#include <iostream>

 #include "World.h"

//constructor por defecto
World::World(){
    //el constructor por defecto pone un plano en el suelo
    
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

void World::CheckTextPrompt(irr::gui::IGUIEnvironment* guienv){
    for(int i = 0; i < npcs.size() ; i++){

        std::cout << "Hola \n" <<  "\n";

        if(abs(player->getPosition().X - npcs.at(i)->getPosition().X) < 20){
            npcs.at(i)->talk(guienv); //Cambiar at(i) por [i]
    }


    }
}
