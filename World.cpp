 #include "World.h"

//constructor por defecto
World::World(){
    //el constructor por defecto pone un plano en el suelo
    
}


int World::addNPC(NPC n){
    npcs.push_back(n);
}

int World::addProp(Prop p){
    props.push_back(p);

}

int World::addTeleport(Teleport t){
    teleports.push_back(t);

}
