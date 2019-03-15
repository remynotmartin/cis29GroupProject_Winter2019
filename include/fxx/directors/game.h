#ifndef FXX_DIRECTORS_GAME_H
#define FXX_DIRECTORS_GAME_H

#include "fxx/actors/brick.h"
#include "fxx/actors/player.h"
#include "fxx/directors/Menu.h"
#include "fxx/props/tile.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>

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

	const float        FRAME_RATE = 120.0f;
	const unsigned int WIDTH      = 512;     // Original: 512
	const unsigned int HEIGHT     = 1024;    // Original: 512
	const std::string  TITLE      = "Ready? Go!";

	const float FALL_ACCELERATION = 200.0f; // Dan OG-spec: 128.0f

	sf::Clock clock;
	sf::RenderWindow window;

	Menu menu;

	activity active_activity;

	std::vector<fxx::actors::actor *> actors;
	std::vector<fxx::actors::collidable *> collidables;
	std::vector<fxx::actors::drawable *> drawables;
	std::vector<fxx::actors::mobile *> mobiles;

	std::vector<fxx::props::tile> tiles;
	std::vector<fxx::actors::brick> bricks;
	std::vector<fxx::actors::player> players;

	std::vector<sf::Texture> textures;
	sf::Music bg_music;
	sf::Music menu_music;
	sf::Music jump_sound;
	//sf::SoundBuffer jumpBuffer;
	//sf::Sound jumpSound;

	void set_up_level();
	void set_up_players();

	void direct();
	void direct(float delta_time);
	void handle_event(sf::Event event);
	void handle_key_press(sf::Keyboard::Key key);
	void handle_key_release(sf::Keyboard::Key key);
	void draw();

    void run_menu();
};

#endif
