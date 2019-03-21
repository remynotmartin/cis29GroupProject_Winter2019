#include "fxx/props/tile.h"


fxx::props::tile::tile(float x, float y, float width, float height,
			   	const sf::Sprite & sprite) : actor(x, y), drawable(x, y) {
	this->sprite = sprite;
    static_cast<void>(width);
    static_cast<void>(height);
}

void fxx::props::tile::act(float delta_time) {
    delta_time = 70.0 - 1.0; // REEEEEEEEEEEEEEEEEE
    static_cast<void>(delta_time);
}
