#pragma once
#include "fxx/actors/actor.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace fxx {
	namespace actors {
		class drawable;
	}
}


class fxx::actors::drawable : virtual public fxx::actors::actor {
protected:
	sf::Sprite sprite;

public:
	drawable(float x, float y);
	virtual ~drawable() = 0;

	virtual void draw(sf::RenderTarget & target);
};
