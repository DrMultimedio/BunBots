
#include <iostream>

 #include "World.h"
//la clase world es una escena fuera de combate, básicamente

//constructor por defecto
World::World(irr::gui::IGUIEnvironment* guienv, MyEventReceiver* r, irr::IrrlichtDevice* d){
    
    receiver = r; 
    device = d;
    then = device->getTimer()->getTime();

}
World::~World(){
	player->getNode()->remove();
    delete player;
	for(int i = 0; i<ladrillos.size(); i++){
		ladrillos[i]->getNode()->remove();
		delete ladrillos[i];
	}
	bola->getNode()->remove();
	delete bola;

}

void World::addLadrillo(Ladrillo* p){
    ladrillos.push_back(p);

}

void World::addBola(Bola* b){
	bola = b;

}
void World::addPlayer(Player* j){
    player = j;

}


void World::Update(){
    now = device->getTimer()->getTime();
    frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
    then = now;
	//check collissions
	if( bola->getNode()->getTransformedBoundingBox().intersectsWithBox(player->getNode()->getTransformedBoundingBox()) )
	{
		bola->crash();
		std::cout<< "COLISION";
	// collision detected
	}
	int ladrilloBorrar = -1;
	//checkeo colisiones con ladrillos
	for(int i = 0; i < ladrillos.size() ; i++){
		if( bola->getNode()->getTransformedBoundingBox().intersectsWithBox(ladrillos[i]->getNode()->getTransformedBoundingBox()) )
		{
			bola->crash();
			ladrilloBorrar = i;
		// collision detected
		}
	}
	if(ladrilloBorrar != -1){
		ladrillos[ladrilloBorrar]->getNode()->remove();

		ladrillos.erase(ladrillos.begin() + ladrilloBorrar);
		ladrilloBorrar = -1;
	}

        //te mueves
		
		/*if(receiver->IsKeyDown(irr::KEY_KEY_W))
			player->move('Z', 1,  frameDeltaTime);
		else if(receiver->IsKeyDown(irr::KEY_KEY_S))
			player->move('Z', -1,  frameDeltaTime);
		*/
		else if(receiver->IsKeyDown(irr::KEY_KEY_A))
			player->move('X', -1,  frameDeltaTime);
		else if(receiver->IsKeyDown(irr::KEY_KEY_D))
			player->move('X', +1,  frameDeltaTime);
		else if(receiver->IsKeyPressed(irr::KEY_KEY_Z))
		{
			std::cout << "pulsado z o algo \n";			
		}
	bola->update();
}
int World::getVidas(){
	return bola->getVidas();
}
void World::faster(){
	bola->faster();
}
bool World::getLoss(){
	return bola->getLoss();
}
bool World::getWin(){
	if(ladrillos.size() == 0)
		return true;
	return false;
}
void World::restart(){
	bola->restart();
}