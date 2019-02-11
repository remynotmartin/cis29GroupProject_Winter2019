#pragma once
#include "fxx/actors/actor.h"


namespace fxx {
	namespace actors {
		class mobile;
	}
}


class fxx::actors::mobile : virtual public fxx::actors::actor {
public:
	mobile(float x, float y);
	virtual ~mobile() = 0;

	virtual void act(float delta_time) override;
	virtual void accelerate(float a_x, float a_y);

protected:
	sf::Vector2f velocity;
	sf::Vector2f acceleration;

	virtual void move(float delta_time);
};
