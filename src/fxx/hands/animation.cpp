#include "fxx/hands/animation.h"


fxx::hands::animation::animation(sf::Texture * texture, std::size_t images_count,
			   	float switch_interval) :
	   	active_frame_index(0), frame_time(0.0f), SWITCH_INTERVAL(switch_interval) {
	unsigned int frame_width = texture->getSize().x / images_count;
	unsigned int frame_height = texture->getSize().y;

	for (std::size_t i = 0; i < images_count; i++) {
		sf::Sprite frame;
		frame.setTexture(*texture);
		frame.setTextureRect(sf::IntRect(i * frame_width, 0, frame_width, frame_height));
		frames.push_back(frame);
	}
}


void fxx::hands::animation::play(float delta_time) {
	frame_time += delta_time;

	while (frame_time >= SWITCH_INTERVAL) {
		frame_time -= SWITCH_INTERVAL;
		active_frame_index++;
		active_frame_index %= frames.size();
	}
}


sf::Sprite fxx::hands::animation::get_active_frame() const {
	return frames[active_frame_index];
}
