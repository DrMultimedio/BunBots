#include "MyGUI.h"
#include <iostream>
#include <sstream>
#include<string>
MyGUI::MyGUI(irr::gui::IGUIEnvironment* gui){
    guienv = gui;
    textBox = guienv->addStaticText(L"", irr::core::rect<irr::s32>(750,25,790,60), false, true, 0, -1,false);

}
MyGUI::MyGUI(irr::gui::IGUIEnvironment* gui, int a, int b, int c, int d ){
    guienv = gui;
    textBox = guienv->addStaticText(L"", irr::core::rect<irr::s32>(a,b,c,d), false, true, 0, -1,false);

}

void MyGUI::promptText(std::string text) const{

    //este metodo imprimira un texto con el formato del juego


    std::wstring widestr;
    
    const wchar_t* widecstr;

    int l = 0;
    bool pressed = true; //bool para ver si pulsas un botón
    
    widestr = std::wstring(text.begin(), text.end());
    widecstr = widestr.c_str();
    textBox->setText(widecstr);
    std::cout << text << "\n";
    
}