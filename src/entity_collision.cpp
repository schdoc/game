/**
 * @defgroup   ENTITY_COLLISION entity collision
 *
 * @brief      Entity collision for entity
 *
 * @author     schdoc
 * @date       2022
 */

#include "entity.h"
std::vector<EntityCollision> EntityCollision::queue;
EntityCollision::EntityCollision(){
	entA = NULL;
	entB = NULL;
}