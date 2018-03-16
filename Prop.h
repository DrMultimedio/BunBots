#ifndef __PROP_H__
#define __PROP_H__

#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "TextedGameObject.h"

class Prop : public GameObjectOverWorld, public TextedGameObject {
	private:
		std::string name;
    
	public:
        Prop();
        Prop (std::string n, std::string t);

		void addModelProp(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux);
		void addModelProp(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux, irr::core::vector3df position);

		std::string getName() {return name;}
		void setName(std::string n){name = n;}

		const std::string& getText() const override { return getText_p(); };
		const 		  void setText(const std::string& t) override { setText_p(t); };
		const 		  void promptText(irr::gui::IGUIEnvironment* guienv) const override { promptText_p(guienv); };
		



};

#endif