//menu.cpp

#include "fxx/directors/Menu.h"
#include <iostream>

//constructor
fxx::directors::Menu::Menu(const unsigned int w, const unsigned int h) : width(w), height(h)
{
    if (!font.loadFromFile("share/resources/arial.ttf"))
    {
        throw "Failed to load a font file\n";
    }
    selectedIdx = 0;

}


//draw menu
void fxx::directors::Menu::draw(sf::RenderWindow &window) {

    window.clear(sf::Color(0, 0, 0));
    if (state == MAIN_MENU) {
        std::cout << "MAIN_MENU\n";
        for (int i = 0; i < NUMBER_OF_ITEMS ; ++i) {
            window.draw(menu[i]);
        }
    } else if (state == HOW_TO_PLAY) {

        std::cout << "HOW_TO_PLAY\n";

        for (int i = 0; i < 2 ; ++i) {
            window.draw(menu[i]);
        }
    }
}

void fxx::directors::Menu::displayHowToPlay(sf::RenderWindow &window)
{
    sf::Text text;
    text.setFont(font);
    sf::Text credits("Made by: name1, name2, name3, name4", font, 20);
    text.setString("How to play the game page\nThis will be updated later\n");
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
}


//going up
void fxx::directors::Menu::MoveUp() {

    if (selectedIdx - 1 >= 0) {
        menu[selectedIdx].setColor(sf::Color::White);
        selectedIdx--;
        menu[selectedIdx].setColor(sf::Color::Red);
    }
}

//going down
void fxx::directors::Menu::MoveDown() {
    menu[selectedIdx].setColor(sf::Color::White);
    selectedIdx = (selectedIdx + 1) % NUMBER_OF_ITEMS;
    menu[selectedIdx].setColor(sf::Color::Red);
}

//return selected index
int fxx::directors::Menu::getSelectedIdx() {
    return selectedIdx;
}

void fxx::directors::Menu::makeMenu()
{
    state = MAIN_MENU;
    menu[0].setFont(font);
    menu[0].setCharacterSize(40);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f((width/2) - (menu[0].getLocalBounds().width / 2) , height / (NUMBER_OF_ITEMS + 1) * 1));
    menu[1].setFont(font);
    menu[1].setCharacterSize(40);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("How to play");
    menu[1].setPosition(sf::Vector2f((width/2) - (menu[1].getLocalBounds().width / 2), height / (NUMBER_OF_ITEMS + 1) * 2));
    menu[2].setFont(font);
    menu[2].setCharacterSize(40);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Scores");
    menu[2].setPosition(sf::Vector2f((width/2) - (menu[2].getLocalBounds().width / 2), height / (NUMBER_OF_ITEMS + 1) * 3));
    menu[3].setFont(font);
    menu[3].setCharacterSize(40);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f((width/2) - (menu[3].getLocalBounds().width / 2), height / (NUMBER_OF_ITEMS + 1) * 4));
}

void fxx::directors::Menu::goToHowToPlay(sf::RenderWindow &window) {
    state = HOW_TO_PLAY;
    sf::Text text;
    text.setFont(font);
    text.setString("How to play the game page\nThis will be updated later\n");
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    window.draw(text);

    menu[0].setFont(font);
    menu[0].setCharacterSize(40);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("go back to main");
    menu[0].setPosition(sf::Vector2f((width/2) - (menu[0].getLocalBounds().width / 2) , height / (NUMBER_OF_ITEMS + 1) * 1));
    menu[1].setFont(font);
    menu[1].setCharacterSize(40);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("start the game");
    menu[1].setPosition(sf::Vector2f((width/2) - (menu[1].getLocalBounds().width / 2) , height / (NUMBER_OF_ITEMS + 1) * 2));
}
