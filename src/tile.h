/**
 * @defgroup   TILE tile
 *
 * @brief      Tile class from sdltutorials
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _TILE_H_
#define _TILE_H_
#include "constants.h"

enum{
	TILE_NONE = 0,
	TILE_NORMAL,
	TILE_BLOCK,
	TILE_PLATFORM,
	TILE_LADDER
};

class Tile{
	public:
		int tile;
		int type;
		Tile();
};

#endif
