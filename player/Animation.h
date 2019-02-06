//
// Created by Heather Hyunkyung Koo on 2/5/19.
//

#ifndef PLAYER_ANIMATION_H
#define PLAYER_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Animation {
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    //~Animation();

    void Update(int row, float deltaTime, bool faceRight);


public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

};


Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = (texture->getSize().x) / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::Update(int row, float deltaTime, bool faceRight) {
    currentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x) {
            currentImage.x = 0;
        }

    }
    if (faceRight) {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    } else {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);  //flip the image
    }

    uvRect.top = currentImage.y * uvRect.height;
}

#endif //PLAYER_ANIMATION_H
