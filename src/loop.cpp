/**
 * @defgroup   LOOP loop
 *
 * @brief      Loop function to update entities before render call
 *
 * @author     schdoc
 * @date       2022
 */

#include "main.h"

void App::loop(){
	Framelimiter::fps.loop();
	int mousex = 0;
	int mousey = 0;
	float aimx = 0;
	float aimy = 0;
	SDL_GetMouseState(&mousex, &mousey);
	SDL_RenderWindowToLogical(renderer, mousex, mousey, &aimx, &aimy);
	cheesedude.hand.aimX = (int)aimx;
	cheesedude.hand.aimY = (int)aimy;
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if(keys[SDL_SCANCODE_A]){
		cheesedude.left = true;
	}
	else{
		cheesedude.left = false;
	}
	if(keys[SDL_SCANCODE_D]){
		cheesedude.right = true;
	}
	else{
		cheesedude.right = false;
	}
	if(keys[SDL_SCANCODE_W]){
		cheesedude.jump();
	}
	// cheesedude.angle = SDL_GetTicks()%360;
	for(int i = 0; i < Entity::entities.size(); i++){
		auto entity = Entity::entities[i];
		if(!entity) continue;
		entity->loop();
	}
	for (int i=0;i<EntityCollision::queue.size();i++)
	{
		Entity* entA = EntityCollision::queue[i].entA;
		Entity* entB = EntityCollision::queue[i].entB;
		if(entA==NULL||entB==NULL) continue;
		if(entA->collision(entB)){
			entB->collision(entA);
		}
	}
	text.x = cheesedude.x;
	text.y = cheesedude.y-48;
	EntityCollision::queue.clear();
}
