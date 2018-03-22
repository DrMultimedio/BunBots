#ifndef __MYGUI_H__
#define __MYGUI_H__



#include <irrlicht.h>
#include <vector> 
#include <string>
#include "GameObject.h"
#include "NPC.h"
class MyGUI {
    protected: 
        irr::gui::IGUIEnvironment* guienv;
        
    public:
        MyGUI(irr::gui::IGUIEnvironment* gui);
        
        void promptText(NPC* n) const;


};


#endif