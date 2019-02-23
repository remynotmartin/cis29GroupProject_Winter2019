#include "fxx/actors/actor.h"


fxx::actors::actor::actor(float x, float y) : position(x, y) {

}

sf::Vector2f fxx::actors::actor::where () const {
	return position;
}
