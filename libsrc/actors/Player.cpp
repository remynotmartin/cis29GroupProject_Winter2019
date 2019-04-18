#include "fxx/actors/Player.h"
#include <iostream>


fxx::actors::Player::Player(float x, float y, float width, float height, const fxx::hands::Animation& run_animation)
	: Actor(x, y), Collidable(x, y, width, height), Drawable(x, y), Mobile(x, y), jump_time(0.0f), is_running(false), run_animation(run_animation) {

}

void fxx::actors::Player::act(float delta_time) {
	jump_time += delta_time;
	run_animation.play(delta_time);
	Mobile::act(delta_time);
}


void fxx::actors::Player::collide(fxx::actors::Collidable & that) {
	if (clips(that)) {
		if (clip_dir(that).y > 0.0f) {
			jump_time = 0.0f;
			is_running = true;
		} else if (clip_dir(that).x < 0.0f) {
			is_running = false;
		}

		unclip(that);
	}
}


void fxx::actors::Player::draw(sf::RenderTarget & target) {
	sprite = run_animation.get_active_frame();

	if (velocity.x > 0) {
		sprite.setOrigin({sprite.getLocalBounds().width, 0});
		sprite.setScale({-1, 1});
	}

	Drawable::draw(target);
}


void fxx::actors::Player::jump() {
	if (jump_time < FULL_JUMP_TIME) {
		velocity.y = JUMP_VELOCITY;
	}
}


void fxx::actors::Player::cut_jump() {
	velocity.y = 0.0f;
	jump_time = FULL_JUMP_TIME;
}


void fxx::actors::Player::run() {
	if (is_running) {
		velocity.x = RUN_VELOCITY;
	}
}
