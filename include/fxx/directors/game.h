#pragma once
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
	const float FRAME_RATE = 10.0f;
	const unsigned int WIDTH = 512;
	const unsigned int HEIGHT = 416;
	const std::string TITLE = "Hello, world!";

	enum class activity {
		TITLE,
		GAME,
		PAUSE,
		GAME_OVER
	};

	sf::Clock clock;
	sf::RenderWindow window;

	activity active_activity;

	void direct();
	void direct(float delta_time);
	void handle_event(sf::Event event);
	void handle_key_press(sf::Keyboard::Key key);
	void draw();
};
