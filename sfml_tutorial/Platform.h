//
// Created by Heather Hyunkyung Koo on 1/13/19.
//

#ifndef WINDOW_TUTORIAL_PLATFORM_H
#define WINDOW_TUTORIAL_PLATFORM_H

#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform {
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);

    void Draw(sf::RenderWindow& window);
    Collider GetCollider() {return Collider(body);}

private:
    sf::RectangleShape body;
};

Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setTexture(texture);
    body.setPosition(position);
}

void Platform::Draw(sf::RenderWindow &window) {
    window.draw(body);
}



#endif //WINDOW_TUTORIAL_PLATFORM_H
