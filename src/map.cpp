#include "map.h"

Map Map::currentmap;

Map::Map(){
	tileset = NULL;
}

bool Map::load(SDL_Renderer* dest, char* file){
	tiles.clear();
	FILE* map = fopen(file, "r");
	if(map == NULL){
		return false;
	}
	char tilefile[255];
	fscanf(map, "%s\n", tilefile);
	if((tileset = Texture::load(dest, tilefile)) == NULL){
		fclose(map);
		return false;
	}
	for(int y=0;y<MAP_HEIGHT;y++){
		for(int x=0;x<MAP_WIDTH;x++){
			Tile tile;
			fscanf(map, "%d,%d ", &tile.tile, &tile.type);
			tiles.push_back(tile);
		}
		fscanf(map, "\n");
	}
	fclose(map);
	return true;
}

void Map::draw(SDL_Renderer* dest, int mapX, int mapY){
	if(tileset == NULL) return;
	int w; int h;
	SDL_QueryTexture(tileset, NULL, NULL, &w, &h);
	int tilesetW = w/TILE_SIZE; // size in cells, not pixels
	int tilesetH = h/TILE_SIZE;
	int idx = 0;
	for(int y=0;y<MAP_HEIGHT;y++){
		for(int x=0;x<MAP_WIDTH;x++){
			if(tiles[idx].type == TILE_NONE){
				idx++;
				continue;
			}
			int tileX = mapX+(x*TILE_SIZE);
			int tileY = mapY+(y*TILE_SIZE);
			int setX = (tiles[idx].tile % tilesetW)*TILE_SIZE;
			int setY = (tiles[idx].tile / tilesetW)*TILE_SIZE;
			Texture::draw(tileset, dest, setX, setY, tileX, tileY, TILE_SIZE, TILE_SIZE);
			idx++;
		}
	}
}

void Map::cleanup(){
	if(tileset) {
		SDL_DestroyTexture(tileset);
	}
	tiles.clear();
}

Tile* Map::getTile(int x, int y){
	int id = 0;
	id = x/TILE_SIZE;
	id = id + (MAP_WIDTH*y/TILE_SIZE);
	if(id < 0 || id > tiles.size()){
		return NULL;
	}
	return &tiles[id];
}
