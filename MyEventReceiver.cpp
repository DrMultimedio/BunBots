#include "MyEventReceiver.h"

// This is the one method that we have to implement
bool MyEventReceiver::OnEvent(const irr::SEvent& event)
{
    // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT){
        KeyWasDown[event.KeyInput.Key] = KeyIsDown[event.KeyInput.Key];
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
    return false;
}

// This is used to check whether a key is being held down
bool MyEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

bool MyEventReceiver::IsKeyPressed(irr::EKEY_CODE keyCode) const
{
    if(!KeyWasDown[keyCode] && KeyIsDown[keyCode]){

        return true;
    }
    else{
        return false;
    }

}



MyEventReceiver::MyEventReceiver()
{
    for (int i=0; i<irr::KEY_KEY_CODES_COUNT; ++i){
    
        KeyIsDown[i] = false;
        KeyWasDown[i] = false;
    }
}


