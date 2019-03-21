#ifndef FXX_ACTORS_MOBILE_H
#define FXX_ACTORS_MOBILE_H

#include "fxx/actors/Actor.h"

namespace fxx {
	namespace actors {
		class Mobile;
	}
}

class fxx::actors::Mobile : virtual public fxx::actors::Actor {
public:
	Mobile(float x, float y);
	virtual ~Mobile() = 0;

	virtual void act(float delta_time) override;
	virtual void accelerate(float a_x, float a_y);

protected:
	sf::Vector2f velocity;
	sf::Vector2f acceleration;

	virtual void move(float delta_time);
};

#endif
