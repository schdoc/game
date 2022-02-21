/**
 * @defgroup   WEAPON weapon
 *
 * @brief      Weapon and weapon types held by PlayerHand
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _WEAPON_H_
#define _WEAPON_H_
#include "entity.h"

class Weapon : public StaticEntity{
	public:
		Weapon();
		~Weapon();

		int rate; // in ms
		bool fullauto;
		int clipsize;
		int offX; // offset relative to hand
		int offY; 
		int rotX;
		int rotY;
		int fireX; // where hitscans should come from
		int fireY;
		int state;

		int lastFire;
		bool canFire; 
		bool load(SDL_Renderer* dest, char* file);
		bool fire();
		void loop();
		void render(SDL_Renderer* dest);
	private:
		SDL_Texture* tex;
};

#endif