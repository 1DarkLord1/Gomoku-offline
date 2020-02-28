#pragma once
#include "Board.hpp"

class StdioBoardView {
private:
	Board& board;
	bool isSilent;
	bool isLastMoveBad;

public:
    StdioBoardView(Board& _board, bool _isSilent);

    void doGameCycle();

private:
	char signDisplayCharacter(Sign sign) const; 

	void boardPrint() const;
	
	void currentMovePrint() const;
	
	void badMoveHandler(const int x, const int y);
	
	void gameResultPrint() const;
};
