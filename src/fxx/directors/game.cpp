#include "fxx/directors/game.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>


fxx::directors::game::game() : window(sf::VideoMode(WIDTH, HEIGHT), TITLE) {
	active_activity = activity::GAME;

	const float HEIGHT_IN_TILES = HEIGHT / TILE_WIDTH;
	const float WIDTH_IN_TILES = WIDTH / TILE_WIDTH;

	sf::Texture brick_texture;
	brick_texture.loadFromFile("share/textures/gutstiles.png");
	sf::Sprite brick_sprite;
	brick_sprite.setTexture(brick_texture);
	brick_sprite.setTextureRect(sf::IntRect(138, 36, 32, 32));

	for (int j = 0; j < 256; j++) {
		bricks.emplace_back(j * TILE_WIDTH, (HEIGHT_IN_TILES - 1) * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH, brick_sprite);
	}

	for (int j = 0; j < 256; j++) {
		actors.push_back(&bricks[j]);
		collidables.push_back(&bricks[j]);
		drawables.push_back(&bricks[j]);
	}

	sf::Texture player_texture;
	player_texture.loadFromFile("share/textures/blues.png");
	sf::Sprite player_sprite;
	player_sprite.setTexture(player_texture);
	player_sprite.setTextureRect(sf::IntRect(204 + 44, 22, -44, 48));

	players.emplace_back(0.0f, (HEIGHT_IN_TILES - 3) * TILE_WIDTH, 48.0f, 48.0f, player_sprite);
	actors.push_back(&players[0]);
	collidables.push_back(&players[0]);
	drawables.push_back(&players[0]);
	mobiles.push_back(&players[0]);

	while (window.isOpen()) {
		if (active_activity == activity::TITLE) {

		} else if (active_activity == activity::GAME) {
			direct();
		} else if (active_activity == activity::PAUSE) {

		} else if (active_activity == activity::GAME_OVER) {

		}
	}
}


void fxx::directors::game::direct() {
	const float DRAW_INTERVAL = 1.0f / FRAME_RATE;
	sf::Event event;

	float delta_draw_time = 0;
	float delta_direct_time = 0;

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
			if (a != b) {
				a->collide(*b);
			}
		}
	}
}


void fxx::directors::game::draw() {
	window.clear(sf::Color::White);

	for (auto drawable : drawables) {
		drawable->draw(window);
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
	if (key == sf::Keyboard::LControl) {
		std::cout << "left control pressed" << std::endl;
		players[0].jump();
	} else if (key == sf::Keyboard::RControl) {
		std::cout << "right control pressed" << std::endl;
	}
}


void fxx::directors::game::handle_key_release(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::LControl) {
		std::cout << "left control released" << std::endl;
		players[0].cut_jump();
	} else if (key == sf::Keyboard::RControl) {
		std::cout << "right control released" << std::endl;
	}
}
