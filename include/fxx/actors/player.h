#pragma once
#include "fxx/actors/drawable.h"
#include "fxx/actors/mobile.h"
#include <SFML/Graphics/Texture.hpp>


namespace fxx {
	namespace actors {
		class mobile;
		class player;
	}
}


class fxx::actors::player : public fxx::actors::drawable, public fxx::actors::mobile {
public:
	player(float x, float y);

	virtual void act(float delta_time) override;

private:
	sf::Texture texture;
};
