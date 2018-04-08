#ifndef __MYGUI_H__
#define __MYGUI_H__



#include <irrlicht.h>
#include <vector> 
#include <string>
#include "World.h"

class Game {
    protected:
        World* world;
        //FightMode* fightmode;
        enum modes {WORLD, FIGHTMODE}; 
        enum modes currentMode = world;
    public:
        game();
        void swap();
        void initDrivers();

}
