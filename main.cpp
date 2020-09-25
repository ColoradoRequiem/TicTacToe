#include "TicTacToe.cpp"

int main() {
  Board * b = new Board();
  b->DisplayBoard();



  delete b;
  return 0;
}
