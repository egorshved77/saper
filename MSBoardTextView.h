//
// Created by c on 4/16/24.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView {
    MinesweeperBoard & board;
public:
    MSBoardTextView(MinesweeperBoard & board);
    void display()const;
};


#endif //SAPER_MSBOARDTEXTVIEW_H
