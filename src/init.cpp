#include "main.h"

bool App::Init(){
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		printf("Failed to initialize SDL2: %s", SDL_GetError());
		return false;
	}
	if((Screen = SDL_CreateWindow("Hi, SDL!",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_OPENGL)) == NULL){
		printf("Failed to create window: %s", SDL_GetError());
		return false;
	}
	return true;
}
