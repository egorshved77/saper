#include "MinesweeperBoard.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

MinesweeperBoard::MinesweeperBoard() {
    width = 7;
    height = 5;
    board.resize(height, width);
    clearBoard();
    board[0][0] = {true, false, false};
    board[1][1] = {false, false, true};
    board[0][2] = {true, true, false};
}

void MinesweeperBoard::clearBoard() {
    for (int nRow = 0; nRow < height; nRow++) {
        for (int nCol = 0; nCol < width; nCol++) {
            board[nRow][nCol] = {false, false, false};
        }
    }
}

void MinesweeperBoard::debug_display() const {
    int fieldWidth = 6;

    //std::cout << std::setw(fieldWidth) << " ";
    for (int nCol = 0; nCol < width; nCol++) {
        std::cout << std::setw(fieldWidth) << nCol;
    }
    std::cout << std::endl;

    for (int nRow = 0; nRow < height; nRow++) {
        std::cout << std::setw(2) << nRow << " ";
        for (int nCol = 0; nCol < width; nCol++) {
            std::cout << "[";
            if (board[nRow][nCol].hasMine == 1) {
                std::cout << "M";
            } else { std::cout << "."; }

            if (board[nRow][nCol].isRevealed == 1) {
                std::cout << "o";
            } else { std::cout << "."; }

            if (board[nRow][nCol].hasFlag == 1) {
                std::cout << "F";
            } else { std::cout << "."; }
            std::cout << "] ";
        }
        std::cout << std::endl;
    }

}

MinesweeperBoard::MinesweeperBoard(int a, int b, GameMode mode) {
    height = a;
    width = b;
    board.resize(height, width);
    clearBoard();
    srand(time(NULL));
    switch (mode) {
        case DEBUG:
            for (int nCol = 0; nCol < width; nCol++) {
                board[0][nCol] = {true, false, false};
            }

            for (int nRow = 0; nRow < height; nRow++) {
                if (nRow % 2 == 0) {
                    board[nRow][0] = {true, false, false};
                }
            }

            for (int nRow = 0; nRow < height; nRow++) {
                for (int nCol = 0; nCol < width; nCol++) {
                    if (nRow == nCol) { board[nRow][nCol] = {true, false, false}; }
                }
            }
            break;
        case EASY:
            int measy;
            measy = ceil(width * height * 0.1);
            while (measy != 0) {
                int nCol = rand() % width;
                int nRow = rand() % height;
                if (board[nRow][nCol].hasMine == 0) {
                    board[nRow][nCol].hasMine = 1;
                    measy--;
                }
            }
            break;

        case NORMAL:
            int mnormal;
            mnormal = ceil(width * height * 0.2);
            while (mnormal != 0) {
                int nCol = rand() % width;
                int nRow = rand() % height;
                if (board[nRow][nCol].hasMine == 0) {
                    board[nRow][nCol].hasMine = 1;
                    mnormal--;
                }
            }
            break;
        case HARD:
            int mhard;
            mhard = ceil(width * height * 0.3);
            while (mhard != 0) {
                int nCol = rand() % width;
                int nRow = rand() % height;
                if (board[nRow][nCol].hasMine == 0) {
                    board[nRow][nCol].hasMine = 1;
                    mhard--;
                }
            }
            break;
    }
}

int MinesweeperBoard::getBoardWidth() const {
    return width;
}

int MinesweeperBoard::getBoardHeight() const {
    return height;
}

int MinesweeperBoard::getMineCount() const {
    int mine = 0;

    for (int nRow = 0; nRow < height; nRow++) {
        for (int nCol = 0; nCol < width; nCol++) {
            if (board[nRow][nCol].hasMine) { mine++; }
        }
    }
    return mine;
}

bool MinesweeperBoard::isValid(int Nrow, int Ncol) const {
    return ((Nrow >= 0) && (Nrow < height) && (Ncol >= 0) && (Ncol < width));
}

int MinesweeperBoard::countMines(int row, int col) const {
    int sum_mine = 0;

    if (!isValid(row, col) || !board[row][col].isRevealed) {
        return -1;
    }

    for (int Nrow = row - 1; Nrow <= row + 1; Nrow++) {
        for (int Ncol = col - 1; Ncol <= col + 1; Ncol++) {
            if (isValid(Nrow, Ncol)) {
                if (board[Nrow][Ncol].hasMine) sum_mine++;
            }
        }
    }
    return sum_mine;
}

bool MinesweeperBoard::hasFlag(int row, int col) const {
    if (!isValid(row, col) || board[row][col].isRevealed || !board[row][col].hasFlag) return false;
    return (board[row][col].hasFlag);
}

bool MinesweeperBoard::hasMine(int row, int col) const {
    if (!isValid(row, col)) return false;
    return (board[row][col].hasMine);
}

void MinesweeperBoard::toggleFlag(int row, int col) {
    if (!isValid(row, col) || board[row][col].isRevealed ) {
        return;
    }

    board[row][col].hasFlag = !board[row][col].hasFlag; // Przełącz flagę na przeciwną wartość
}

bool MinesweeperBoard::isRevealed(int row, int col) const {
    if (isValid(row, col)) {
        return (board[row][col].isRevealed);
    }
    return false;
}


void MinesweeperBoard::revealField(int row, int col) {


    if (board[row][col].isRevealed || board[row][col].hasFlag || !isValid(row, col)) {
        return;
    }

    // Jezeli pole ma mine
    if (board[row][col].hasMine) {
        //Sprawdza czy to jest pierwsy ruch gracza
        bool firstPlayerAction = true;
        for (int nCol = 0; firstPlayerAction && (nCol < width); nCol++) {
            for (int nRow = 0; nRow < height; nRow++) {
                if (isRevealed(nRow, nCol)) firstPlayerAction = 0;
            }
        }

        if (firstPlayerAction) {
            bool newmine = 1;
            board[row][col].hasMine = 0;
            while (newmine) {
                int nCol = rand() % width;
                int nRow = rand() % height;
                if ((board[nRow][nCol].hasMine == 0) && (nRow != row) &&
                    (nCol != col)) { //sprawdza czy może zaminować pole
                    board[nRow][nCol].hasMine = 1;
                    newmine = 0; //
                }
            }
            board[row][col].isRevealed = true; // Reveal the field

        }
    }
    // jezeli nie ma miny -  otwiera
    board[row][col].isRevealed = true;

}


GameState MinesweeperBoard::getGameState() const {
    bool win = 1;
    for (int nCol = 0; nCol < width; nCol++) {
        for (int nRow = 0; nRow < height; nRow++) {
            if (getFieldInfo(nRow, nCol) == 'x')return FINISHED_LOSS;
            if (!isRevealed(nRow, nCol) && !hasMine(nRow, nCol)) win = 0;
        }
    }
    if (win)return FINISHED_WIN;
    return RUNNING;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const {
    if (!isValid(row, col)) {
        return '#'; // Outside board
    }

    if (!board[row][col].isRevealed) {
        if (board[row][col].hasFlag) {
            return 'F';
        } else {
            return '_';
        }
    }

    if (board[row][col].isRevealed && board[row][col].hasMine) {
        return 'x';
    }

    int minesAround = countMines(row, col);
    if (board[row][col].isRevealed && minesAround == 0) {
        return ' ';
    } else {
        return minesAround + '0';
    }
}

