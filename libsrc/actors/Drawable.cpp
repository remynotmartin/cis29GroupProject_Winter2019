#include "fxx/actors/Drawable.h"


fxx::actors::Drawable::Drawable(float x, float y) : Actor(x, y) {

}

fxx::actors::Drawable::~Drawable() {

}

void fxx::actors::Drawable::draw(sf::RenderTarget & target) {
	sprite.setPosition(position);
	target.draw(sprite);
}
