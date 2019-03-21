//menu.cpp

#include "fxx/directors/Menu.h"
const char* const blockyFont = "share/resources/04b03.ttf";


#include <iostream>
#include <fstream>
#include <string>
//constructor
fxx::directors::Menu::Menu(const unsigned int w, const unsigned int h)
: width(w), height(h) {
    
    try {
        if (!font.loadFromFile(blockyFont))
            throw "Failed to load a font file!";
        }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
        std::cerr << "Path to file is: " << blockyFont << std::endl;
        std::cerr << "Please check path and filename." << std::endl;
    }
    toneBuffer.loadFromFile("share/soundEffects/menuBeep.ogg");
    menuTone.setBuffer(toneBuffer);
    selectedIdx = 0;

}


//draw menu
void fxx::directors::Menu::draw(sf::RenderWindow &window) {

    window.clear(sf::Color(0, 0, 0));
    if (state == MAIN_MENU) {
        for (int i = 0; i < NUMBER_OF_ITEMS ; ++i) {
            window.draw(menu[i]);
        }
    } else if (state == HOW_TO_PLAY || state == SHOW_SCORES) {
        window.draw(text);
        window.draw(menu[0]);
        
    } else if (state == GET_NAME) {
        window.draw(text);
        window.draw(textname);
        window.draw(textname2);
        window.draw(menu[0]);
    }
        
}


//going up
void fxx::directors::Menu::MoveUp() {

    if (selectedIdx - 1 >= 0) {
        menu[selectedIdx].setFillColor(sf::Color::White);
        selectedIdx--;
        menu[selectedIdx].setFillColor(sf::Color::Red);
    }
}

//going down
void fxx::directors::Menu::MoveDown() {
    menu[selectedIdx].setFillColor(sf::Color::White);
    if (state == MAIN_MENU)
        selectedIdx = (selectedIdx + 1) % NUMBER_OF_ITEMS;
    else
        selectedIdx = 0;

    menu[selectedIdx].setFillColor(sf::Color::Red);
}

//return selected index
int fxx::directors::Menu::getSelectedIdx() {
    return selectedIdx;
}

// make menu to display
void fxx::directors::Menu::makeMenu() {
    state = MAIN_MENU;
    menu[0].setFont(font);
    menu[0].setCharacterSize(40);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f((width/2) - (menu[0].getLocalBounds().width / 2) , height / (NUMBER_OF_ITEMS + 1) * 1));
    menu[1].setFont(font);
    menu[1].setCharacterSize(40);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("How to play");
    menu[1].setPosition(sf::Vector2f((width/2) - (menu[1].getLocalBounds().width / 2), height / (NUMBER_OF_ITEMS + 1) * 2));
    menu[2].setFont(font);
    menu[2].setCharacterSize(40);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Scores");
    menu[2].setPosition(sf::Vector2f((width/2) - (menu[2].getLocalBounds().width / 2), height / (NUMBER_OF_ITEMS + 1) * 3));
    menu[3].setFont(font);
    menu[3].setCharacterSize(40);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Input Name");
    menu[3].setPosition(sf::Vector2f((width/2) - (menu[3].getLocalBounds().width / 2), height / (NUMBER_OF_ITEMS + 1) * 4));
    menu[4].setFont(font);
    menu[4].setCharacterSize(40);
    menu[4].setFillColor(sf::Color::White);
    menu[4].setString("Exit");
    menu[4].setPosition(sf::Vector2f((width/2) - (menu[4].getLocalBounds().width / 2), height / (NUMBER_OF_ITEMS + 1) * 5));
}

//ask player name before game starts
void fxx::directors::Menu::askName(std::string p1name, std::string p2name) {
    state = GET_NAME;
    //text
    text.setFont(font);
    text.setString("Enter your name: ");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(0.0f  , 0.0f));
    
    textname.setFont(font);
    textname.setString(p1name);
    textname.setCharacterSize(30);
    textname.setFillColor(sf::Color::Green);
    textname.setPosition(20, 40);

    textname2.setFont(font);
    textname2.setString(p2name);
    textname2.setCharacterSize(30);
    textname2.setFillColor(sf::Color::Blue);
    textname2.setPosition(20, 80);

    
    menu[0].setFont(font);
    menu[0].setCharacterSize(40);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Game Start");
    menu[0].setPosition(sf::Vector2f((width/2) - (menu[0].getLocalBounds().width / 2) , height / 10 * 8 ));
}


// display instruction in how to play
void fxx::directors::Menu::goToHowToPlay() {
    
    state = HOW_TO_PLAY;
    //text
    std::string instruction;
    instruction = getInstruction();
    text.setFont(font);
    text.setString(instruction.c_str());
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(0.0f, 0.0f);
    
    //menu
    menu[0].setFont(font);
    menu[0].setCharacterSize(40);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Go Back To Main");
    menu[0].setPosition(sf::Vector2f((width/2) - (menu[0].getLocalBounds().width / 2) , height / 10 * 8 ));

}

// read a instruction to create one long string to display
std::string fxx::directors::Menu::getInstruction() {
    
    std::ifstream fin("share/resources/sample_instruction.txt");
    std::string text, line;
    if (!fin) {
        std::cout << "error opening instruction file in print instruction()\n";
        exit(101);
    }
    
    while (getline(fin, line)) {
        text += line += '\n';
    }
    
    fin.close();
    return text;
}

void fxx::directors::Menu::displayScores() {
    
    state = SHOW_SCORES;
    //text
    std::string scores ;
    scores = getScores();
    text.setFont(font);
    text.setString(scores.c_str());
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(0.0f , 0.0f));
    
    // menu
    menu[0].setFont(font);
    menu[0].setCharacterSize(40);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Go Back To Main");
    menu[0].setPosition(sf::Vector2f((width/2) - (menu[0].getLocalBounds().width / 2) , height / 10 * 8 ));

}

std::string fxx::directors::Menu::getScores() {
    
    std::ifstream fin("share/resources/sample_scores.txt");
    std::string text, line;
    if (!fin) {
        std::cout << "error opening scores.txt in getScores()\n";
        exit(102);
    }
    while (getline(fin, line)) {
        text += line += '\n';
    }
    
    fin.close();
    return text;
    
}

void fxx::directors::Menu::playMenuTone() {
    menuTone.play();
}
