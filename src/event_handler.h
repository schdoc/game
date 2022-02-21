/**
 * @defgroup   EVENT event_handler
 *
 * @brief      Event handler from which the App class inherits for easier code
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include <SDL.h>

class EventHandler{
	public:
		EventHandler();
		virtual ~EventHandler();
		virtual void event(SDL_Event* event);
		virtual void focus_gained(Uint32 id);
		virtual void focus_lost(Uint32 id);
		virtual void maximized(Uint32 id);
		virtual void restored(Uint32 id);
		virtual void keyup(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod);
		virtual void keydown(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod);
		virtual void mouse_motion(int x, int y, int xR, int yR, bool m1, bool m2, bool m3);
		virtual void mouse_buttonUp(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse_buttonDown(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse1_buttonUp(Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse1_buttonDown(Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse2_buttonUp(Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse2_buttonDown(Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse3_buttonUp(Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse3_buttonDown(Uint8 clicks, Sint32 xrel, Sint32 yrel);
		virtual void mouse_wheel(int x, int y, Uint32 direction);
		virtual void joy_axisMotion(SDL_JoystickID id, Uint8 axis, Sint16 value);
		virtual void joy_ballMotion(SDL_JoystickID id, Uint8 ball, Sint16 xrel, Sint16 yrel);
		virtual void joy_hatMotion(SDL_JoystickID id, Uint8 hat, Uint8 value);
		virtual void joy_buttonUp(SDL_JoystickID id, Uint8 btn, Uint8 state);
		virtual void joy_buttonDown(SDL_JoystickID id, Uint8 btn, Uint8 state);
		virtual void syswmevent(SDL_SysWMmsg* msg);
		virtual void window(Uint32 id, Uint8 event, Sint32 data1, Sint32 data2);
		virtual void quit();
		virtual void user(Sint32 code, void* data1, void* data2);
};

#endif
