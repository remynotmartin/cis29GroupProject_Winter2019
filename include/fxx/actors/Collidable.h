#ifndef FXX_ACTORS_COLLIDABLE_H
#define FXX_ACTORS_COLLIDABLE_H

#include "fxx/actors/Actor.h"
#include <SFML/Graphics/Rect.hpp>
#include <utility>

namespace fxx {
	namespace actors {
		class Collidable;
	}
}

class fxx::actors::Collidable : virtual public fxx::actors::Actor
{
public:
	Collidable(float x, float y, float width, float height);

	virtual void collide(fxx::actors::Collidable & that) = 0;

protected:
	sf::Vector2f size;

	bool clips(const fxx::actors::Collidable & that) const;
	void unclip(const fxx::actors::Collidable & that);

	sf::Vector2f  clip_dir(const fxx::actors::Collidable & that) const;
	sf::FloatRect clip_rect(const fxx::actors::Collidable & that) const;
};

#endif
