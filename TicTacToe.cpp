#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

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
	void TakeTurn();
	bool GameOver(); // not sure how im going to prioitize player over "EXIT" when checking this, probably just overwrite the value when the player gets there

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
	std::cout << "  1   2   3" << std::endl;

  for(int i = 0; i < 3; i++) {
		std::cout << (i + 1) << " ";
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
			this->arr_[r-1][c-1] = value;
		}
	}
	return;
}

#endif
