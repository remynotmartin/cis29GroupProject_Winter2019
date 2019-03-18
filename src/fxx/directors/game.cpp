#include "fxx/directors/game.h"
#include "fxx/hands/animation.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>


fxx::directors::game::game()
		: window(sf::VideoMode(WIDTH, HEIGHT), TITLE), menu(WIDTH, HEIGHT) {
	active_activity = activity::TITLE;

	textures.resize(6);

	set_up_level();
	set_up_players();

	menu.makeMenu();

	while (window.isOpen()) {
		if (active_activity == activity::TITLE) {
			run_menu();
		} else if (active_activity == activity::GAME) {
			direct();
		} else if (active_activity == activity::PAUSE) {

		} else if (active_activity == activity::GAME_OVER) {

		}
	}
}


void fxx::directors::game::set_up_level() {
	const unsigned int TILE_WIDTH = 32;
	textures.emplace_back();
    // Load tileset from sprite map
	textures.back().loadFromFile("share/textures/gutstiles.png");
	// Background music
	bg_music.openFromFile("share/textures/play_music.ogg");
	bg_music.setLoop(true);
	// Menu music
	menu_music.openFromFile("share/textures/menu_music.ogg");
	//std::cout << a << std::endl;
	jump_sound.openFromFile("share/textures/jump.ogg");
	//jumpBuffer.loadFromFile("share/textures/jump.wav");
	//jumpSound.setBuffer(jumpBuffer);
    menu_music.play();
    menu_music.setLoop(true);
	//bg_music.play();

	std::vector<sf::Sprite> tileset;
	sf::Sprite tile;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 5; j++) {
			tile.setTexture(textures.back());
			tile.setTextureRect(sf::IntRect(j * (TILE_WIDTH + 2) + 2,
								   	i * (TILE_WIDTH + 2) + 2, TILE_WIDTH, TILE_WIDTH));
			tileset.push_back(tile);
		}
	}

    const char* const gutsPath = "share/levels/guts";

	std::ifstream fin(gutsPath, std::ios::binary | std::ios::in);

	if (!fin.is_open()) {
		std::cerr << "Unable to open file: " << gutsPath << std::endl;
		std::exit(1);
	}

	unsigned char room_index;
	unsigned char width;
	unsigned char height;

	fin.read(reinterpret_cast<char *>(&room_index), 1);
	fin.read(reinterpret_cast<char *>(&width),      1);
	fin.read(reinterpret_cast<char *>(&height),     1);

	std::vector<bool> is_solid = {
		0, 1, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		0, 1, 1, 0, 1,
		0, 0, 0, 0, 0,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1
	};

	int i = 0;
	int j = 0;
	unsigned char count;
	unsigned char type;

	while (!fin.eof()) {
		fin.read(reinterpret_cast<char *>(&count), 1);
		fin.read(reinterpret_cast<char *>(&type), 1);

		while (count--) {
			tileset[type].setPosition(j * TILE_WIDTH, i * TILE_WIDTH);

			if (is_solid[type]) {
				bricks.emplace_back(j * TILE_WIDTH, i * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH, tileset[type]);

			}
            else {
				tiles.emplace_back(j * TILE_WIDTH, i * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH, tileset[type]);
			}

			j++;

			if (j == width) {
				j = 0;
				i++;
			}
		}
	}

	for (auto & tile : tiles) {
		drawables.push_back(&tile);
	}

	for (auto & brick : bricks) {
		collidables.push_back(&brick);
		drawables.push_back(&brick);
	}
}


void fxx::directors::game::set_up_players() {
	const unsigned int PLAYER_WIDTH  = 46;
	const unsigned int PLAYER_HEIGHT = 48;

	textures.emplace_back();
	textures.back().loadFromFile("share/textures/blues.png");
	fxx::hands::animation run_animation1(&textures.back(), 6, 1.0f / 10.0f);
	players.emplace_back(0.0f, 0.0f, PLAYER_WIDTH, PLAYER_HEIGHT, run_animation1);

    textures.emplace_back();
	textures.back().loadFromFile("share/textures/greens.png");
	fxx::hands::animation run_animation2(&textures.back(), 6, 1.0f / 10.0f);
	players.emplace_back(PLAYER_WIDTH, 0.0f, PLAYER_WIDTH, PLAYER_HEIGHT, run_animation2);

    // Range-based For Loop
	for (auto & player : players) {
		     actors.push_back(&player);
		collidables.push_back(&player);
		  drawables.push_back(&player);
		    mobiles.push_back(&player);
	}
}


void fxx::directors::game::direct() {
	const float DRAW_INTERVAL = 1.0f / FRAME_RATE;
	sf::Event event;

	float   delta_draw_time = 0.0f;
	float delta_direct_time = 0.0f;

	do {
		delta_direct_time = clock.restart().asSeconds();
		direct(delta_direct_time);
		delta_draw_time += delta_direct_time;
	} while (delta_draw_time < DRAW_INTERVAL);

	while (window.pollEvent(event)) {
		handle_event(event);
	}

	std::cout << delta_draw_time * FRAME_RATE * FRAME_RATE << std::endl;
	draw();
}


