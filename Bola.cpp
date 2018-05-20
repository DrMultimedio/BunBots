#include "Bola.h"


void Bola::addModelBola(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux){
    node = smgraux->addSphereSceneNode(5.0f, 16, 0, -1, irr::core::vector3df(0.0f, 0.0f, -50.0f), irr::core::vector3df(0, 0, 0), irr::core::vector3df(1.0f, 1.0f, 1.0f));
    if (node)
    {
        node->setDebugDataVisible( true);
        //node->setPosition(irr::core::vector3df(0,0,30));
        pos.X = 0.0f;
        pos.Y = 0.0f;
        pos.Z = -50.0f;
        node->setMaterialTexture(0, driveraux->getTexture("Materials/bola.jpg"));
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }
}
void Bola::update(){
    speed.X += acceleration.X;
    speed.Z += acceleration.Z;

    pos.X = pos.X + speed.X;
    pos.Z = pos.Z + speed.Z;

    if (abs(pos.X) > 100.0f){
        speed.X = -speed.X;
        acceleration.X = -acceleration.X;
    }
    if (pos.Z > 100.0f){
        speed.Z = -speed.Z;
        acceleration.Z = -acceleration.Z; //sin esta linea hace un efecto gravitatorio :3
    }
    if (pos.Z < -100.0f){
        restart();
    }
    this->node->setPosition(pos);

}
void Bola::faster(){
    acceleration.X += 0.0001f;
    acceleration.Y += 0.001f;

}
void Bola::restart(){
    if(lifes>0){
        pos.X = 0.0f;
        pos.Y = 0.0f;
        pos.Z = -50.0f;
        lifes--;
        std::cout<<"Quedan " << lifes <<" vidas \n";
        
    }
    else{
        loss = true;
    }
}
void Bola::crash(){
    speed.Z = -speed.Z;
    //acceleration.Z = -acceleration.Z; //sin esta linea hace un efecto gravitatorio :3

}
Bola::Bola(){
    speed.X = 0.6f;
    speed.Z = 0.95f;
    acceleration.X = 0.0005f;
    acceleration.Y = 0.005f;
    //acceleration.Z = 0.01f;

}
bool Bola::getLoss(){
    return loss; 
}
int Bola::getVidas(){
    return lifes; 
}