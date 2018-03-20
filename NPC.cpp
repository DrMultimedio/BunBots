#include "NPC.h"
#include <iostream>

NPC::NPC (std::string n, std::string t){
    name = n; 
    this->setText(t);

}
void NPC::modelNPC(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux){
    node = smgraux->addCubeSceneNode(10.0f, 0, 0, irr::core::vector3df(15.0f, 0.0f, 45.0f), irr::core::vector3df(0, 0, 0), irr::core::vector3df(1.0f, 1.0f, 1.0f));
    if (node)
    {
        //node->setPosition(irr::core::vector3df(0,0,30));
        node->setMaterialTexture(0, driveraux->getTexture("Materials/ielo.jpg"));
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }
}
void NPC::talk(irr::gui::IGUIEnvironment* guienv){
    //esta funcion existe por si el npc decide darte un objeto, abrir una puerta o similar. 
    //solo que no está implementado aún 
    this->promptText(guienv);
}
void NPC::setPosition(int x, int y, int z){
    node->setPosition(irr::core::vector3df(x,y,z)); //esta linea da segmentation fault, ni ide de por que
}