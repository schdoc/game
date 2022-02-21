/**
 * @defgroup   WEAPON weapon
 *
 * @brief      Header file for weapon object
 *
 * @author     schdoc
 * @date       2022
 */

#include "weapon.h"

// WeaponType WEAPON_GLOCK = {
// 	400,
// 	false,
// 	17,
// 	0,
// 	0,
// 	0,
// 	0,
// 	"./res/img/sprite/wpn_glock.bmp",
// };

Weapon::Weapon(){
	rate = 0;
	clipsize = 0;
	offX = 0;
	offY = 0;
	rotX = 0;
	rotY = 0;
	fireX = 0;
	fireY = 0;
	state = 0;
	lastFire = 0;
	fullauto = false;
	canFire = true;
}

Weapon::~Weapon(){

}

bool Weapon::load(SDL_Renderer* renderer, char* file){
	if((tex = Texture::load(renderer, file)) == NULL){
		return false;
	}
	int cool;
	SDL_QueryTexture(tex, NULL, NULL, &this->width, &cool);
	this->animator.length = 4;
	this->height = cool/this->animator.length;
	return true;
}

bool Weapon::fire(){
	if(!canFire) return false;
	lastFire = SDL_GetTicks();
	canFire = false;
	return true;
}

void Weapon::loop(){
	if(lastFire+rate < SDL_GetTicks()){
		canFire = true;
	}
}

void Weapon::render(SDL_Renderer* dest){
	if(tex == NULL || dest == NULL) return;
	Texture::draw(tex, dest, 0, height*state, x+offX, y+offY, width, height, angle, rotX, rotY, flip?SDL_FLIP_VERTICAL:SDL_FLIP_NONE);
}
