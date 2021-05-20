#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {
	public:
		Board();
		bool makeMove(int pos, int player);
		int getWinner();
		int* getBoard();
		void show();
	private:
		int board[9];
};

#endif
