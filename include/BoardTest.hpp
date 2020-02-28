#include "Test.hpp"

class BoardTest: public Test {
private:
	void testCanMove_0_0();

	void testCanMove_5_5();

	void testCanMove_1_2();

	void testMove_0_0();
		
	void testMove_9_9();
	
	void testMove_1_5();
	
	void testGetState_col_O_WIN();
	
	void testGetState_diag_X_WIN();
	
	void testGetState_GAME_IN_PROGRESS();
	
	void testWhoIsWinner_afterZeroMoves_X_WIN();
	
	void testWhoIsWinner_afterOneMove_O_WIN();
	
	void testWhoIsWinner_afterTwoMoves_X_WIN();

	void testGetBoardSize_10();
	
	void testGetBoardSize_3();
	
	void testGetBoardSize_4();

	void testGetStripSize_5();
	
	void testGetStripSize_3();
	
	void testGetStripSize_6();
	
	void testGetCurrentMove_afterOneMove_X();
	
	void testGetCurrentMove_afterTwoMoves_O();
	
	void testGetCurrentMove_afterThreeMoves_X();
	
	void testGetCell_EMPTY();
	
	void testGetCell_0_0_O();
	
	void testGetCell_9_8_X();
	    
public:
    void runAllTests();
};
