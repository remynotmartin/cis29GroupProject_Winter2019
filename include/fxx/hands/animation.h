#ifndef FXX_HANDS_ANIMATION_H
#define FXX_HANDS_ANIMATION_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstddef>


namespace fxx {
	namespace hands {
		class animation;
	}
}


class fxx::hands::animation {
public:
	animation(sf::Texture * texture, std::size_t images_count, float switch_interval);

	void play(float delta_time);
	sf::Sprite get_active_frame() const;

private:
	std::vector<sf::Sprite> frames;
	std::size_t active_frame_index;
	float frame_time;
	const float SWITCH_INTERVAL;
};

#endif
