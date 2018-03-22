#include "MyGUI.h"
#include <iostream>
#include <sstream>

MyGUI::MyGUI(irr::gui::IGUIEnvironment* gui){
    guienv = gui;
}

void MyGUI::promptText(NPC* n) const{

    //este metodo imprimira un texto con el formato del juego

    std::vector<std::string> text = n->getText();

    std::wstring widestr = std::wstring(text.at(0).begin(), text.at(0).end());
    
    const wchar_t* widecstr = widestr.c_str();

    guienv->addStaticText(widecstr, irr::core::rect<irr::s32>(10,10,300,50), true);

    //pseudocodigo de lo que deberia hacer
    //while quede texto sin mostrar 
    //(texto = t, t tiene l lineas, cada vez que pulse el boton y aparezca una linea nueva aumentara i. Cuando i sea mayor que z se sale del bucle)
    //esperar boton
    for(int i = 0; i < text.size() ; i++){
        std::cout << text[i] << "\n";
    }

}