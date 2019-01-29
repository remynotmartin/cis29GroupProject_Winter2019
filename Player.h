//
// Created by Heather Hyunkyung Koo on 1/7/19.
//

#ifndef WINDOW_TUTORIAL_PLAYER_H
#define WINDOW_TUTORIAL_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player {
public:
    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

    sf::Vector2f GetPosition() {return body.getPosition();}
    Collider GetCollider() { return Collider(body); }

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
};

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) :
        animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(100.0f, 150.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
}

void Player::Update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed * deltaTime;

    if (movement.x == 0.0f)
        row = 0;
    else {
        row = 1;
        if (movement.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}


void Player::Draw(sf::RenderWindow& window) {
    window.draw(body);
}
#endif //WINDOW_TUTORIAL_PLAYER_H
