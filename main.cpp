#include "board.h"
//#include <ncurses.h>

int main(){
	Board board;
	board.printBoard();
	board.loadFromFile("puzzles/file1.txt");
	board.printBoard();

	board.solve();
	board.printBoard();
	return 0;
}