#include "TextedGameObject.h"
#include <iostream>

void TextedGameObject::promptText_p(irr::gui::IGUIEnvironment* guienv) const{
        //este metodo imprimira un texto con el formato del juego
        std::cout << 1;
        
        std::wstring widestr = std::wstring(text.begin(), text.end());
        
        std::cout << 2;

        const wchar_t* widecstr = widestr.c_str();
        
        std::cout << 3;

        guienv->addStaticText(widecstr,
        irr::core::rect<irr::s32>(10,10,300,50), true);

    }