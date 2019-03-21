#ifndef FXX_ACTORS_DRAWABLE_H
#define FXX_ACTORS_DRAWABLE_H

#include "fxx/actors/Actor.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace fxx {
	namespace actors {
		class Drawable;
	}
}


class fxx::actors::Drawable : virtual public fxx::actors::Actor {
public:
	Drawable(float x, float y);
	virtual ~Drawable() = 0;

	virtual void draw(sf::RenderTarget & target);

protected:
	sf::Sprite sprite;
};

#endif
