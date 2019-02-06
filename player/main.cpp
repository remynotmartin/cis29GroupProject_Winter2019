#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "demo", sf::Style::Close | sf::Style::Resize);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("blues.png");
    Player player(&playerTexture, sf::Vector2u(6, 1), 0.1f, 100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        player.Update(deltaTime);

        window.clear(sf::Color(150, 150, 150));
        player.Draw(window);
        window.display();
    }


    return 0;
}
