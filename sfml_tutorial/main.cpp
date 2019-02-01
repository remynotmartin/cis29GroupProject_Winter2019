#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Collider.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    //sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
    //player.setFillColor(sf::Color::Green);
    //player.setOrigin(50.0f, 50.0f);
    //player.setPosition(206.0f, 206.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("tux_from_linux.png");
    //player.setTexture(&playerTexture);

    //Animation animation(&playerTexture, sf::Vector2u(3,9), 0.3f);
    Player player(&playerTexture, sf::Vector2u(3,9), 0.3f, 100.0f);

    Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
    Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

    float deltaTime = 0.0f;
    sf::Clock clock;
    /*
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 3;
    textureSize.y /= 9;

    player.setTextureRect(sf::IntRect(textureSize.x*2, textureSize.y*8, textureSize.x, textureSize.y));
    */
    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;

        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    ResizeView(window, view);
                    //std::cout << "New window width: " << evnt.size.width << " New window height: " << evnt.size.height << std::endl;
                    break;
                /*
                case sf::Event::TextEntered:
                    if (evnt.text.unicode < 128) {
                        printf("%c", evnt.text.unicode);
                    }*/
            }
        }
        /*
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); //relative pos to the window not screen
            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
        }*/

        /*
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            player.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            player.move(0.0f, 0.1f);
        }*/

        //animation.Update(0, deltaTime, false);
        //player.setTextureRect(animation.uvRect);
        Collider playerCollRect = player.GetCollider();
        player.Update(deltaTime);


        platform1.GetCollider().CheckCollision(playerCollRect, 0.5f);
        platform2.GetCollider().CheckCollision(playerCollRect, 1.0f);

        view.setCenter(player.GetPosition()); // call this after player.Update()
        window.clear(sf::Color(150, 150, 150));

        //window.draw(player);
        window.setView(view);
        player.Draw(window);
        platform1.Draw(window);
        platform2.Draw(window);
        window.display();
    }
    return 0;
}