//
// Created by egors on 07.05.2024.
//
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"


class rungame {
public:
    static void start(){
        sf::RenderWindow window(sf::VideoMode(600, 800), "Minesweeper",sf::Style::Titlebar | sf::Style::Close);



        Menu menu(window.getSize().x, window.getSize().y);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::MouseButtonPressed:
                        menu.handleMouseClick(event.mouseButton.x, event.mouseButton.y);
                        break;
                    default:
                        break;
                }
            }

            window.clear();
            menu.draw(window);
            window.display();

            if (menu.isOptionSelected()) {
                GameMode selectedMode = menu.getSelectedMode();
                MinesweeperBoard board(10, 10, selectedMode);
                MSSFMLView view(board);
                board.debug_display();
                MSSFMLController controller(board, window, view);
                controller.play();
                menu.reset();
            }
        }}
}
;
