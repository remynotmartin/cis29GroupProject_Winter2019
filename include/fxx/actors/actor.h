#ifndef FXX_ACTORS_ACTOR_H
#define FXX_ACTORS_ACTOR_H

#include <SFML/System/Vector2.hpp>

namespace fxx {
	namespace actors {
		class actor;
	}
}


class fxx::actors::actor {
public:
	actor(float x, float y);

	virtual void act(float delta_time) = 0;

protected:
	sf::Vector2f position;
};

#endif
