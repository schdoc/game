#include "entity.h"
std::vector<EntityCollision> EntityCollision::queue;
EntityCollision::EntityCollision(){
	entA = NULL;
	entB = NULL;
}