#include "fxx/actors/mobile.h"


fxx::actors::mobile::mobile(float x, float y) : actor(x, y) {

}


fxx::actors::mobile::~mobile() {

}


void fxx::actors::mobile::act(float delta_time) {
	move(delta_time);
}


void fxx::actors::mobile::accelerate(float a_x, float a_y) {
	acceleration += sf::Vector2f(a_x, a_y);
}


void fxx::actors::mobile::move(float delta_time) {
	velocity += acceleration * delta_time;
	position += velocity * delta_time;
	acceleration *= 0.0f;
}
