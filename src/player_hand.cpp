/**
 * @defgroup   PLAYER_HAND player hand
 *
 * @brief      Player hand (to hold weapon). Used in player.cpp
 *
 * @author     schdoc
 * @date       2022
 */

#include "player.h"
#include "constants.h"
#include <cmath>

PlayerHand::PlayerHand(){
	tex = NULL;
	aimX = 0;
	aimY = 0;
	aimoffX = 0;
	aimoffY = 0;
	offX = 0;
	offY = 0;
	mouse1 = false;
	clicktimer = 0;
}

bool PlayerHand::load(SDL_Renderer* renderer, char* file, int width, int height){
	if((tex = Texture::load(renderer, file)) == NULL){
		return false;
	}
	this->width = width;
	this->height = height;
	this->offX = width/2;
	this->offY = 0;
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
	angle = atan(A)*180 / PI;
	if(b < 0){
		angle+=180;
		flip = true;
	}
	else{
		flip = false;
	}
	this->weapon.x = x;
	this->weapon.y = y;
	this->weapon.angle = angle;
	this->weapon.flip = flip;
	this->weapon.rotY = height/2;
	this->weapon.loop();
	// mouse click

};

void PlayerHand::render(SDL_Renderer* dest){
	this->weapon.render(dest);
	if(tex == NULL || dest == NULL) return;
	Texture::draw(tex, dest, 0, 0, x+offX, y+offY, width, height, angle, 0, height/2, flip?SDL_FLIP_VERTICAL:SDL_FLIP_NONE);
}

// void PlayerHand::mousedown(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel){
	
// }

// void PlayerHand::mouseup(Uint8 button, Uint8 clicks, Sint32 xrel, Sint32 yrel){
	
// }
