#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include "iostream"

using namespace std;

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : board(board), view(view) {}

void MSTextController::play() const {


    while (true) {
        view.display();
        std::cout << "Enter coordinates (r x y) to reveal a field or (f x y) to toggle flag: ";
        char action;
        int x, y;
        std::cin >> action >> x >> y;
        if (action == 'r') {
            if (!board.isValid(x, y)) {
                std::cout << "Invalid coordinates. Please try again." << std::endl;
                continue;
            }
            board.revealField(x,y);
            if (board.hasFlag(x, y)) {
                std::cout << "Cannot reveal field with flag. Please toggle the flag first." << std::endl;
            } else if (board.hasMine(x, y)) {

                std::cout << "You hit a mine! Game over." << std::endl;
                view.display();

                break;
            } else {
                if (board.getGameState() == FINISHED_WIN) {
                    std::cout << "Congratulations! You've cleared the minefield." << std::endl;
                    view.display();
                    break;
                }
            }
        } else if (action == 'f') {
            if (x < 0 || x >= board.getBoardWidth() || y < 0 || y >= board.getBoardHeight()) {
                std::cout << "Invalid coordinates. Please try again." << std::endl;
                continue;
            }

            board.toggleFlag(x, y);
        } else {
            std::cout << "Invalid action. Please try again." << std::endl;
        }
    }
}
