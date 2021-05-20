#include "board.hpp"

Board::Board(){
	for(int i = 0; i < 9; i++){
		board[i] = 0;
	}
}

bool Board::makeMove(int pos, int player){
	if (board[pos] == 0){
		board[pos] = player;
		return true;
	}
	else{
		return false;
	}
}

void Board::show(){
	std::cout << board[0] << board[1] << board[2] << std::endl
			  << board[3] << board[4] << board[5] << std::endl
			  << board[6] << board[7] << board[8] << std::endl;
}

int Board::getWinner(){
	for (int i = 0; i < 3; i++){
		if ((board[i*3] == board[i*3 + 1]) && (board[i*3 + 1] == board[i*3 + 2]) && (board[i*3] != 0)){
			return board[i*3];
		}
		else if ((board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]) && (board[i] != 0)){
			return board[i];
		}
	}
	if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] != 0)){
		return board[0];
	}
	else if((board[2] == board[4]) && (board[4] == board[6]) && (board [2] != 0)){
		return board[2];
	}
	
	return 0;
}

int* Board::getBoard(){
	return board;
}
