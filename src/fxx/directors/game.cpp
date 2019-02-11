#include "fxx/directors/game.h"
#include <SFML/Window/Event.hpp>
#include <iostream>


fxx::directors::game::game() : window(sf::VideoMode(WIDTH, HEIGHT), TITLE) {
	active_activity = activity::GAME;
	players.emplace_back(0.0f, 0.0f);
	drawables.push_back(&players[0]);

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
	}
}


void fxx::directors::game::handle_key_press(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::LControl) {
		std::cout << "left control pressed" << std::endl;
	} else if (key == sf::Keyboard::RControl) {
		std::cout << "right control pressed" << std::endl;
	}
}
