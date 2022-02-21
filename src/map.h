/**
 * @defgroup   MAP map
 *
 * @brief      Map class adapted from sdltutorials for only one map
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _MAP_H_
#define _MAP_H_

#include <SDL.h>
#include <vector>

#include "tile.h"
#include "texture.h"

class Map{
	private:
		std::vector<Tile> tiles;
	public:
		static Map currentmap;
		SDL_Texture* tileset;
		Map();
		bool load(SDL_Renderer* dest, char* file);
		void draw(SDL_Renderer* dest, int mapX, int mapY);
		void cleanup();
		Tile* getTile(int x, int y);
		int offX;
		int offY;
};

#endif
