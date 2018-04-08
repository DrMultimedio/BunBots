#ifndef __MYEVENTRECEIVER_H__
#define __MYEVENTRECEIVER_H__



#include <irrlicht.h>

class MyEventReceiver : public irr::IEventReceiver{
	private:
		private:
			// We use this array to store the current state of each key
			bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
			bool KeyWasDown[irr::KEY_KEY_CODES_COUNT];

	public:

		// This is the one method that we have to implement
		virtual bool OnEvent(const irr::SEvent& event);

		// This is used to check whether a key is being held down
		virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
		virtual bool IsKeyPressed(irr::EKEY_CODE keyCode) const;

		MyEventReceiver();
        

};

#endif