#include "main.h"

void App::render(){
	SDL_SetRenderDrawColor(renderer, 85, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	Map::currentmap.draw(renderer, 0, 0);

	for(int i = 0; i < Entity::entities.size(); i++){
		auto entity = Entity::entities[i];
		if(!entity) continue;
		entity->render(renderer);
	}

	SDL_RenderPresent(renderer);
}
