#ifndef __ITEM_H__
#define __ITEM_H__

#include <irrlicht.h>
#include "gameObject.h"

class Item : public Gameobject{
    private:
        std::string name;
        std::string description;
        
    public:

        setName(std::string n){name = n;}
        getName(){return name;}
        setDescription(std::string d){description = d;}
        getDescription(){return description;}

};