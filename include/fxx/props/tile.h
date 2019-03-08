#ifndef FXX_PROPS_TILE_H
#define FXX_PROPS_TILE_H
#include "fxx/actors/drawable.h"
#include <SFML/Graphics/Texture.hpp>


namespace fxx {
	namespace props {
		class tile;
	}
}


class fxx::props::tile : public fxx::actors::drawable {
public:
	tile(float x, float y, float width, float height, const sf::Sprite & sprite);

	virtual void act(float delta_time) override;
};

#endif
