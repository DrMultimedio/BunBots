#ifndef __NPC_H__
#define __NPC_H__

#include <irrlicht.h>
#include "GameObject.h"
#include "GameObjectOverworld.h"
#include "TextedGameObject.h"



class NPC : public GameObjectOverWorld, public TextedGameObject {
	private:
		std::string name;
    public:
        NPC();
        NPC (std::string n, std::string t);
		
		void modelNPC(irr::scene::ISceneManager* smgraux, irr::video::IVideoDriver* driveraux);
		void talk(irr::gui::IGUIEnvironment* guienv);

		std::string getName() {return name;}

		void setName(std::string n){name = n;}
		irr::core::vector3df getPosition(){return node->getPosition();};
		void setPosition(int x, int y, int z);
		const std::vector<std::string>& getText() const override { return getText_p(); };
		void setText(const std::string& t) override { setText_p(t); };
	    void promptText(irr::gui::IGUIEnvironment* guienv) const override { promptText_p(guienv); };



};

#endif