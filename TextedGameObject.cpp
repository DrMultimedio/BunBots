#include "TextedGameObject.h"


void promptText(gui::IGUIEnvironment* guienv){
        //este metodo imprimira un texto con el formato del juego
        //ahora mismo solo lo saca por consola, pero joer loco habremos de mejorarlo, no?
        std::cout << 1;
        
        std::wstring widestr = std::wstring(TextedGameObject::text.begin(), TextedGameObject::text.end());
        
        std::cout << 2;

        const wchar_t* widecstr = widestr.c_str();
        
        std::cout << 3;

        guienv->addStaticText(widecstr,
        rect<s32>(10,10,300,50), true);

    }