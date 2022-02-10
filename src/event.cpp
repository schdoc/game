#include "main.h"

void App::Event(SDL_Event* Event){
	if(Event->type == SDL_QUIT){
		Running = false;
	}
}
