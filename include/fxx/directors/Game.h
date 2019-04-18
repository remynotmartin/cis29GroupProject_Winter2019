#ifndef FXX_DIRECTORS_GAME_H
#define FXX_DIRECTORS_GAME_H

#include "fxx/actors/Brick.h"
#include "fxx/actors/Player.h"
#include "fxx/directors/Menu.h"
#include "fxx/hands/Randomizer.h"
#include "fxx/props/Tile.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <vector>

namespace fxx {
	namespace directors {
		class Game;
	}
}


class fxx::directors::Game {
public:
	Game(bool randomize);

private:
	enum class activity {
		TITLE,
		GAME,
		PAUSE,
		GAME_OVER
	};

    std::string p1name;
    std::string p2name;
	const float        FRAME_RATE = 120.0f;
	const unsigned int WIDTH      = 512;     // Original: 512
	const unsigned int HEIGHT     = 1024;    // Original: 512
	const std::string  TITLE      = "Ready? Go!";

	const float FALL_ACCELERATION = 200.0f; // Dan OG-spec: 128.0f

	sf::Clock              clock;
	sf::RenderWindow       window;
	Menu                   menu;
	fxx::hands::Randomizer randomizer;
	activity               active_activity;

	std::vector<fxx::actors::Actor *>      actors;
	std::vector<fxx::actors::Collidable *> collidables;
	std::vector<fxx::actors::Drawable *>   drawables;
	std::vector<fxx::actors::Mobile *>     mobiles;

	std::vector<fxx::props::Tile>              tiles;
	std::vector<fxx::actors::Brick>            bricks;
	std::vector<fxx::actors::Player>           players;
	std::vector<sf::Texture>                   textures;
	std::unordered_map<std::string, sf::Music> soundMap;

	void set_up_level(bool randomize);
	void set_up_players();

	void direct();
	void direct(float delta_time);
	void handle_event(sf::Event event);
	void handle_key_press(sf::Keyboard::Key key);
	void handle_key_release(sf::Keyboard::Key key);
	void handle_mouse_click(sf::Mouse::Button button);
	void handle_mouse_release(sf::Mouse::Button button);
	//void draw();
    void draw(sf::Text& text);
    bool flag;
    bool flag2;
    void run_menu();
    bool GameFinished;
    
public:
    std::string getP1Name() {return p1name;}
    std::string getP2Name() {return p2name;}
};

#endif
