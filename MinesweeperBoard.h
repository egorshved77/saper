#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

#include "Array2D.h"

struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode {
    DEBUG, EASY, NORMAL, HARD
};
enum GameState {
    RUNNING, FINISHED_WIN, FINISHED_LOSS
};

class MinesweeperBoard {
    int height; //rzeczywista wysokosc planszy
    int width; //rzeczywista szerokosc planszy
    Array2D<Field> board = Array2D<Field>(100, 100);

    void clearBoard();

public:
    MinesweeperBoard();

    void debug_display() const;

    MinesweeperBoard(int width, int height, GameMode mode);

    int getBoardWidth() const;

    int getBoardHeight() const;

    int getMineCount() const;

    int countMines(int row, int col) const;

    bool hasFlag(int row, int col) const;

    bool hasMine(int row, int col) const;


    void toggleFlag(int row, int col);

    void revealField(int row, int col);

    bool isRevealed(int row, int col) const;

    GameState getGameState() const;

    char getFieldInfo(int row, int col) const;

    bool isValid(int row, int col) const;

};


#endif //SAPER_MINESWEEPERBOARD_H
