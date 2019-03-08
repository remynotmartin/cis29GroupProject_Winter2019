#include "fxx/actors/drawable.h"


fxx::actors::drawable::drawable(float x, float y) : actor(x, y) {

}

fxx::actors::drawable::~drawable() {

}

void fxx::actors::drawable::draw(sf::RenderTarget & target) {
	sprite.setPosition(position);
	target.draw(sprite);
}
