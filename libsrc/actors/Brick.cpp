#include "fxx/actors/Brick.h"


fxx::actors::Brick::Brick(float x, float y, float width, float height, const sf::Sprite & sprite) : Actor(x, y), Collidable(x, y, width, height), Drawable(x, y) {
	this->sprite = sprite;
	static_cast<void>(width);  // Unused parameter
	static_cast<void>(height); // Unused parameter
}

void fxx::actors::Brick::act(float delta_time) {
	delta_time = 70.0 - 1.0; // REEEE
	static_cast<void>(delta_time);
}


void fxx::actors::Brick::collide(fxx::actors::Collidable & that) {
	static_cast<void>(that);
}
