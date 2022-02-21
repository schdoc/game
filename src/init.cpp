/**
 * @defgroup   INIT initialize
 *
 * @brief      Initialization
 *
 * @author     schdoc
 * @date       2022
 */

#include "main.h"

bool App::init(){
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		printf("Failed to initialize SDL2: %s", SDL_GetError());
		return false;
	}
	if((window = SDL_CreateWindow("Hi, SDL!",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE)) == NULL){
		printf("Failed to create window: %s", SDL_GetError());
		return false;
	}
	if((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL){
		printf("Failed to create renderer: %s", SDL_GetError());
		return false;	
	}
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	if((cheesedude.load(renderer, "./res/img/sprite/cheesedude_anim.bmp", 64, 64, 4)) == NULL){
		printf("Failed to load entity: %s", SDL_GetError());
		return false;
	}
	cheesedude.x = (SCREEN_WIDTH/2)-(cheesedude.width/2);
	cheesedude.y = (SCREEN_HEIGHT/2)-(cheesedude.height/2);
	if((cheesedude.hand.load(renderer, "./res/img/sprite/cheesedude_hand.bmp", 64, 64)) == NULL){
		printf("Failed to load entity: %s", SDL_GetError());
		return false;
	}
	if((cheesedude.hand.weapon.load(renderer, "./res/img/sprite/wpn_glock.bmp")) == NULL){
		printf("Failed to load entity: %s", SDL_GetError());
		return false;
	}
	if(Map::currentmap.load(renderer, "./res/map/flat.map") == false){
		printf("Failed to load map: %s", SDL_GetError());
		return false;
	}
	if(text.load(renderer, "./res/img/sprite/charmap.bmp", 16) == false){
		printf("Failed to load text: %s", SDL_GetError());
		return false;
	}
	text.text = "i procrastinated\ntoo much :(";
	text.charspacing = -6;
	text.bob = true;
	text.bobradius = 10;
	Entity::entities.push_back(&cheesedude);
	return true;
}
