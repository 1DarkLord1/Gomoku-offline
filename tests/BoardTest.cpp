#include <cstddef>
#include "Board.hpp"
#include "BoardTest.hpp"

void BoardTest::testCanMove_0_0() {
	Board b(10, 5);
	DO_CHECK(b.canMove(0, 0) == true);
}

void BoardTest::testCanMove_5_5() {
	Board b(10, 5);
	DO_CHECK(b.canMove(5, 5) == true);
}

void BoardTest::testCanMove_1_2() {
	Board b(10, 5);
	DO_CHECK(b.canMove(1, 2) == true);
}

void BoardTest::testMove_0_0() {
	Board b(10, 5);
	b.move(0, 0);
	DO_CHECK(b.canMove(0, 0) == false);
}
	
void BoardTest::testMove_9_9() {
	Board b(10, 5);
	b.move(9, 9);
	DO_CHECK(b.canMove(9, 9) == false);
}
	
void BoardTest::testMove_1_5() {
	Board b(10, 5);
	b.move(1, 5);
	DO_CHECK(b.canMove(1, 5) == false);
}
	
void BoardTest::testGetState_col_O_WIN() {
	Board b(10, 5);
	for(size_t i = 0; i + 1 < b.getStripSize(); i++) {
		for(size_t j = 0; j < b.getBoardSize(); j++) {
			b.move(i, j);
		}
	}
	b.move(b.getStripSize() - 1, 0);
	DO_CHECK(b.getState() == O_WIN);
}
	
void BoardTest::testGetState_diag_X_WIN() {
	Board b(10, 5);
	for(size_t i = 0; i + 1 < b.getStripSize(); i++) {
		b.move(i, i);
		b.move(i, b.getBoardSize() - i - 1);
	}
	b.move(9, 9);
	b.move(b.getStripSize() - 1, b.getBoardSize() - b.getStripSize());
	DO_CHECK(b.getState() == X_WIN);
}
	
void BoardTest::testGetState_GAME_IN_PROGRESS() {
	Board b(10, 5);
	b.move(1, 0);
	b.move(7, 8);
	b.move(1, 2);
	b.move(3, 3);
	DO_CHECK(b.getState() == GAME_IN_PROGRESS);
}
	
void BoardTest::testWhoIsWinner_afterZeroMoves_X_WIN() {
	Board b(10, 5);
	DO_CHECK(b.whoIsWinner() == X_WIN);
}
	
void BoardTest::testWhoIsWinner_afterOneMove_O_WIN() {
	Board b(10, 5);
	b.move(1, 1);
	DO_CHECK(b.whoIsWinner() == O_WIN);
}
	
void BoardTest::testWhoIsWinner_afterTwoMoves_X_WIN() {
	Board b(10, 5);
	b.move(9, 8);
	b.move(6, 7);
	DO_CHECK(b.whoIsWinner() == X_WIN);
}

void BoardTest::testGetBoardSize_10() {
	Board b(10, 5);
	DO_CHECK(b.getBoardSize() == 10);
}
	
void BoardTest::testGetBoardSize_3() {
	Board b(3, 3);
	DO_CHECK(b.getBoardSize() == 3);
}
	
void BoardTest::testGetBoardSize_4() {
	Board b(4, 2);
	DO_CHECK(b.getBoardSize() == 4);
}

void BoardTest::testGetStripSize_5() {
	Board b(10, 5);
	DO_CHECK(b.getStripSize() == 5);
}
	
void BoardTest::testGetStripSize_3() {
	Board b(10, 3);
	DO_CHECK(b.getStripSize() == 3);
}
	
void BoardTest::testGetStripSize_6() {
	Board b(12, 6);
	DO_CHECK(b.getStripSize() == 6);
}
	
void BoardTest::testGetCurrentMove_afterOneMove_X() {
	Board b(10, 5);
	b.move(0, 0);
	DO_CHECK(b.getCurrentMove() == X);
}
	
void BoardTest::testGetCurrentMove_afterTwoMoves_O() {
	Board b(10, 5);
	b.move(0, 0);
	b.move(1, 1);
	DO_CHECK(b.getCurrentMove() == O);
}
	
void BoardTest::testGetCurrentMove_afterThreeMoves_X() {
	Board b(10, 5);
	b.move(0, 0);
	b.move(5, 6);
	b.move(9, 9);
	DO_CHECK(b.getCurrentMove() == X);
}
	
void BoardTest::testGetCell_EMPTY() {
	Board b(10, 5);
	DO_CHECK(b.getCell(1, 1) == EMPTY); 
}
	
void BoardTest::testGetCell_0_0_O() {
	Board b(10, 5);
	b.move(0, 0);
	DO_CHECK(b.getCell(0, 0) == O);
}
	
void BoardTest::testGetCell_9_8_X() {
	Board b(10, 5);
	b.move(1, 1);
	b.move(9, 8);
	DO_CHECK(b.getCell(9, 8) == X);
}

void BoardTest::runAllTests() {
	testCanMove_0_0();
	testCanMove_5_5();
	testCanMove_1_2();
	testMove_0_0();	
	testMove_9_9();
	testMove_1_5();
	testGetState_col_O_WIN();
	testGetState_diag_X_WIN();
	testGetState_GAME_IN_PROGRESS();
	testWhoIsWinner_afterZeroMoves_X_WIN();
	testWhoIsWinner_afterOneMove_O_WIN();
	testWhoIsWinner_afterTwoMoves_X_WIN();
	testGetBoardSize_10();
	testGetBoardSize_3();
	testGetBoardSize_4();
	testGetStripSize_5();
	testGetStripSize_3();
	testGetStripSize_6();
	testGetCurrentMove_afterOneMove_X();
	testGetCurrentMove_afterTwoMoves_O();
	testGetCurrentMove_afterThreeMoves_X();
	testGetCell_EMPTY();	
	testGetCell_0_0_O();
	testGetCell_9_8_X();
}
