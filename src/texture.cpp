/**
 * @defgroup   TEXTURE texture
 *
 * @brief      Texture handler with many draw definitions
 *
 * @author     schdoc
 * @date       2022
 */

#include "texture.h"

Texture::Texture(){
	//constructor
}

SDL_Texture* Texture::load(SDL_Renderer* renderer, char* file){
	SDL_Surface* surf = NULL;
	SDL_Texture* tex = NULL;
	if((surf = SDL_LoadBMP(file))==NULL){
		return NULL;
	}
	SDL_SetColorKey(surf, true, SDL_MapRGB(surf->format, 255, 0, 255));
	tex = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	return tex;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, SDL_Rect* srcR, SDL_Rect* dstR){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_RenderCopy(dest, src, srcR, dstR);
	return true;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, int x, int y){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(src, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(dest, src, NULL, &rect);
	return true;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, SDL_Rect* srcR, int x, int y){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(src, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(dest, src, srcR, &rect);
	return true;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, int x1, int y1, int x2, int y2, int w, int h){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_Rect srcR;
	srcR.x = x1;
	srcR.y = y1;
	srcR.w = w;
	srcR.h = h;
	SDL_Rect dstR;
	dstR.x = x2;
	dstR.y = y2;
	dstR.w = w;
	dstR.h = h;
	SDL_RenderCopy(dest, src, &srcR, &dstR);
	return true;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, int x1, int y1, int x2, int y2, int w, int h, SDL_RendererFlip flip){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_Rect srcR;
	srcR.x = x1;
	srcR.y = y1;
	srcR.w = w;
	srcR.h = h;
	SDL_Rect dstR;
	dstR.x = x2;
	dstR.y = y2;
	dstR.w = w;
	dstR.h = h;
	SDL_RenderCopyEx(dest, src, &srcR, &dstR, 0, NULL, flip);
	return true;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, int x1, int y1, int x2, int y2, int w, int h, double angle){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_Rect srcR;
	srcR.x = x1;
	srcR.y = y1;
	srcR.w = w;
	srcR.h = h;
	SDL_Rect dstR;
	dstR.x = x2;
	dstR.y = y2;
	dstR.w = w;
	dstR.h = h;
	SDL_RenderCopyEx(dest, src, &srcR, &dstR, angle, NULL, SDL_FLIP_NONE);
	return true;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, int x1, int y1, int x2, int y2, int w, int h, double angle, SDL_RendererFlip flip){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_Rect srcR;
	srcR.x = x1;
	srcR.y = y1;
	srcR.w = w;
	srcR.h = h;
	SDL_Rect dstR;
	dstR.x = x2;
	dstR.y = y2;
	dstR.w = w;
	dstR.h = h;
	SDL_RenderCopyEx(dest, src, &srcR, &dstR, angle, NULL, flip);
	return true;
}

bool Texture::draw(SDL_Texture* src, SDL_Renderer* dest, int x1, int y1, int x2, int y2, int w, int h, double angle, int oX, int oY, SDL_RendererFlip flip){
	if(src == NULL || dest == NULL){
		return false;
	}
	SDL_Rect srcR;
	srcR.x = x1;
	srcR.y = y1;
	srcR.w = w;
	srcR.h = h;
	SDL_Rect dstR;
	dstR.x = x2;
	dstR.y = y2;
	dstR.w = w;
	dstR.h = h;
	SDL_Point center;
	center.x = oX;
	center.y = oY;
	SDL_RenderCopyEx(dest, src, &srcR, &dstR, angle, &center, flip);
	return true;
}

SDL_Rect Texture::rect(int x, int y, int w, int h){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return rect;
}
