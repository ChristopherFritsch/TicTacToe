#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include <vector>


class Game
{
	public:
		Game() : score(0){}
		bool makeMove(int pos);
		bool makeMoves(std::vector<int> poss);
		int getWinner();
		std::vector<int> getMoveHist();
		std::vector<int> getPlayerHist();
		Game* getParent();
		void setParent(Game* parent);
		int getScore();
		void setScore(int score);
		void makeOptimalMove();
		void show();
		Board getBoard();
			
	private:
		Board gameBoard;
		int score;
		Game* parent;
		std::vector<int> moveHist;
		std::vector<int> playerHist;
};

#endif /* GAME_HPP */ 
