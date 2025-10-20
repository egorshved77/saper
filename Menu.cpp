#include "Menu.h"

Menu::Menu(int screenWidth, int screenHeight) : optionSelected(false), selectedMode(GameMode::EASY) {


    // Ustawienia przycisków

    if (!font.loadFromFile("C:/Users/egors/programowanie obiektowe/saper1/saper_yahor_shved/arial_bolditalicmt.ttf")) {
        // Obsługa błędu ładowania czcionki
        return;
    }
    hellotext.setFont(font);
    hellotext.setCharacterSize(50);
    hellotext.setFillColor(sf::Color::Black);
    hellotext.setString("MINESWEEPER");
    hellotext.setPosition(screenWidth/3-70, 20);

    level.setFont(font);
    level.setCharacterSize(25);
    level.setFillColor(sf::Color::Black);
    level.setString("select mode");
    level.setPosition(30, 150);



    easyButton.setSize(sf::Vector2f(200, 50));
    easyButton.setPosition(10, 200);
    easyButton.setFillColor(sf::Color::Green);

    easyText.setFont(font);
    easyText.setCharacterSize(24);
    easyText.setFillColor(sf::Color::White);
    easyText.setString("Easy");
    easyText.setPosition(70, 210);


    normalButton.setSize(sf::Vector2f(200, 50));
    normalButton.setPosition(10, 300);
    normalButton.setFillColor(sf::Color(0, 0, 139));


    normalText.setFont(font);
    normalText.setCharacterSize(24);
    normalText.setFillColor(sf::Color::White);
    normalText.setString("Normal");
    normalText.setPosition(70, 310);


    hardButton.setSize(sf::Vector2f(200, 50));
    hardButton.setPosition(10, 400);
    hardButton.setFillColor(sf::Color::Red);

    hardText.setFont(font);
    hardText.setCharacterSize(24);
    hardText.setFillColor(sf::Color::White);
    hardText.setString("Hard");
    hardText.setPosition( 70,   410);
}

void Menu::handleMouseClick(int mouseX, int mouseY) {
    if (easyButton.getGlobalBounds().contains(mouseX, mouseY)) {
        optionSelected = true;
        selectedMode = GameMode::EASY;
    } else if (normalButton.getGlobalBounds().contains(mouseX, mouseY)) {
        optionSelected = true;
        selectedMode = GameMode::NORMAL;
    } else if (hardButton.getGlobalBounds().contains(mouseX, mouseY)) {
        optionSelected = true;
        selectedMode = GameMode::HARD;
    }
}

void Menu::draw(sf::RenderWindow& window) {

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/tapety_pwr_en_3.jpg"))
    {
        return;
    }
    sf::Sprite background(backgroundTexture);
    window.draw(background);
    window.draw(hellotext);
    window.draw(level);
    //window.clear(sf::Color(0,0,255));
    window.draw(easyButton);
    window.draw(easyText);

    window.draw(normalButton);
    window.draw(normalText);

    window.draw(hardButton);
    window.draw(hardText);

}

bool Menu::isOptionSelected() const {
    return optionSelected;
}

GameMode Menu::getSelectedMode() const {
    return selectedMode;
}

void Menu::reset() {
    optionSelected = false;
}
