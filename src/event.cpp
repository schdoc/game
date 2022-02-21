#include "main.h"

void App::event(SDL_Event* event){
	EventHandler::event(event);
}

void App::quit(){
	RUNNING = false;
}

void App::keydown(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod){
	switch(sym){
		case SDLK_RETURN:
			if(SDL_GetModState() & KMOD_ALT){
				FULLSCREEN = !FULLSCREEN;
				SDL_SetWindowFullscreen(window, FULLSCREEN?SDL_WINDOW_FULLSCREEN_DESKTOP:0);
			}
			break;
		default:
			break;
	}
}

void App::keyup(SDL_Scancode scan, SDL_Keycode sym, Uint16 mod){
	// switch(sym){
	// 	case SDLK_LEFT:
	// 		cheesedude.left = false;
	// 		break;
	// 	case SDLK_RIGHT:
	// 		cheesedude.right = false;
	// 		break;
	// 	default:
	// 		break;
	// }
}
