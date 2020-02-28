#include "StdioBoardView.hpp"
#include "NcursesBoardView.hpp"
#include <cstring>

int main(int argc, char** argv) {
	Board board(10, 5);
	if(argc > 1 && !strcmp(argv[1], "curses")) {
		NcursesBoardView ncursesBoardView(board);
		ncursesBoardView.doGameCycle();
	}
	else{
		bool isSilent = (argc > 1 && !strcmp(argv[1], "silent"));
		StdioBoardView stdioBoardView(board, isSilent);
		stdioBoardView.doGameCycle();
	}
	return 0;	
}
