
#include <iostream>

 #include "World.h"
//la clase world es una escena fuera de combate, básicamente

//constructor por defecto
World::World(irr::gui::IGUIEnvironment* guienv, MyEventReceiver* r, irr::IrrlichtDevice* d){
    
    gui = new MyGUI(guienv );
    receiver = r; 
    device = d;
    then = device->getTimer()->getTime();
    talkingNPC = nullptr;

}
World::~World(){
    delete gui;
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

void World::checkTextNPC(){
    for(int i = 0; i < npcs.size() ; i++){


        if( (abs(player->getPosition().X - npcs.at(i)->getPosition().X)<20)
           &&
           (abs(player->getPosition().Z - npcs.at(i)->getPosition().Z) <20 ))  {
            //npcs[i]->talk(guienv); //Cambiar at(i) por [i]

            gui->promptText(npcs[i]->getText()[0]);
            talkingNPC = npcs[i];
            textMode = true;
            actualLine = 1; 
        }


    }
}

void World::Update(){
    /*este metodo va a checkiar si hay un npc hablando, y si lo esta, pues si le dan a la z sigue hablando hasta 
    que termina de hablar */
    now = device->getTimer()->getTime();
    frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
    then = now;

    if(textMode){
        //modo lectura
        if(talkingNPC != nullptr) {
            if(receiver->IsKeyPressed(irr::KEY_KEY_Z) ){
                gui->promptText(talkingNPC->getText()[actualLine]);
                actualLine++;
                if(actualLine >= talkingNPC->getText().size() ){
                    textMode = false;
                    actualLine = 0;
                    talkingNPC = nullptr;
                    gui->promptText("");

                }
            }
        }
        else{
            textMode = false;
            actualLine = 0;
            talkingNPC = nullptr;

        }
    }
    else{
        //te mueves
		
		if(receiver->IsKeyDown(irr::KEY_KEY_W))
			player->move('Z', 1,  frameDeltaTime);
		else if(receiver->IsKeyDown(irr::KEY_KEY_S))
			player->move('Z', -1,  frameDeltaTime);

		else if(receiver->IsKeyDown(irr::KEY_KEY_A))
			player->move('X', -1,  frameDeltaTime);
		else if(receiver->IsKeyDown(irr::KEY_KEY_D))
			player->move('X', +1,  frameDeltaTime);
		else if(receiver->IsKeyPressed(irr::KEY_KEY_Z))
		{
			std::cout << "pulsado z o algo \n";
			this->checkTextNPC();
			
			//enepece.talk(jugador.getPosition());
			//enepece.promptText(guienv);
		}
    }
}