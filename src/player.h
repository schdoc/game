#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "entity.h"

class Weapon{
public:
		int rate; // time it takes between each shot
		bool rapid; // auto or semi
		int clipsize; // < 0 = infinite
		int reload;
		bool canFire; // reloading, time between shots, etc...
		float x;
		float y;
		int offX;
		int offY;
		int fireX; // where hitscans should be
		int fireY;

		bool load(SDL_Renderer* renderer, char* file, int width, int height);
		bool fire();
		void loop();
		void render();
		void cleanup();
	private:
		SDL_Texture* tex;
};

class PlayerHand{
	public:
		PlayerHand();
		bool load(SDL_Renderer* renderer, char* file, int width, int height);
		void loop();
		void render(SDL_Renderer* dest);
		void cleanup();

		float x;
		float y;
		int width;
		int height;
		double angle;
		int aimX;
		int aimY;
		int aimoffX;
		int aimoffY;
		int offX;
		int offY;
		bool flip;

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
