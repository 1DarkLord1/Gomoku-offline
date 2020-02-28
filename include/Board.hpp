#pragma once
#include <stddef.h>

enum Sign { EMPTY, X, O };

static const int sizeSign = 3;

enum State { GAME_IN_PROGRESS, X_WIN, O_WIN, DRAW }; 

static const int sizeState = 4;

class Board {
private:
	size_t boardSize, stripSize;
	int countMarked;
	int** board;
	Sign prevMove, currentMove;

public:
	Board(const size_t _boardSize, const size_t _stripSize);

	~Board();
	
	bool correctMove(const int x, const int y) const;

	bool canMove(const int x, const int y) const;
	
	void move(const int x, const int y);

	State getState() const;
	
	size_t getBoardSize() const;

	size_t getStripSize() const;
	
	Sign getCurrentMove() const;
	
	Sign getCell(const int x, const int y) const;

	State whoIsWinner() const;
	
private:
	static int** boardCreate(const size_t size);

	bool checkStrip(const int x, const int y, const int dx, const int dy) const;
	
	bool checkEmpty() const;

	bool checkWin() const;
};
