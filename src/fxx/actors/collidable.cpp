#include "fxx/actors/collidable.h"


fxx::actors::collidable::collidable(float x, float y, float width, float height) : actor(x, y), size(width, height) {

}


bool fxx::actors::collidable::clips(const fxx::actors::collidable & that) const {
	return position.x < that.position.x + that.size.x
		&& position.x + size.x > that.position.x
		&& position.y < that.position.y + that.size.y
		&& position.y + size.y > that.position.y;
}


void fxx::actors::collidable::unclip(const fxx::actors::collidable & that) {
	if (position.y < that.position.y) {
		position.y = that.position.y - size.y;
	} else if (position.y > that.position.y) {
		position.y = that.position.y + that.size.y;
	} else if (position.x < that.position.x) {
		position.x = that.position.x - size.x;
	} else if (position.x > that.position.x) {
		position.x = that.position.x + that.size.x;
	}
}
