//Menu.h
#ifndef Menu_h
#define Menu_h

#include <iostream>
#include <string>
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Graphics.hpp"

#define NUMBER_OF_ITEMS 5


namespace fxx {
    namespace directors {
        class Menu;
    }
}


class fxx::directors::Menu {
public:
    enum State {
        MAIN_MENU,
        HOW_TO_PLAY,
        SHOW_SCORES,
        GET_NAME
    };
    
private:
    int                selectedIdx;
    sf::Font           font;
    sf::Text           text;
    sf::SoundBuffer    toneBuffer;
    sf::Sound          menuTone;
    sf::Text           menu[NUMBER_OF_ITEMS];
    const unsigned int width;
    const unsigned int height;
    State              state;

    
public:
    
    Menu(const unsigned int, const unsigned int);
    State getState() {return state;}
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int getSelectedIdx();
    void goToHowToPlay();
    void makeMenu() ;
    void playMenuTone();
    void displayScores();
    void askName();
    std::string getInstruction();
    std::string getScores();
};

#endif /* Menu_h */
