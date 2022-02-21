#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include "anim.h"
#include "texture.h"
#include "framelimiter.h"
#include "tile.h"
#include "map.h"

enum {
	ENTITY_TYPE_GENERIC = 0,
	ENTITY_TYPE_PLAYER = 0x00000001
};

enum {
	ENTITY_FLAG_NONE = 0,
	ENTITY_FLAG_GRAV = 0x00000001,
	ENTITY_FLAG_NOCLIP = 0x00000002,
	ENTITY_FLAG_MAP = 0x000000004
};

class Entity{
	public:
		static std::vector<Entity*> entities;
		
		float x;
		float y;
		int width;
		int height;
		int anim;

		bool left;
		bool right;
		bool flip;

		double angle;

		int type;
		int flags;
		bool dead;
		
		Entity();
		virtual ~Entity();

		float maxSpeedX;
		float maxSpeedY;

		bool load(SDL_Renderer* renderer, char* file, int w, int h, int length);
		virtual void loop();
		virtual void render(SDL_Renderer* dest);
		virtual void cleanup();
		virtual void step();
		virtual bool collision(Entity* other);
		virtual void move(float toX, float toY);
		virtual void stop();
		virtual bool colliding(int oX, int oY, int oW, int oH);
		bool jump();
	protected:
		float speedX;
		float speedY;
		float accelX;
		float accelY;
		int frameCol;
		int frameRow;
		int colX;
		int colY;
		int colW;
		int colH;
		bool jumpflag;
		Animator animator;
		SDL_Texture* tex;
	private:
		bool posValid(int toX, int toY);
		bool posValidTile(Tile* tile);
		bool posValidEnt(Entity* entity, int toX, int toY);
};

class EntityCollision{
	public:
		static std::vector<EntityCollision> queue;
	public:
		Entity* entA;
		Entity* entB;
		EntityCollision();
};

#endif
