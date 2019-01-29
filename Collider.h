//
// Created by Heather Hyunkyung Koo on 1/13/19.
//

#ifndef SFML_JUMPING_COLLIDER_H
#define SFML_JUMPING_COLLIDER_H
#include <SFML/Graphics.hpp>
#include <math.h>

class Collider {
public:
    Collider(sf::RectangleShape& body);

    void Move(float dx, float dy) { body.move(dx, dy);}

    bool CheckCollision(Collider& other, sf::Vector2f& direction, float push);
    sf::Vector2f GetPosition() { return body.getPosition(); }
    sf::Vector2f GetHalfSize() { return body.getSize()/2.0f;}

private:
    sf::RectangleShape& body;
};

Collider::Collider(sf::RectangleShape &body) : body(body)
{
}

bool Collider::CheckCollision(Collider &other, sf::Vector2f& direction, float push) {
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f) {
        push = std::min(std::max(push, 0.0f), 1.0f); // clamping between 0 and 1
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                Move(intersectX * (1.0f - push), 0.0f);
                other.Move(-intersectX * push, 0.0f);

                direction.x = 1.0f;
                direction.y = 0.0f;
            } else {
                Move(-intersectX * (1.0f - push), 0.0f);
                other.Move(intersectX * push, 0.0f);

                direction.x = -1.0f;
                direction.y = 0.0f;
            }
        } else {
            if (deltaY > 0.0f) {
                Move(0.0f, intersectY * (1.0f - push));
                other.Move(0.0f, -intersectY * push);

                direction.x = 0.0f;
                direction.y = 1.0f;
            } else {
                Move(0.0f, -intersectY * (1.0f - push));
                other.Move(0.0f, intersectY * push);

                direction.x = 0.0f;
                direction.y = -1.0f;
            }
        }
        return true;
    }

    return false;
}

#endif //SFML_JUMPING_COLLIDER_H