void fxx::directors::game::direct(float delta_time) {
	for (auto & player : players) {
		player.run();
	}

	for (auto mobile : mobiles) {
		mobile->accelerate(0, FALL_ACCELERATION);
	}

	for (auto actor : actors) {
		actor->act(delta_time);
	}

	for (auto a : collidables) {
		for (auto b : collidables) {
			if (a != b && !((a == &players[0] && b == &players[1]) ||
						    (b == &players[0] && a == &players[1]))) {
				a->collide(*b);
			}
		}
	}
}


void fxx::directors::game::draw() {
	window.clear(sf::Color::White);
	sf::Vector2f viewSize(static_cast<float>(HEIGHT * 1.0), static_cast<float>(WIDTH * 1.0));
          
    float yLock      = 230.0f,  // lock Y to hide void top & bottom
          xLeftLock  = 225.0f,  // keep  left-hand void out of view
          xRightLock = 4880.0f, // keep right-hand void out of view
          x1, x2,
          y1, y2;

    // Start of game, prevents left-hand void from entering view
    if      (players[0].where().x < xLeftLock) {
        x1 = xLeftLock;
        y1 = yLock;
    }
    // Right-Edge of map reached
    else if (players[0].where().x >= xRightLock) {
        x1 = xRightLock;
        y1 = yLock;
    }
    // While the game is running
    else {
        x1 = players[0].where().x;
        y1 = yLock;
    }

    // Do the same checks for player2 view
    if      (players[1].where().x < xLeftLock) {
        x2 = xLeftLock;
        y2 = yLock;
    }
    else if (players[1].where().x >= xRightLock) {
        x2 = xRightLock;
        y2 = yLock;
    }
    else {
        x2 = players[1].where().x;
        y2 = yLock;
    }

    // Load these vector2fs with the appropriate values
    sf::Vector2f trackP1(x1, y1),
                 trackP2(x2, y2);

	sf::View view1(trackP1, viewSize),
	         view2(trackP2, viewSize);

    std::vector<sf::View*> views;
    views.push_back(&view1);
    views.push_back(&view2);

    view1.zoom(0.875f);
    view2.zoom(0.875f);

    // Defines proportions for each player viewport
    // Parametres ( x-coordinate, y-coordinate, width, height )
    view1.setViewport(sf::FloatRect(-0.5f, 0.5f, 2.0f, 0.5f));
    view2.setViewport(sf::FloatRect(-0.5f, 0.0f, 2.0f, 0.5f));

    for (auto & view : views) {
        window.setView(*view);
	    for (auto drawable : drawables) {
		    drawable->draw(window);
	    }
    }
	window.display();
}


void fxx::directors::game::handle_event(sf::Event event) {
	if (event.type == sf::Event::Closed) {
		window.close();
	} else if (event.type == sf::Event::KeyPressed) {
		handle_key_press(event.key.code);
	} else if (event.type == sf::Event::KeyReleased) {
		handle_key_release(event.key.code);
	}
}


void fxx::directors::game::handle_key_press(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Z) {

		std::cout << "'Z' key pressed" << std::endl;
        std::cout << sf::Music::Playing << std::endl;
        if (jump_sound.getStatus() != sf::Music::Playing) {
			jump_sound.play();
        }
		players[0].jump();
	} else if (key == sf::Keyboard::M) {
		std::cout << "'M' key pressed" << std::endl;
		if (jump_sound.getStatus() != sf::Music::Playing) {
			jump_sound.play();
		}
		players[1].jump();
	}
}


void fxx::directors::game::handle_key_release(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Z) {
		std::cout << "'Z' key released" << std::endl;
		jump_sound.stop();
		players[0].cut_jump();
	} else if (key == sf::Keyboard::M) {
		std::cout << "'M' key released" << std::endl;
		jump_sound.stop();
		players[1].cut_jump();
	}
}

void fxx::directors::game::run_menu() {
	menu.draw(window);
	window.display();

    sf::Event evnt;
    while (window.pollEvent(evnt)) {
        switch (evnt.type)
        {
            case sf::Event::KeyReleased:

            switch (evnt.key.code)
            {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    menu.playMenuTone();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    menu.playMenuTone();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.getSelectedIdx())
                    {
                        case 0 :
                            if (menu.getState() == Menu::MAIN_MENU)
                            {
                                menu.playMenuTone();
                                menu_music.stop();
                                bg_music.play();
                                active_activity = activity::GAME;
								clock.restart();
                            }
                            if (menu.getState() == Menu::HOW_TO_PLAY || menu.getState() == Menu::SHOW_SCORES) {
                                menu.playMenuTone();
                                menu.makeMenu();
                            }
                            break;
                        case 1 :
                            if (menu.getState() == Menu::MAIN_MENU) {
                                menu.playMenuTone();
                                menu.goToHowToPlay();
                            }
                            else if (menu.getState() == Menu::HOW_TO_PLAY || menu.getState() == Menu::SHOW_SCORES)
                            {    
                                menu.playMenuTone();
                                active_activity = activity::GAME;
                                clock.restart();
                            }
                            break;
                        case 2:
                            menu.playMenuTone();
                            menu.displayScores();
                            break;
                        case 3 :
                            menu.playMenuTone();
                            window.close();
                            break;
                    }
                default:
                    ;
            }
            default:
                ;

        }
    }
}
