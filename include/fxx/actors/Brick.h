#ifndef FXX_ACTORS_BRICK_H
#define FXX_ACTORS_BRICK_H

#include "fxx/actors/Collidable.h"
#include "fxx/actors/Drawable.h"
#include <SFML/Graphics/Texture.hpp>


namespace fxx {
	namespace actors {
		class Brick;
	}
}


class fxx::actors::Brick : public fxx::actors::Collidable, public fxx::actors::Drawable {
public:
	Brick(float x, float y, float width, float height, const sf::Sprite& sprite);

	virtual void act(float delta_time) override;
	virtual void collide(fxx::actors::Collidable & that) override;
};

#endif
