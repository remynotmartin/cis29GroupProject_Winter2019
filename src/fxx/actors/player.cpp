#include "fxx/actors/player.h"


fxx::actors::player::player(float x, float y) : actor(x, y), drawable(x, y), mobile(x, y) {
	texture.loadFromFile("share/textures/blues.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(204, 22, 44, 48));
}

void fxx::actors::player::act(float delta_time) {
	mobile::act(delta_time);
}
