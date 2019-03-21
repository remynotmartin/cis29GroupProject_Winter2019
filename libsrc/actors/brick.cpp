#include "fxx/actors/brick.h"


fxx::actors::brick::brick(float x, float y, float width, float height, const sf::Sprite & sprite) :
		actor(x, y), collidable(x, y, width, height), drawable(x, y) {
	this->sprite = sprite;
}

void fxx::actors::brick::act(float delta_time) {

}


void fxx::actors::brick::collide(fxx::actors::collidable & that) {

}
