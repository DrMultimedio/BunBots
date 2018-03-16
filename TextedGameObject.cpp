#include "TextedGameObject.h"
#include <iostream>
#include <sstream>

void TextedGameObject::promptText_p(irr::gui::IGUIEnvironment* guienv) const{
        //este metodo imprimira un texto con el formato del juego


        std::wstring widestr = std::wstring(text.at(0).begin(), text.at(0).end());
        
        const wchar_t* widecstr = widestr.c_str();
        
        guienv->addStaticText(widecstr,
        irr::core::rect<irr::s32>(10,10,300,50), true);

        //pseudocodigo de lo que deberia hacer
        //while quede texto sin mostrar 
        //(texto = t, t tiene l lineas, cada vez que pulse el boton y aparezca una linea nueva aumentara i. Cuando i sea mayor que z se sale del bucle)
        //esperar boton
        


}

//void TextedGameObject::setText_p(std::string t) const{ //quito el const por la funcion push_back, que como no es const pues no va
void TextedGameObject::setText_p(std::string t) const{

    //este metodo separara el string t por \n para que se pueda leer bien y haya un texto fluido
    //primero esto y luego lo otro
    
    std::istringstream iss(t);
    std::string token;
    while (std::getline(iss, token, '\n'))
    {
        //text.push_back(token);
        std::cout << token << std::endl;
    }


}

