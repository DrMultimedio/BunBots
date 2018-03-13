	#ifndef __GAMEOBJECTOVERWORLD_H__
	#define __GAMEOBJECTOVERWORLD_H__


	#include <irrlicht.h>
	#include <stdio.h>
	#include "GameObject.h"


	class GameObjectOverWorld : public GameObject{
		//un gameobject de overworld es una especificación del gameobject para cuando estemos fuera de batalla, es decir, en el overworld 
		protected:
			irr::scene::ISceneNode* node = nullptr; //esta variable deberia ser compartida con todos los hijos, pero dice
			//que está protected. Preguntar martes
		
		public: 
		
			GameObjectOverWorld() {}
			irr::core::vector3df getPosition(){return node->getPosition();}

	};

	#endif