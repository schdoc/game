/**
 * @defgroup   PLAYER player
 *
 * @brief      Player and PlayerHand header. Player from sdltutorials.
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "entity.h"
#include "weapon.h"

class PlayerHand : public StaticEntity{
	public:
		PlayerHand();
		bool load(SDL_Renderer* renderer, char* file, int width, int height);
		void loop();
		void render(SDL_Renderer* dest);

		int aimX;
		int aimY;
		int aimoffX;
		int aimoffY;
		int offX;
		int offY;

		bool mouse1;
		int clicktimer;

		Weapon weapon;
	private:
		SDL_Texture* tex;
};

class Player : public Entity {
	public:
		Player();
		bool load(SDL_Renderer* renderer, char* file, int width, int height, int length);
		void loop();
		void render(SDL_Renderer* dest);
		void cleanup();
		void step();
		bool collision(Entity* entity);
		PlayerHand hand;
};

#endif
