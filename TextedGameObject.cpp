#include "TextedGameObject.h"
#include <iostream>
#include <sstream>

void TextedGameObject::promptText_p(irr::gui::IGUIEnvironment* guienv) const{

    std::cout << "Este metodo  se mantiene por compatibilidad, cuando MyGUI sea totalmente funcional lo borrare \n";



}

//void TextedGameObject::setText_p(std::string t) const{ //quito el const por la funcion push_back, que como no es const pues no va
void TextedGameObject::setText_p(std::string t){

    //este metodo separara el string t por \n para que se pueda leer bien y haya un texto fluido
    //primero esto y luego lo otro
    
    std::istringstream iss(t);
    std::string token;
    while (std::getline(iss, token, '\n'))
    {
        text.push_back(token);
        std::cout << token << std::endl;
    }


}

