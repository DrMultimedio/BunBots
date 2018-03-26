#ifndef __MYGUI_H__
#define __MYGUI_H__



#include <irrlicht.h>
#include <vector> 
#include <string>
#include "GameObject.h"
#include "NPC.h"
#include "MyEventReceiver.h"

class MyGUI {

    protected: 
        irr::gui::IGUIEnvironment* guienv;
        MyEventReceiver* receiver;
    public:
        MyGUI(irr::gui::IGUIEnvironment* gui,  MyEventReceiver* r);
        MyGUI() = default;
        void promptText(NPC* n) const;


};


#endif