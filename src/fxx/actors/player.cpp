#include "fxx/actors/player.h"


fxx::actors::player::player(float x, float y, float width, float height, const sf::Sprite & sprite) : actor(x, y), collidable(x, y, width, height), drawable(x, y), mobile(x, y) {
	this->sprite = sprite;
}

void fxx::actors::player::act(float delta_time) {
	mobile::act(delta_time);
}


void fxx::actors::player::collide(fxx::actors::collidable & that) {
	if (clips(that)) {
		unclip(that);
	}
}
