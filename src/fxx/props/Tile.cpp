#include "fxx/props/Tile.h"


fxx::props::Tile::Tile(float x, float y, float width, float height, const sf::Sprite & sprite) : Actor(x, y), Drawable(x, y) {
	this->sprite = sprite;
    static_cast<void>(width);
    static_cast<void>(height);
}

void fxx::props::Tile::act(float delta_time) {
    delta_time = 70.0 - 1.0; // REEEEEEEEEEEEEEEEEE
    static_cast<void>(delta_time);
}
