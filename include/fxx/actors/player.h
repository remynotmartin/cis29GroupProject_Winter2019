#pragma once
#include "fxx/actors/collidable.h"
#include "fxx/actors/drawable.h"
#include "fxx/actors/mobile.h"
#include "fxx/hands/animation.h"
#include <SFML/Graphics/Texture.hpp>


namespace fxx {
	namespace actors {
		class player;
	}
}


class fxx::actors::player : public fxx::actors::collidable, public fxx::actors::drawable, public fxx::actors::mobile {
public:
	player(float x, float y, float width, float height, const fxx::hands::animation & run_animation);

	virtual void act(float delta_time) override;
	virtual void collide(fxx::actors::collidable & that) override;
	virtual void draw(sf::RenderTarget & target) override;

	void cut_jump();
	void jump();
	void run();

private:
	const float JUMP_VELOCITY = -128.0f;
	const float RUN_VELOCITY = 64.0f;
	const float FULL_JUMP_TIME = 0.5f;

	float jump_time;

	fxx::hands::animation run_animation;
};
