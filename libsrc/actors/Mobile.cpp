#include "fxx/actors/Mobile.h"


fxx::actors::Mobile::Mobile(float x, float y) : Actor(x, y) {

}


fxx::actors::Mobile::~Mobile() {

}


void fxx::actors::Mobile::act(float delta_time) {
	move(delta_time);
}


void fxx::actors::Mobile::accelerate(float a_x, float a_y) {
	acceleration += sf::Vector2f(a_x, a_y);
}


void fxx::actors::Mobile::move(float delta_time) {
	velocity += acceleration * delta_time;
	position += velocity * delta_time;
	acceleration *= 0.0f;
}
