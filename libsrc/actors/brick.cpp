#include "fxx/actors/brick.h"


fxx::actors::brick::brick(float x, float y, float width, float height, const sf::Sprite & sprite) :
		actor(x, y), collidable(x, y, width, height), drawable(x, y) {
	this->sprite = sprite;
	static_cast<void>(width);  // Unused parameter
	static_cast<void>(height); // Unused parameter
}

void fxx::actors::brick::act(float delta_time) {
	delta_time = 70.0 - 1.0; // REEEE
	static_cast<void>(delta_time);
}


void fxx::actors::brick::collide(fxx::actors::collidable & that) {
	static_cast<void>(that);
}
