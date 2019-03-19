#include "fxx/actors/collidable.h"
#include <cmath>


fxx::actors::collidable::collidable(float x, float y, float width, float height) :
	   	actor(x, y), size(width, height) {

}


bool fxx::actors::collidable::clips(const fxx::actors::collidable & that) const {
	return sf::FloatRect(position, size).intersects(sf::FloatRect(that.position, that.size));
}


void fxx::actors::collidable::unclip(const fxx::actors::collidable & that) {
	auto isect  = clip_rect(that);
	auto center = that.position + that.size / 2.0f;

	if (isect.width == 0.0f && isect.height == 0.0f) {
		return;
	}

	if (std::abs(center.y - isect.top) > std::abs(isect.left - center.x)) {
		if (isect.top + isect.height / 2.0f < center.y) {
			position.y = that.position.y - size.y;
		} else {
			position.y = that.position.y + size.y;
		}
	} else {
		if (isect.left + isect.width / 2.0f < center.x) {
			position.x = that.position.x - size.x;
		} else {
			position.x = that.position.x + size.x;
		}
	}
}


sf::Vector2f fxx::actors::collidable::clip_dir(const fxx::actors::collidable & that) const {
	auto isect = clip_rect(that);
	auto center = that.position + that.size / 2.0f;

	if (isect.width == 0.0f && isect.height == 0.0f) {
		return sf::Vector2f(0.0f, 0.0f);
	}

	if (center.y - isect.top > isect.left - center.x) {
		if (isect.top + isect.height / 2.0f < center.y) {
			return sf::Vector2f(0.0f, 1.0f);
		} else {
			return sf::Vector2f(0.0f, -1.0f);
		}
	} else {
		if (isect.left + isect.width / 2.0f < center.x) {
			return sf::Vector2f(-1.0f, 0.0f);
		} else {
			return sf::Vector2f(1.0f, 0.0f);
		}
	}
}


inline sf::FloatRect fxx::actors::collidable::clip_rect(const fxx::actors::collidable & that) const {
	sf::FloatRect isect;
	sf::FloatRect(position, size).intersects(sf::FloatRect(that.position, that.size), isect);
	return isect;
}
