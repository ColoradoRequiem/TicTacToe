#include "TicTacToe.cpp"

int main() {
  Board * b = new Board();

  int turn = 0;
  std::string mark;

  std::cout << "NEW GAME" << std::endl;

  b->DisplayBoard();
  while (b->GameOver() == false) {
    if (turn % 2 == 0) {
      std::cout << "Player One's Turn" << std::endl;
      mark = "X";
    }
    else {
      std::cout << "Player Two's Turn" << std::endl;
      mark = "O";
    }
    turn ++;
    b->GetPlayerChoice(mark);
    b->DisplayBoard();
  }

  std::cout << std::endl;
  std::cout << "GAME OVER!" << std::endl;

  delete b;
  return 0;
}
