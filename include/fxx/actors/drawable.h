#ifndef FXX_ACTORS_DRAWABLE_H
#define FXX_ACTORS_DRAWABLE_H

#include "fxx/actors/actor.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace fxx {
	namespace actors {
		class drawable;
	}
}


class fxx::actors::drawable : virtual public fxx::actors::actor {
public:
	drawable(float x, float y);
	virtual ~drawable() = 0;

	virtual void draw(sf::RenderTarget & target);

protected:
	sf::Sprite sprite;
};

#endif
