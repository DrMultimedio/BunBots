#ifndef __GUIText_H__
#define __GUIText_H__



#include <irrlicht.h>
#include <vector> 
#include <string>
#include "GameObject.h"

class GUIText {

    protected: 
        irr::gui::IGUIEnvironment* guienv;
        irr::gui::IGUIFont* font = 0;
        irr::gui::IGUIStaticText* textBox;
        irr::gui::IGUISkin* skin;
    public:
        GUIText(irr::gui::IGUIEnvironment* gui);
        GUIText(irr::gui::IGUIEnvironment* gui, int a, int b, int c, int d );

        GUIText() = delete;
        void promptText(std::string text) const;


};


#endif