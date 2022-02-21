/**
 * @defgroup   EVENT event_handler
 *
 * @brief      Event handler from which the App class inherits for easier code
 *
 * @author     schdoc
 * @date       2022
 */

#include "event_handler.h"

EventHandler::EventHandler(){

}

EventHandler::~EventHandler(){

}

void EventHandler::event(SDL_Event* event){
	switch(event->type){
		case SDL_KEYUP:
			keyup(event->key.keysym.scancode, event->key.keysym.sym, event->key.keysym.mod);
			break;
		case SDL_KEYDOWN:
			keyup(event->key.keysym.scancode, event->key.keysym.sym, event->key.keysym.mod);
			break;
		case SDL_MOUSEMOTION:
			mouse_motion(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel, (event->motion.state&SDL_BUTTON_LMASK)!=0, (event->motion.state&SDL_BUTTON_RMASK)!=0, (event->motion.state&SDL_BUTTON_MMASK)!=0);
			break;
		case SDL_MOUSEBUTTONDOWN:
			mouse_buttonDown(event->button.button, event->button.clicks, event->button.x, event->button.y);
			switch(event->button.button){
				case SDL_BUTTON_LEFT:
					mouse1_buttonDown(event->button.clicks, event->button.x, event->button.y);
					break;
				case SDL_BUTTON_MIDDLE:
					mouse2_buttonDown(event->button.clicks, event->button.x, event->button.y);
					break;
				case SDL_BUTTON_RIGHT:
					mouse3_buttonDown(event->button.clicks, event->button.x, event->button.y);
					break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			mouse_buttonUp(event->button.button, event->button.clicks, event->button.x, event->button.y);
			switch(event->button.button){
				case SDL_BUTTON_LEFT:
					mouse1_buttonUp(event->button.clicks, event->button.x, event->button.y);
					break;
				case SDL_BUTTON_MIDDLE:
					mouse2_buttonUp(event->button.clicks, event->button.x, event->button.y);
					break;
				case SDL_BUTTON_RIGHT:
					mouse3_buttonUp(event->button.clicks, event->button.x, event->button.y);
					break;
			}
			break;
		case SDL_MOUSEWHEEL:
			mouse_wheel(event->wheel.x, event->wheel.y, event->wheel.direction);
			break;
		case SDL_JOYAXISMOTION:
			joy_axisMotion(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
			break;
		case SDL_JOYBALLMOTION:
			joy_ballMotion(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
			break;
		case SDL_JOYHATMOTION:
			joy_hatMotion(event->jhat.which, event->jhat.hat, event->jhat.value);
			break;
		case SDL_JOYBUTTONDOWN:
			joy_buttonDown(event->jbutton.which, event->jbutton.button, event->jbutton.state);
			break;
		case SDL_JOYBUTTONUP:
			joy_buttonUp(event->jbutton.which, event->jbutton.button, event->jbutton.state);
			break;
		case SDL_SYSWMEVENT:
			syswmevent(event->syswm.msg);
			break;
		case SDL_WINDOWEVENT:
			window(event->window.windowID, event->window.event, event->window.data1, event->window.data2);
			switch(event->window.event){
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					focus_gained(event->window.windowID);
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					focus_lost(event->window.windowID);
					break;
				case SDL_WINDOWEVENT_MAXIMIZED:
					maximized(event->window.windowID);
					break;
				case SDL_WINDOWEVENT_MINIMIZED:
					restored(event->window.windowID);
					break;
			}
			break;
		case SDL_QUIT:
			quit();
			break;
		case SDL_USEREVENT:
			user(event->user.code, event->user.data1, event->user.data2);
			break;
		default:
			break;
	}
}

void EventHandler::focus_gained(Uint32 id){
	// you caneu override this
}

void EventHandler::focus_lost(Uint32 id){
	// you caneu override this
}

void EventHandler::maximized(Uint32 id){
	// you caneu override this
}

void EventHandler::restored(Uint32 id){
	// you caneu override this
}

void EventHandler::keyup(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod){
	// you caneu override this
}

void EventHandler::keydown(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod){
	// you caneu override this
}

void EventHandler::mouse_motion(int x, int y, int xR, int yR, bool m1, bool m2, bool m3){
	// you caneu override this
}

void EventHandler::mouse_buttonUp(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse_buttonDown(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse1_buttonUp(Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse1_buttonDown(Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse2_buttonUp(Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse2_buttonDown(Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse3_buttonUp(Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse3_buttonDown(Uint8 clicks, Sint32 xrel, Sint32 yrel){
	// you caneu override this
}

void EventHandler::mouse_wheel(int x, int y, Uint32 direction){
	// you caneu override this
}

void EventHandler::joy_axisMotion(SDL_JoystickID id, Uint8 axis, Sint16 value){
	// you caneu override this
}

void EventHandler::joy_ballMotion(SDL_JoystickID id, Uint8 ball, Sint16 xrel, Sint16 yrel){
	// you caneu override this
}

void EventHandler::joy_hatMotion(SDL_JoystickID id, Uint8 hat, Uint8 value){
	// you caneu override this
}

void EventHandler::joy_buttonUp(SDL_JoystickID id, Uint8 btn, Uint8 state){
	// you caneu override this
}

void EventHandler::joy_buttonDown(SDL_JoystickID id, Uint8 btn, Uint8 state){
	// you caneu override this
}

void EventHandler::syswmevent(SDL_SysWMmsg* msg){
	// you caneu override this
}

void EventHandler::window(Uint32 id, Uint8 event, Sint32 data1, Sint32 data2){
	// you caneu override this
}

void EventHandler::quit(){
	// you caneu override this
}

void EventHandler::user(Sint32 code, void* data1, void* data2){
	// you caneu override this
}
