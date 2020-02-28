#include "Board.hpp"
#include <algorithm>

int** Board::boardCreate(const size_t size) {
	int** newBoard = new int* [size];
	int* buffer = new int [size * size];
	for(size_t i = 0; i < size; i++) {
		newBoard[i] = &buffer[i * size];
	}

	std::fill(buffer, buffer + size * size, EMPTY);
	return newBoard;
}

Board::Board(const size_t _boardSize, const size_t _stripSize): boardSize(_boardSize), stripSize(_stripSize), 
				countMarked(0), prevMove(X), currentMove(O) {
	board = boardCreate(_boardSize);
};

Board::~Board() {
	delete [] board[0];
	delete [] board;
}

bool Board::correctMove(const int x, const int y) const{
	return (0 <= x && x < (int)boardSize) && (0 <= y && y < (int)boardSize);
}

bool Board::canMove(const int x, const int y) const{
	return correctMove(x, y) && (board[x][y] == EMPTY);
}

void Board::move(const int x, const int y) {
	countMarked++;
	board[x][y] = currentMove;
	std::swap(currentMove, prevMove);
}

Sign Board::getCurrentMove() const {
	return currentMove;
}

Sign Board::getCell(const int x, const int y) const{
	return (Sign)board[x][y];
}

State Board::whoIsWinner() const {
	return prevMove == X ? X_WIN: O_WIN;
}

bool Board::checkStrip(const int x, const int y, const int dx, const int dy) const {
	bool haveStrip = false;
	for(size_t i = 0; correctMove(x + dx * (i + stripSize - 1), y + dy * (i + stripSize - 1)); i++) {
		int startX = x + i * dx;
		int startY = y + i * dy;
		bool filled = (board[startX][startY] != EMPTY);
		for(size_t j = 1; j < stripSize; j++) {
			filled &= (board[startX][startY] == board[startX + dx * j][startY + dy * j]);
		}
		haveStrip |= filled;
	}
	
	return haveStrip;
}


bool Board::checkWin() const{
	bool haveStrip = false;
	for(size_t i = 0; i < boardSize; i++) {
		haveStrip |= checkStrip(i, 0, 0, 1);
		haveStrip |= checkStrip(0, i, 1, 0);
		haveStrip |= checkStrip(i, 0, 1, 1);
		haveStrip |= checkStrip(0, i, 1, -1);
	}
	return haveStrip;
}

bool Board::checkEmpty() const {
	return countMarked < (int)(boardSize * boardSize);
}

State Board::getState() const {
	if (checkWin()) {
		return whoIsWinner();
	}
	else {
		return checkEmpty() ? GAME_IN_PROGRESS: DRAW;
	}
};

size_t Board::getBoardSize() const {
	return boardSize;
};

size_t Board::getStripSize() const {
	return stripSize;
};
