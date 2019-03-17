//Menu.h

#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Sound.hpp"

#define NUMBER_OF_ITEMS 4


namespace fxx {
    namespace directors {
        class Menu;
    }
}


class fxx::directors::Menu {
public:
    enum State {
        MAIN_MENU,
        HOW_TO_PLAY
    };
    
private:
    int                selectedIdx;
    sf::Font           font;
    sf::Text           menu[NUMBER_OF_ITEMS];
    sf::SoundBuffer    toneBuffer;
    sf::Sound          menuTone;
    const unsigned int width;
    const unsigned int height;
    State              state;
    
public:
    
    Menu(const unsigned int, const unsigned int);
    State getState() {return state;}
    void draw(sf::RenderWindow &window);
    void displayHowToPlay(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int getSelectedIdx();
    void goToHowToPlay(sf::RenderWindow &window);
    void makeMenu();
    void playMenuTone();
};

#endif /* Menu_h */
