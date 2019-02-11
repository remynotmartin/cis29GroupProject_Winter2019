#include "fxx/actors/player.h"


fxx::actors::player::player(float x, float y, float width, float height, const sf::Sprite & sprite) : actor(x, y), collidable(x, y, width, height), drawable(x, y), mobile(x, y), jump_time(0.0f) {
	this->sprite = sprite;
}

void fxx::actors::player::act(float delta_time) {
	mobile::act(delta_time);
}


void fxx::actors::player::collide(fxx::actors::collidable & that) {
	if (clips(that)) {
		if (clips_top(that)) {
			jump_time = 0.0f;
		}

		unclip(that);
	}
}


void fxx::actors::player::jump() {
	if (jump_time < FULL_JUMP_TIME) {
		velocity.y = JUMP_VELOCITY;
	}
}


void fxx::actors::player::cut_jump() {
	velocity.y = 0.0f;
}


void fxx::actors::player::run() {
	velocity.x = RUN_VELOCITY;
}
