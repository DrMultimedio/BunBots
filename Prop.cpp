#include "Prop.h"


void Prop::addModelProp(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux){
    node = smgraux->addCubeSceneNode(10.0f, 0, 0, irr::core::vector3df(15.0f, 0.0f, 45.0f), irr::core::vector3df(0, 0, 0), irr::core::vector3df(1.0f, 1.0f, 1.0f));
    if (node)
    {
        //node->setPosition(irr::core::vector3df(0,0,30));
        node->setMaterialTexture(0, driveraux->getTexture("Materials/ielo.jpg"));
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }
}
void Prop::addModelProp(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux, irr::core::vector3df position){
    node = smgraux->addCubeSceneNode(10.0f, 0, 0, position, irr::core::vector3df(0, 0, 0), irr::core::vector3df(1.0f, 1.0f, 1.0f));
    if (node)
    {
        //node->setPosition(irr::core::vector3df(0,0,30));
        node->setMaterialTexture(0, driveraux->getTexture("Materials/ielo.jpg"));
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }
}