#ifndef MSSFMLCONTROLLER_H
#define MSSFMLCONTROLLER_H

#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"

class MSSFMLController {
private:
    MinesweeperBoard &board;
    sf::RenderWindow &window;
    MSSFMLView &view;

public:
    MSSFMLController(MinesweeperBoard &board, sf::RenderWindow &window, MSSFMLView &view);

    void play();

};

#endif // MSSFMLCONTROLLER_H