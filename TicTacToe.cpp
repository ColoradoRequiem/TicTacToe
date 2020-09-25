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
	void SetSquareValue(int r, int c, std::string value); 	// set the value of a square to the given SquareType
	std::vector<Position> GetMoves(Player *p); // get the possible Positions that a Player could move to

	void PrintBoard();
	void TakeTurn();
	bool GameOver(); // not sure how im going to prioitize player over "EXIT" when checking this, probably just overwrite the value when the player gets there

private:
	std::string arr_[3][3];
};  // class Board

Board::Board() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      arr_[i][j] = "-";
    }
  }
}

void Board::PrintBoard() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      std::cout << arr_[i][j] << " | "
    }
  }
}
