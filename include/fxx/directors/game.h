#pragma once
#include "fxx/actors/player.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


namespace fxx {
	namespace directors {
		class game;
	}
}


class fxx::directors::game {
public:
	game();

private:
	enum class activity {
		TITLE,
		GAME,
		PAUSE,
		GAME_OVER
	};

	const float FRAME_RATE = 20.0f;
	const unsigned int WIDTH = 512;
	const unsigned int HEIGHT = 416;
	const std::string TITLE = "Hello, world!";

	const float FALL_ACCELERATION = 128.0f;

	sf::Clock clock;
	sf::RenderWindow window;

	activity active_activity;

	std::vector<fxx::actors::actor *> actors;
	std::vector<fxx::actors::drawable *> drawables;
	std::vector<fxx::actors::mobile *> mobiles;

	std::vector<fxx::actors::player> players;

	void direct();
	void direct(float delta_time);
	void handle_event(sf::Event event);
	void handle_key_press(sf::Keyboard::Key key);
	void draw();
};
