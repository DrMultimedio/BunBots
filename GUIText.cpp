#include "GUIText.h"
#include <iostream>
#include <sstream>
#include<string>
GUIText::GUIText(irr::gui::IGUIEnvironment* gui){
    guienv = gui;
    skin = guienv->getSkin();
    font = guienv->getFont("./Materials/myfont0.png");
    skin->setFont(font);
    textBox = guienv->addStaticText(L"", irr::core::rect<irr::s32>(750,25,790,60), false, true, 0, -1,false);

}
GUIText::GUIText(irr::gui::IGUIEnvironment* gui, int a, int b, int c, int d ){
    guienv = gui;
    skin = guienv->getSkin();
    font = guienv->addFont("./Materials/myfont0.png", font);
    skin->setFont(font);
    textBox = guienv->addStaticText(L"", irr::core::rect<irr::s32>(a,b,c,d), false, true, 0, -1,false);
}
    //1 colision por segundo y elemento
void GUIText::promptText(std::string text) const{

    //este metodo imprimira un texto con el formato del juego


    std::wstring widestr;
    
    const wchar_t* widecstr;
    skin->setFont(font);
    
    widestr = std::wstring(text.begin(), text.end());
    widecstr = widestr.c_str();
    textBox->setText(widecstr);
    std::cout << text << "\n";
    
}