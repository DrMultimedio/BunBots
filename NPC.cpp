#include "NPC.h"

NPC (std::string n, std::string t){
    name = n; 
    text = t;
}
void modelNPC(ISceneManager* smgraux, IVideoDriver* driveraux){
    node = smgraux->addCubeSceneNode(10.0f, 0, 0, core::vector3df(15.0f, 0.0f, 45.0f), core::vector3df(0, 0, 0), core::vector3df(1.0f, 1.0f, 1.0f));
    if (node)
    {
        //node->setPosition(core::vector3df(0,0,30));
        node->setMaterialTexture(0, driveraux->getTexture("Materials/ielo.jpg"));
        node->setMaterialFlag(video::EMF_LIGHTING, false);
    }
}