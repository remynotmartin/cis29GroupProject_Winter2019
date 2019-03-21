#ifndef FXX_PROPS_TILE_H
#define FXX_PROPS_TILE_H
#include "fxx/actors/Drawable.h"
#include <SFML/Graphics/Texture.hpp>


namespace fxx {
	namespace props {
		class Tile;
	}
}


class fxx::props::Tile : public fxx::actors::Drawable {
public:
	Tile(float x, float y, float width, float height, const sf::Sprite & sprite);

	virtual void act(float delta_time) override;
};

#endif
