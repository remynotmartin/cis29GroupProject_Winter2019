#ifndef FXX_ACTORS_ACTOR_H
#define FXX_ACTORS_ACTOR_H

#include <SFML/System/Vector2.hpp>

namespace fxx {
	namespace actors {
		class Actor;
	}
}


class fxx::actors::Actor {
public:
	Actor(float x, float y);
	virtual void act(float delta_time) = 0;
	sf::Vector2f where() const;

protected:
	sf::Vector2f position;
};

#endif
