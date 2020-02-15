#include "board.h"

Board::Board(){
	this->board.resize(9);
	for(int row=0; row<9; row++){
		this->board[row].resize(9);
		for(int col=0; col<9; col++){
			this->board[row][col] = 0;
		}
	}
}

void Board::printBoard(){
	cout << "  0 1 2 3 4 5 6 7 8 " << endl;
	for(int row=0; row<9; row++){
		cout << row << "|";
		for(int col=0; col<9; col++){
			cout << this->board[row][col] << " ";
		}
		cout << endl;
	}
}

void Board::loadFromFile(string fileName){
	ifstream file;
	file.open(fileName);

	if( !file.is_open() ){
		return;
	}

	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			file >> this->board[row][col];
		}
	}

	file.close();
}

bool Board::possible(int row, int col, int num){
	if(col > 8 || col < 0 || row > 8 || row < 0 || num < 1 || num > 9){
		//cout << "out of range!" << endl;
		return false;
	}
	
	/*if(this->board[row][col] != 0){
		//cout << "full!" << endl;
		return false;
	}*/

	// Check line
	for(int col=0; col<9; col++){
		if(this->board[row][col] == num){
			//cout << "found on col" << endl;
			return false;
		}
	}
	// Check row
	for(int row=0; row<9; row++){
		if(this->board[row][col] == num){
			//cout << "found on row" << endl;
			return false;
		}
	}

	// Check subgrid
	int baserow = row - (row % 3); // 0, 3, 6
	int basecol = col - (col % 3); // 0, 3, 6
	for(int row=baserow; row<baserow+3; row++){
		for(int col=basecol; col<basecol+3; col++){
			if(this->board[row][col] == num){
				//cout << "found on subgrid" << endl;
				return false;
			}
		}
	}

	return true;
}

bool Board::solve(){
	// Backtracking Algorithm
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			// If cell is empty
			if(this->board[row][col] == 0){
				bool flag = false;	// Can make a placement?
				for(int num=1; num<=9; num++){
					if(this->possible(row, col, num)){
						flag = true;	// Make a placement
						this->board[row][col] = num;
						// If this placement valid
						if(solve() == true){
							return true;
						} else{
							flag = false;
						}
					}
				}
				// If there is no valid placement, return false
				if(flag == false){
					this->board[row][col] = 0;
					return false;
				}
			}
		}
	}
	this->printBoard();
	return true;
}