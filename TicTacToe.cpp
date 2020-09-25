#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <vector>

class Board {
public:
	// TODO: implement
	Board();

	int get_rows() const {return 3;}  // you should be able to change the size of your
	int get_cols() const {return 3;}  // board by changing these numbers and the numbers in the arr_ field

	std::string get_square_value(int r, int c); // should return Squaretype but with the funcs it relies on i might need to change some things around
	void place_Marker(int r, int c, std::string value); 	// set the value of a square to the given SquareType
	// std::vector<Position> GetMoves(Player *p); // get the possible Positions that a Player could move to

	void DisplayBoard();
	std::vector<int> GetPlayerChoice(std::string mark);
	void TakeTurn();
	bool GameOver();

private:
	std::string arr_[3][3]; // row, col
};  // class Board

Board::Board() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      arr_[i][j] = " ";
    }
  }
}

void Board::DisplayBoard() {
	std::cout << "  0   1   2" << std::endl;

  for(int i = 0; i < 3; i++) {
		std::cout << i << " ";
    for(int j = 0; j < 3; j++) {
      std::cout << arr_[i][j];
      if (j < 2) {
        std::cout << " | ";
      }
    }
    std::cout << std::endl;
    if (i < 2) {
      std::cout << "  _   _   _" <<std::endl;
    }
  }
}

void Board::place_Marker(int r, int c, std::string value) {
	if (r < 0 | r > 2 | c < 0 | c > 2 ) {
		std::cout << "ERROR: OUT OF BOUNDS" << std::endl;
	}
	else {
		if (arr_[r][c] != " ") {
			std::cout << "ERROR: SPOT ALREADY PLAYED" << std::endl;
		}
		else {
			this->arr_[r][c] = value;
		}
	}
	return;
}

 std::vector<int> Board::GetPlayerChoice(std::string mark){
	bool choice_made = false;
	std::vector<int> coordinates;
	std::string row_choice = "";
	std::string col_choice = "";

	while (!choice_made){
		std::cout << "Choose which row on the board you would like to place your marker" << std::endl;
		std::getline(std::cin, row_choice);
		std::cout << "Choose which column on the board you would like to place your marker" << std::endl;
		std::getline(std::cin, col_choice);

		if(row_choice == "0" || row_choice == "1" || row_choice == "2"){
			if(col_choice == "0" || col_choice == "1" || col_choice == "2"){
				coordinates.push_back(std::stoi(row_choice));
				coordinates.push_back(std::stoi(col_choice));
				place_Marker(std::stoi(row_choice), std::stoi(col_choice), mark);
				choice_made = true;
			}
			else{
				std::cout << "Invalid choice, please try again." << std::endl << std::endl;
			}
		}

		else{
			std::cout << "Invalid choice, please try again." << std::endl << std::endl;
		}

	}

	return coordinates;
}

bool Board::GameOver() { // r , c
	bool three = false;

	for (int i = 0; i < 3; i++) { // row check
		int countr = 0;
		for (int j = 0; j < 3; j++) {
			if (j > 0) {
				if ((arr_[i][j] == arr_[i][j-1]) && (arr_[i][j] != " ")) {
					countr++;
					if (countr == 2) {return true;}
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) { // column check
		int countc = 0;
		for (int j = 0; j < 3; j++) {
			if (j > 0) {
				if ((arr_[j][i] == arr_[j-1][i]) && (arr_[j][i] != " ")) {
					countc++;
					if (countc == 2) {return true;}
				}
			}
		}
	}

	//diag check
	if ((arr_[0][0] == arr_[1][1]) & (arr_[1][1] == arr_[2][2]) & (arr_[2][2] != " ")) {
		return true;
	}

	if ((arr_[0][2] == arr_[1][1]) & (arr_[1][1] == arr_[2][0]) & (arr_[2][0] != " ")) {
		return true;
	}

	return three;
}

#endif
