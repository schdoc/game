#include "entity.h"

std::vector<Entity*> Entity::entities;

Entity::Entity(){
	tex = NULL;
	x = 0.0f, y = 0.0f;
	width = 0, height = 0;
	anim = 0;

	left = false;
	right = false;

	type = ENTITY_TYPE_GENERIC;

	dead = false;
	flags = ENTITY_FLAG_GRAV;

	speedX = 0;
	speedY = 0;
	accelX = 0;
	accelY = 0;
	angle = 0;

	maxSpeedX = 10;
	maxSpeedY = 20;

	frameCol = 0;
	frameRow = 0;

	colX = 0;
	colY = 0;
	colW = 0;
	colH = 0;

	flip = false;
	jumpflag = false;
}

Entity::~Entity(){
}

bool Entity::load(SDL_Renderer* renderer, char* file, int w, int h, int length){
	if((tex = Texture::load(renderer, file)) == NULL){
		return false;
	}
	this->width = w;
	this->height = h;
	animator.length = length;
	return true;
}

void Entity::loop(){
	if(left==false&&right==false){
		stop();
	}
	if(left){
		accelX = -0.5;
	}
	else if(right){
		accelX = 0.5;
	}
	if(flags & ENTITY_FLAG_GRAV){
		accelY = 0.75;
	}
	speedX += accelX * Framelimiter::fps.getFactor();
	speedY += accelY * Framelimiter::fps.getFactor();

	if(speedX > maxSpeedX) speedX = maxSpeedX;
	if(speedX < -maxSpeedX) speedX = -maxSpeedX;
	if(speedY > maxSpeedY) speedY = maxSpeedY;
	if(speedY < -maxSpeedY) speedY = -maxSpeedY;

	step();
	move(speedX, speedY);
}

void Entity::render(SDL_Renderer* dest){
	if(tex == NULL || dest == NULL) return;
	Texture::draw(tex, dest, anim * width, animator.getFrame() * height, x, y, width, height, angle, flip?SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE);
}

void Entity::cleanup(){
	if(tex){
		SDL_DestroyTexture(tex);
	}
	tex = NULL;
}

void Entity::step(){
	if(left){
		flip = true;
	}else if(right){
		flip = false;
	}
	animator.step();
}

bool Entity::collision(Entity* entity){
	
}

void Entity::move(float toX, float toY){
	jumpflag = false;
	if(toX == 0 && toY == 0) return;

	double newX = 0;
	double newY = 0;
	
	toX *= Framelimiter::fps.getFactor();
	toY *= Framelimiter::fps.getFactor();

	if(toX!=0){
		if(toX >= 0){
			newX = Framelimiter::fps.getFactor();
		}
		else{
			newX = -Framelimiter::fps.getFactor();
		}
	}

	if(toY!=0){
		if(toY >= 0){
			newY = Framelimiter::fps.getFactor();
		}
		else{
			newY = -Framelimiter::fps.getFactor();
		}
	}

	while(true){
		if(flags & ENTITY_FLAG_NOCLIP){
			posValid((int)(x+newX), (int)(y+newY));
			x+=newX;
			y+=newY;
		}
		else{
			if(posValid((int)(x+newX), (int)(y))){

				x+=newX;
			}else{
				speedX = 0;
			}
			if(posValid((int)(x), (int)(y+newY))){

				y+=newY;
			}else{
				if(toY > 0){
					jumpflag = true;
				}
				speedY = 0;
			}

		}

		toX += -newX;
		toY += -newY;

		if(newX > 0 && toX <= 0) newX = 0;
		if(newX < 0 && toX >= 0) newX = 0;

		if(newY > 0 && toY <= 0) newY = 0;
		if(newY < 0 && toY >= 0) newY = 0;

		if(toX == 0) newX = 0;
		if(toY == 0) newY = 0;
		if(toX == 0 && toY == 0) break;
		if(newX == 0 && newY == 0) break;
	}
}

void Entity::stop(){
	if(speedX > 0){
		accelX = -1;
	}
	
	if(speedX < 0){
		accelX = 1;
	}

	if(speedX < 2.0f && speedX > -2.0f){
		accelX = 0;
		speedX = 0;
	}
}

bool Entity::colliding(int oX, int oY, int oW, int oH){
	int left1, left2;
	int right1, right2;
	int top1, top2;
	int bottom1, bottom2;

	int tX = (int)x + colX;
	int tY = (int)x + colY;

	left1 = tX;
	left2 = oX;
	
	right1 = left1 + width - 1 - colW;
	right2 = oX + oW - 1;

	top1 = tY;
	top2 = oY;

	bottom1 = top1 + height - 1 - colH;
	bottom2 = oY + oH - 1;
	
	if(bottom1 < top2) return false;
	if(top1 > bottom2) return false;
	if(right1 < left2) return false;
	if(left1 > right2) return false;

	return true;
}

bool Entity::posValid(int toX, int toY){
	bool a = true;

	int startx = (toX + colX)/TILE_SIZE;
	int starty = (toY + colY)/TILE_SIZE;
	int endx = ((toX + colX) + width - colW - 1)/TILE_SIZE;
	int endy = ((toY + colY) + height - colW - 1)/TILE_SIZE;

	for(int iy = starty;iy <= endy;iy++){
		for(int ix = startx;ix <= endx;ix++){
			Tile* tile = Map::currentmap.getTile(ix*TILE_SIZE, iy*TILE_SIZE);
			if(posValidTile(tile) == false){
				a = false;
			}
		}
	}
	if(flags & ENTITY_FLAG_MAP){
	}else{
		for(int i=0;i < entities.size();i++){
			if(posValidEnt(entities[i], toX, toY) == false){
				a = false;
			}
		}
	}

	return a;
}

bool Entity::posValidTile(Tile* tile){
	if(tile == NULL){
		return true;
	}

	if(tile->type == TILE_PLATFORM && speedY >= 0){
		return false;
	}

	if(tile->type == TILE_BLOCK){
		return false;
	}

	return true;
}

bool Entity::posValidEnt(Entity* entity, int toX, int toY){
	if(this != entity && entity != NULL && entity->dead == false &&
			entity->flags ^ ENTITY_FLAG_MAP &&
			entity->colliding(toX+colX, toY+colY, width-colW-1, height-colH-1) == true){
		EntityCollision col;
		col.entA = this;
		col.entB = entity;
		EntityCollision::queue.push_back(col);
		return false;
	}
	return true;
}

bool Entity::jump(){
	if(jumpflag == false) return false;
	speedY = -maxSpeedY;
	return true;
}
