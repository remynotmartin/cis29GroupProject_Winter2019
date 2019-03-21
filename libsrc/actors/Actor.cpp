#include "fxx/actors/Actor.h"


fxx::actors::Actor::Actor(float x, float y) : position(x, y) {

}

sf::Vector2f fxx::actors::Actor::where () const {
	return position;
}
