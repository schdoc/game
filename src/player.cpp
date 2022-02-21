#include "player.h"

Player::Player(){
}

bool Player::load(SDL_Renderer* renderer, char* file, int width, int height, int length){
	if(Entity::load(renderer, file, width, height, length) == false){
		return false;
	}
	return true;
}

void Player::loop(){
	Entity::loop();
	this->hand.x = x;
	this->hand.y = y;
	SDL_GetMouseState(&this->hand.aimX, &this->hand.aimY);
	// Did not think i would need the window or the renderer... oops
	// SDL_RenderWindowToLogical() // https://github.com/libsdl-org/SDL/pull/4939
	this->hand.loop();
}

void Player::render(SDL_Renderer* dest){
	Entity::render(dest);
	this->hand.render(dest);
}

void Player::cleanup(){
	Entity::cleanup();
	this->hand.cleanup();
}

void Player::step(){
	if(speedX != 0){
		animator.length = 4;
	}
	else{
		animator.length = 0;
	}
	Entity::step();
}

bool Player::collision(Entity* entity){
}
