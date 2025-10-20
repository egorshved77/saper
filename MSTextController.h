//
// Created by c on 4/16/24.
//
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "iostream"


#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H

class MSTextController {
    MinesweeperBoard &board;
    MSBoardTextView &view;
public:
    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);

    void play() const;
};

#endif //SAPER_MSTEXTCONTROLLER_H
