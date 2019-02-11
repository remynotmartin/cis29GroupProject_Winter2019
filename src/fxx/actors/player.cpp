#include "fxx/actors/player.h"


fxx::actors::player::player(float x, float y, float width, float height,  const fxx::hands::animation & run_animation) : actor(x, y), collidable(x, y, width, height), drawable(x, y), mobile(x, y), jump_time(0.0f), run_animation(run_animation) {

}

void fxx::actors::player::act(float delta_time) {
	jump_time += delta_time;
	run_animation.play(delta_time);
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


void fxx::actors::player::draw(sf::RenderTarget & target) {
	sprite = run_animation.get_active_frame();

	if (velocity.x > 0) {
		sprite.setOrigin({sprite.getLocalBounds().width, 0});
		sprite.setScale({-1, 1});
	}

	drawable::draw(target);
}


void fxx::actors::player::jump() {
	if (jump_time < FULL_JUMP_TIME) {
		velocity.y = JUMP_VELOCITY;
	}
}


void fxx::actors::player::cut_jump() {
	velocity.y = 0.0f;
	jump_time = FULL_JUMP_TIME;
}


void fxx::actors::player::run() {
	velocity.x = RUN_VELOCITY;
}
