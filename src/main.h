/**
 * @defgroup   MAIN main
 *
 * @brief      Header for app
 *
 * @author     schdoc
 * @date       2022
 */

#define SDL_MAIN_HANDLED
#ifndef _MAIN_H_
#define _MAIN_H_


#include <SDL.h>
#include "constants.h"
#include "event_handler.h"
#include "texture.h"
#include "anim.h"
#include "entity.h"
#include "map.h"
#include "player.h"
#include "text.h"

class App: public EventHandler{
	private:
		bool RUNNING;
		bool FULLSCREEN;
		SDL_Window* window;
		Player cheesedude;
		SDL_Renderer* renderer;
		Text text;
		Animator cheesedude_anim;
	public:
		App();
		int exec();
		bool init();
		void event(SDL_Event* event);
		void keydown(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod);
		void keyup(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod);
		void loop();
		void render();
		void quit();
		void cleanup();
};
#endif
