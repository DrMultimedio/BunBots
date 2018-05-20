#include "GUIimg.h"
#include <iostream>
#include <sstream>
#include<string>
GUIimg::GUIimg(irr::gui::IGUIEnvironment* gui,irr::video::IVideoDriver* driver, irr::io::path path){
    guienv = gui;
    img = guienv->addImage(driver->getTexture(path), irr::core::position2di(730,25),true, 0, -1, 0);
    driveraux = driver;
}
GUIimg::GUIimg(irr::gui::IGUIEnvironment* gui, irr::video::IVideoDriver* driver, int a, int b, int c, int d){
    guienv = gui;
    img = guienv->addImage(irr::core::rect<irr::s32>(a,b,c,d), 0, -1, 0, true);
    driveraux = driver;
}
void GUIimg::promptImage(irr::io::path path){

    //este metodo imprimira un texto con el formato del juego
    img->setImage(driveraux->getTexture(path));
    
}
