
#include "MSBoardTextView.h"
#include "iomanip"

using namespace std;

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) : board(board) {}

void MSBoardTextView::display() const {
    if (board.getGameState() != RUNNING) { return; }
    int fieldWidth = 5;
    cout << std::setw(fieldWidth) << "";
    for (int nCol = 0; nCol < board.getBoardWidth(); nCol++) {
        cout << std::setw(fieldWidth) << nCol;
    }
    cout << std::endl;


    for (int nRow = 0; nRow < board.getBoardWidth(); nRow++) {
        cout << std::setw(fieldWidth) << ::right << nRow;
        for (int nCol = 0; nCol < board.getBoardWidth(); nCol++) {
            cout << std::setw(fieldWidth - 2) << ::right
                 << "[" << board.getFieldInfo(nRow, nCol) << "]";
        }
        std::cout << std::endl;
    }
}


