
#include <iostream>

 #include "World.h"

//constructor por defecto
World::World(){
    //el constructor por defecto pone un plano en el suelo
    
}


int World::addNPC(NPC* n){
    npcs.push_back(n);
}

int World::addProp(Prop* p){
    props.push_back(p);

}

int World::addTeleport(Teleport* t){
    teleports.push_back(t);

}
int World::addPlayer(Player* j){
    player = j;

}

void World::CheckTextPrompt(){
    for(int i = 0; i < npcs.size() ; i++){

        std::cout << "Hola \n" <<  "\n";

        if(abs(player->getPosition().X - npcs.at(i)->getPosition().X) < 20){
            npcs.at(i)->talk(player->getPosition());
    }


    }
}
