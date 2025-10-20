#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class Menu {
private:
    sf::RectangleShape easyButton;
    sf::RectangleShape normalButton;
    sf::RectangleShape hardButton;
    sf::Font font;
    sf::Text easyText;
    sf::Text normalText;
    sf::Text hardText;
    sf::Text hellotext;
    sf::Text level;
    bool optionSelected;
    GameMode selectedMode;

public:
    Menu(int screenWidth, int screenHeight);
    void handleMouseClick(int mouseX, int mouseY);
    void draw(sf::RenderWindow& window);
    bool isOptionSelected() const;
    GameMode getSelectedMode() const;
    void reset();
};

#endif // MENU_H
