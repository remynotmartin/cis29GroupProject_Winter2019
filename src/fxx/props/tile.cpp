#include "fxx/props/tile.h"


fxx::props::tile::tile(float x, float y, float width, float height,
			   	const sf::Sprite & sprite) : actor(x, y), drawable(x, y) {
	this->sprite = sprite;
}

void fxx::props::tile::act(float delta_time) {

}
