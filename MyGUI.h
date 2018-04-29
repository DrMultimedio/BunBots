#ifndef __MYGUI_H__
#define __MYGUI_H__



#include <irrlicht.h>
#include <vector> 
#include <string>
#include "GameObject.h"

class MyGUI {

    protected: 
        irr::gui::IGUIEnvironment* guienv;

        irr::gui::IGUIStaticText* textBox;
    public:
        MyGUI(irr::gui::IGUIEnvironment* gui);
        MyGUI(irr::gui::IGUIEnvironment* gui, int a, int b, int c, int d );

        MyGUI() = delete;
        void promptText(std::string text) const;


};


#endif