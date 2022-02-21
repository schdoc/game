/**
 * @defgroup   TEXT text
 *
 * @brief      Text rendering class
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _TEXT_H_
#define _TEXT_H_

#include "entity.h"
#include <string>

class Text : public StaticEntity{
	public:
		Text();
		std::string text;
		int tilesize;
		int tilewidth;
		int tileheight;
		int charspacing;
		bool bob;
		int bobradius;
		void render(SDL_Renderer* dest);
		bool load(SDL_Renderer* renderer, char* file, int tilesize);
};

#endif