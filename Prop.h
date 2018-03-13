#ifndef __PROP_H__
#define __PROP_H__

#include <irrlicht.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "TextedGameObject.h"
#include "TextedGameObject.cpp"

class Prop : public GameObjectOverWorld, public TextedGameObject {
	private:
		std::string name;
    public:
        NPC();
        NPC (std::string n, std::string t);
		void modelNPC(scene::ISceneManager* smgraux, video::IVideoDriver* driveraux);

		std::string getName() {return name;}
		void setName(std::string n){name = n;}

		const std::string& getText() const override { return getText_p(); };
		const 		  void setText(const std::string& t) override { setText_p(t); };
		const 		  void promptText(IGUIEnvironment* guienv) const override { promptText(guienv); };



};

#endif