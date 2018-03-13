	#ifndef __PLAYER_H__
	#define __PLAYER_H__

	#include <irrlicht.h>
	#include <stdio.h>
	#include "GameObject.h"
	#include "GameObjectOverworld.h"

	using namespace irr;
	using namespace core;
	using namespace scene;
	using namespace video;
	using namespace io;
	using namespace gui;

	class Player : public GameObjectOverWorld{
		protected: 
			
			std::string name =""; 
			float speed = 15.0f; 
		public:
			Player() = default;
			void addPlayerModel(ISceneManager* smgraux, IVideoDriver* driveraux);
			void move (char axis, int direction, float frameDeltaTime);
	};
	#endif