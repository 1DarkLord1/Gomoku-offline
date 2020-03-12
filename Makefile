all: gomoku

CXXFLAGS=-I include -Wall -Wextra -Werror -g

test: obj obj/Board.o obj/Test.o obj/BoardTest.o obj/test.o
	g++ obj/Board.o obj/Test.o obj/BoardTest.o obj/test.o -o test
	
gomoku: obj obj/Board.o obj/StdioBoardView.o obj/NcursesBoardView.o obj/main.o
	g++ obj/Board.o obj/StdioBoardView.o obj/NcursesBoardView.o -lcurses obj/main.o -o gomoku

obj/Board.o: src/Board.cpp include/Board.hpp
	g++ $(CXXFLAGS) -c src/Board.cpp -o obj/Board.o
	
obj/StdioBoardView.o: src/StdioBoardView.cpp include/StdioBoardView.hpp
	g++ $(CXXFLAGS) -c src/StdioBoardView.cpp -o obj/StdioBoardView.o

obj/NcursesBoardView.o: src/NcursesBoardView.cpp include/NcursesBoardView.hpp
	g++ $(CXXFLAGS) -c src/NcursesBoardView.cpp -o obj/NcursesBoardView.o

obj/Test.o: tests/Test.cpp include/Test.hpp
	g++ $(CXXFLAGS) -c tests/Test.cpp -o obj/Test.o

obj/test.o: tests/test.cpp
	g++ $(CXXFLAGS) -c tests/test.cpp -o obj/test.o

obj/BoardTest.o: tests/BoardTest.cpp include/BoardTest.hpp
	g++ $(CXXFLAGS) -c tests/BoardTest.cpp -o obj/BoardTest.o

obj/main.o: src/main.cpp
	g++ $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj: 
	mkdir -p obj

clean:
	rm -rf obj gomoku test
.PHONY: clean

















