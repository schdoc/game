/**
 * @defgroup   TEXT text
 *
 * @brief      Text rendering class
 *
 * @author     schdoc
 * @date       2022
 */

#include "text.h"
#include <cmath>

Text::Text(){
	tilesize = 0;
	tilewidth = 0;
	tileheight = 0;
	charspacing = 0;
	bob = false;
	bobradius = 0;
}

bool Text::load(SDL_Renderer* renderer, char* file, int tilesize){
	if((tex = Texture::load(renderer, file)) == NULL){
		return false;
	}
	this->tilesize = tilesize;
	SDL_QueryTexture(tex, NULL, NULL, &this->width, &this->height);
	this->tilewidth = this->width/this->tilesize;
	this->tileheight = this->height/this->tilesize;
	// 32 to 127 charmap sprite
	return true;
}

void Text::render(SDL_Renderer* dest){
	if(tex == NULL || dest == NULL) return;
	int line = 1;
	int ofsete = 0;
	for(int i=0; i < text.size(); i++){
		if(text[i] == '\n'){
			line++;
			ofsete+=(i+1);
		}
		int id = text[i]-32;
		int equis = (id % tilewidth) * tilesize;
		int igriega = (id / tilewidth) * tilesize;
		double timere = (SDL_GetTicks()/100.0f)+i;
		int bobequis = ((std::sin(timere)/PI)*bobradius)*bob;
		int bobigriega = ((std::cos(timere)/PI)*bobradius)*bob;
		Texture::draw(
			tex,
			dest,
			equis,
			igriega,
			x+((i-ofsete)*(tilesize+charspacing))+(bobequis),
			(y+(line*tilesize))+(bobigriega),
			tilesize,
			tilesize
		);
	}
}