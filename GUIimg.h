#ifndef __GUIIMG_H__
#define __GUIIMG_H__



#include <irrlicht.h>
#include <vector> 
#include <string>
#include "GameObject.h"

class GUIimg {

    protected: 
        irr::gui::IGUIImage* img; 
        irr::gui::IGUIEnvironment* guienv;
        irr::video::ITexture* tex;
        irr::video::IVideoDriver* driveraux;

    public:
        GUIimg(irr::gui::IGUIEnvironment* gui,irr::video::IVideoDriver* driveraux, irr::io::path path);
        GUIimg(irr::gui::IGUIEnvironment* gui,irr::video::IVideoDriver* driveraux, int a, int b, int c, int d);
        void promptImage(irr::io::path path);
        GUIimg() = delete;


};


#endif