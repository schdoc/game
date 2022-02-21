/**
 * @defgroup   FRAMELIMITER framelimiter
 *
 * @brief      Framelimiter. For older machines that may not run the game at same speed (from sdltutorials)
 *
 * @author     schdoc
 * @date       2022
 */

#include "framelimiter.h"

Framelimiter Framelimiter::fps;

Framelimiter::Framelimiter(){
	oldtime = 0;
	newtime = 0;
	speed = 0;
	numframes = 0;
	frames = 0;
}

void Framelimiter::loop(){
	if(oldtime+1000<SDL_GetTicks()){
		oldtime=SDL_GetTicks();
		numframes=frames;
		frames=0;
	}
	speed=((SDL_GetTicks()-newtime)/1000.0f)*32.0f;
	newtime = SDL_GetTicks();
	frames++;
}

int Framelimiter::getFPS(){
	return numframes;
}

float Framelimiter::getFactor(){
	return speed;
}
