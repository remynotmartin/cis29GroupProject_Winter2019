#pragma once
#include <SFML/System/Vector2.hpp>


namespace fxx {
	namespace actors {
		class actor;
	}
}


class fxx::actors::actor {
protected:
	sf::Vector2f position;

public:
	actor(float x, float y);

	virtual void act(float delta_time) = 0;
};
