#pragma once
#include "fxx/actors/actor.h"
#include <SFML/Graphics/Rect.hpp>
#include <utility>


namespace fxx {
	namespace actors {
		class collidable;
	}
}


class fxx::actors::collidable : virtual public fxx::actors::actor {
public:
	collidable(float x, float y, float width, float height);

	virtual void collide(fxx::actors::collidable & that) = 0;

protected:
	sf::Vector2f size;

	bool clips(const fxx::actors::collidable & that) const;
	void unclip(const fxx::actors::collidable & that);

	sf::Vector2f clip_dir(const fxx::actors::collidable & that) const;
	sf::FloatRect clip_rect(const fxx::actors::collidable & that) const;
};
