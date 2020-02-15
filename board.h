#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Board{
public:
	Board();
	void printBoard();
	void loadFromFile(string fileName);
	bool possible(int row, int col, int num);
	bool solve();
private:
	vector< vector<int> > board;
};