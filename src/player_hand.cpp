#include "player.h"
#include <cmath>

PlayerHand::PlayerHand(){
	tex = NULL;
}

bool PlayerHand::load(SDL_Renderer* renderer, char* file, int width, int height){
	if((tex = Texture::load(renderer, file)) == NULL){
		return false;
	}
	this->width = width;
	this->height = height;
	this->offX = width/2;
	this->aimoffX = width/2;
	this->aimoffY = height/2;
	return true;
}

void PlayerHand::loop(){
	// knew that 9th grade trigonometry would be useful someday
	// i am very proud of this
	int a = (aimY-y)-aimoffY;
	int b = (aimX-x)-aimoffX;
	double A = (double)a/b;
	angle = atan(A)*180 / 3.141592654f;
	if(b < 0){
		angle+=180;
		flip = true;
	}
	else{
		flip = false;
	}
	// mouse click

};

void PlayerHand::render(SDL_Renderer* dest){
	if(tex == NULL || dest == NULL) return;
	Texture::draw(tex, dest, 0, 0, x+offX, y+offY, width, height, angle, 0, height/2, flip?SDL_FLIP_VERTICAL:SDL_FLIP_NONE);
}

void PlayerHand::cleanup(){
	if(tex){
		SDL_DestroyTexture(tex);
	}
	tex = NULL;
}

// void PlayerHand::mousedown(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel){
	
// }

// void PlayerHand::mouseup(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel){
	
// }
