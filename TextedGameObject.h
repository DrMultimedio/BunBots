#ifndef __TEXTEDGAMEOBJECT_H__
#define __TEXTEDGAMEOBJECT_H__



#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"

class TextedGameObject : public GameObject {

protected: 
        std::string text = "";

		const std::string& getText_p() const { return text; }
		void setText_p(std::string t){ text = std::move(t); }
		void promptText(gui::IGUIEnvironment* guienv);

public: 
	virtual const std::string& getText() const = 0; //metodo const para no cambiar nada de la clase
	virtual const 		  void setText(const std::string& t) = 0;
	virtual const 		  void promptText(gui::IGUIEnvironment* guienv) const = 0;
        

};

#endif