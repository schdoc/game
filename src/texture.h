/**
 * @defgroup   TEXTURE texture
 *
 * @brief      Texture handler with many draw definitions
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL.h>

class Texture{
	public:
		Texture();
		static SDL_Texture* load(SDL_Renderer* renderer, char* file);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, SDL_Rect* srcR, SDL_Rect* dstR);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, int x, int y);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, SDL_Rect* srcC, int x, int y);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, int x1, int y1, int x2, int y2, int w, int h);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, int x1, int y1, int x2, int y2, int w, int h, SDL_RendererFlip flip);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, int x1, int y1, int x2, int y2, int w, int h, double angle);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, int x1, int y1, int x2, int y2, int w, int h, double angle, SDL_RendererFlip flip);
		static bool draw(SDL_Texture* src, SDL_Renderer* dst, int x1, int y1, int x2, int y2, int w, int h, double angle, int oX, int oY, SDL_RendererFlip flip);
		static SDL_Rect rect(int x, int y, int w, int h);
};

#endif
