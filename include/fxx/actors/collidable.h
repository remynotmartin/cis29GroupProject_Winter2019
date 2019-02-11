#pragma once
#include "fxx/actors/actor.h"


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

	bool clips_top(const fxx::actors::collidable & that) const;
	bool clips_right(const fxx::actors::collidable & that) const;
	bool clips_bottom(const fxx::actors::collidable & that) const;
	bool clips_left(const fxx::actors::collidable & that) const;
};
