#include "StdioBoardView.hpp"
#include <cstdio>

StdioBoardView::StdioBoardView(Board& _board, bool _isSilent): board(_board), isSilent(_isSilent), isLastMoveBad(false) {};

char StdioBoardView::signDisplayCharacter(Sign sign) const {
	switch(sign) {
		case EMPTY:
			return '.';
		case X:
			return 'X';
		case O:
			return 'O';
	}
	return '\0';
}

void StdioBoardView::boardPrint() const {
	printf("\n");
	for(size_t i = 0; i < board.getBoardSize(); i++) {
		for(size_t j = 0; j < board.getBoardSize(); j++) {
			printf("%c", signDisplayCharacter(board.getCell(i, j)));  
		}
		printf("\n");
	}
}

void StdioBoardView::currentMovePrint() const {
	printf("%c move: ", signDisplayCharacter(board.getCurrentMove()));
}

void StdioBoardView::gameResultPrint() const {
	switch(board.getState()) {
		case X_WIN:
			printf("X wins!\n");
			break;
		case O_WIN:
			printf("O wins!\n");
			break;
		case DRAW:
			printf("Draw.\n");
			break;
		default:
			break;
	}
}

void StdioBoardView::badMoveHandler(const int x, const int y) {
	if(!board.canMove(x, y)) {
		isLastMoveBad = true;
		printf("Bad move!\n");
	}
	else{
		isLastMoveBad = false;
	}
}


void StdioBoardView::doGameCycle() {
	do{
		if(!isSilent && !isLastMoveBad) {
			boardPrint();			
		}
		currentMovePrint();
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == -1 && y == -1) {
			return;
		}
		badMoveHandler(x, y);
		if(!isLastMoveBad) {
			board.move(x, y);
		}
	} while(board.getState() == GAME_IN_PROGRESS);
	boardPrint();
	gameResultPrint();
}
