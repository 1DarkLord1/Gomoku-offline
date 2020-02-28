#include "ncurses.h"
#include "Board.hpp"
#include "NcursesBoardView.hpp"
#include "assert.h"

NcursesBoardView::NcursesBoardView(Board& _board): board(_board), cursorX(0), cursorY(0), moveInfoX(_board.getBoardSize()),
													moveInfoY(0) {
	gameStateStrings[X_WIN] = "X wins!";
	gameStateStrings[O_WIN] = "O wins!";
	gameStateStrings[DRAW] = "Draw.";
	moveStrings[X] = "X move.";
	moveStrings[O] = "O move.";
};

void NcursesBoardView::boardPrint() const {
	attron(COLOR_PAIR(COLOR_DOT));
	for(size_t i = 0; i < board.getBoardSize(); i++) {
		for(size_t j = 0; j < board.getBoardSize(); j++) {
			mvaddch(i, j, '.');
		}
	}
	refresh();
	attroff(COLOR_PAIR(COLOR_DOT));
	move(cursorX, cursorY);
}

void NcursesBoardView::currentStatePrint() const {
	Sign needMove = (board.getState() == GAME_IN_PROGRESS ? board.getCurrentMove(): (board.getCurrentMove() == X ? O: X));
	attron(COLOR_PAIR(needMove));
	move(board.getBoardSize(), 0);
	deleteln();
	addstr(board.getState() == GAME_IN_PROGRESS ? moveStrings[needMove]: gameStateStrings[board.getState()]);
	refresh();
	attroff(COLOR_PAIR(needMove));
	move(cursorX, cursorY);	
}
void NcursesBoardView::printMove() const {
	attron(COLOR_PAIR(board.getCurrentMove()));
	mvaddch(cursorX, cursorY, (board.getCurrentMove() == X ? 'X': 'O'));
	attroff(COLOR_PAIR(board.getCurrentMove()));
	refresh();
}

bool NcursesBoardView::keyPressHandler() {
	bool isCorrectMove = false;
	int key;
	while(!isCorrectMove) {
		move(cursorX, cursorY);
		key = getch();
		switch(key) {
			case 'x':
				return false;
			case ' ':
				if(board.getState() == GAME_IN_PROGRESS && board.canMove(cursorX, cursorY)) {
					isCorrectMove = true;
				}
				break;
			case KEY_LEFT:
				if(board.correctMove(cursorX, cursorY - 1)) {
					cursorY--;
				}
				break;
			case KEY_RIGHT:
				if(board.correctMove(cursorX, cursorY + 1)) {
					cursorY++;
				}
				break;
			case KEY_UP:
				if(board.correctMove(cursorX - 1, cursorY)) {
					cursorX--;
				}
				break;
			case KEY_DOWN:
				if(board.correctMove(cursorX + 1, cursorY)) {
					cursorX++;
				}
				break;
		}
	}
	return true;
}

void NcursesBoardView::doGameCycle() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(COLOR_X, COLOR_RED, COLOR_BLUE);
	init_pair(COLOR_O, COLOR_GREEN, COLOR_BLUE);
	init_pair(COLOR_DOT, COLOR_WHITE, COLOR_BLUE);
	boardPrint();
	do{
		currentStatePrint();
		if(!keyPressHandler()) {
			endwin();
			return;
		}
		printMove();
		board.move(cursorX, cursorY);
		
	} while(board.getState() == GAME_IN_PROGRESS);
	currentStatePrint();
	mvaddstr(board.getBoardSize() + 1, 0, "Press x to exit");
	refresh();
	keyPressHandler();
	endwin();
}
