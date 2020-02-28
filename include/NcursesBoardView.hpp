#pragma once
#include "ncurses.h"
#include "Board.hpp"

enum Color { COLOR_X = 1, COLOR_O, COLOR_DOT};

class NcursesBoardView {
private:
	Board& board;
	int cursorX, cursorY; //X: up -> down direction, Y: left -> right direction
	int moveInfoX, moveInfoY;
	const char* gameStateStrings[sizeState];
	const char* moveStrings[sizeSign];
public:
    NcursesBoardView(Board& _board);
	
    void doGameCycle();

private:
	void boardPrint() const;

	void currentStatePrint() const;

	void printMove() const;

	bool keyPressHandler();
};
