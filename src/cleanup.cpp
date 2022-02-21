#include "main.h"

void App::cleanup(){
	for(int i = 0; i < Entity::entities.size(); i++){
		auto entity = Entity::entities[i];
		if(!entity) continue;
		entity->cleanup();
	}
	Entity::entities.clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
