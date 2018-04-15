#include "Bola.h"


void Bola::addModelBola(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux){
    node = smgraux->addSphereSceneNode(5.0f, 16, 0, 0, irr::core::vector3df(0.0f, 0.0f, -50.0f), irr::core::vector3df(0, 0, 0), irr::core::vector3df(1.0f, 1.0f, 1.0f));
    if (node)
    {
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
    if (abs(pos.Z) > 100.0f){
        speed.Z = -speed.Z;
        acceleration.Z = -acceleration.Z; //sin esta linea hace un efecto gravitatorio :3

    }

    this->node->setPosition(pos);

}
Bola::Bola(){
    speed.X = 0.6f;
    speed.Z = 0.95f;
    acceleration.X = 0.001f;
    acceleration.Y = 0.001f;

}