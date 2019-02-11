#pragma once
#include "fxx/actors/collidable.h"
#include "fxx/actors/drawable.h"
#include <SFML/Graphics/Texture.hpp>


namespace fxx {
	namespace actors {
		class brick;
	}
}


class fxx::actors::brick : public fxx::actors::collidable, public fxx::actors::drawable {
public:
	brick(float x, float y, float width, float height, const sf::Sprite & sprite);

	virtual void act(float delta_time) override;
	virtual void collide(fxx::actors::collidable & that) override;
};
