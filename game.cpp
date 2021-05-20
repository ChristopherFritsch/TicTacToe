#include "game.hpp"
#include <deque>
#include <iostream>

bool Game::makeMove(int pos){
	if(!playerHist.empty()){
		if (gameBoard.getBoard()[pos] == 0){
			gameBoard.makeMove(pos, -(playerHist.back()));
			moveHist.push_back(pos);
			playerHist.push_back(-(playerHist.back()));
			return true;
		}
		else{
			return false;
		}
	}
	else{
		gameBoard.makeMove(pos, 1);
		moveHist.push_back(pos);
		playerHist.push_back(1);
		return true;
	}
}

bool Game::makeMoves(std::vector<int> poss){
	for(int i = 0; i < poss.size(); i++){
		if(!makeMove(poss[i])){
			return false;
		}
	}
	return true;
}

std::vector<int> Game::getMoveHist(){
	return moveHist;
}

std::vector<int> Game::getPlayerHist(){
	return playerHist;
}

int Game::getWinner(){
	return gameBoard.getWinner();
}

Board Game::getBoard(){
	return gameBoard;
}

Game* Game::getParent(){
	return parent;
}

void Game::setParent(Game* parent){
	this->parent = parent;
}

void Game::setScore(int score){
	this->score = score;
}

int Game::getScore(){
	return score;
}

void Game::makeOptimalMove(){
	std::deque<Game*> bfs;
	std::vector<Game*> gameTree;
	
	if(!playerHist.empty()){
		if(playerHist.back() == 1){
			score = 10;
		}
		else{
			score = -10;
		}
	}
	else{
		score = -10;
	}
	
	bfs.push_back(this);
	
	while(!bfs.empty()){
		Game* currentGame;
		currentGame = bfs.front();
		gameTree.push_back(currentGame);
		bfs.pop_front();
		if(currentGame->getBoard().getWinner() == 0 && currentGame->getMoveHist().size() < 9){
			for(int i = 0; i < 9; i++){
				Game* nextGame = new Game;
				nextGame->makeMoves(currentGame->getMoveHist());
				if (nextGame->makeMove(i)){
					nextGame->setParent(currentGame);
					if(nextGame->getPlayerHist().back() == 1){
						nextGame->setScore(10);
					}
					else{
						nextGame->setScore(-10);
					}
					bfs.push_back(nextGame);
				}
				else{
					delete nextGame;
				}
			}
		}
		else{
			currentGame->setScore((10 - currentGame->getMoveHist().size()) * currentGame->getBoard().getWinner());
		}
	}
	
	for(int i = gameTree.size() - 1; i > 0; i--){
		if(gameTree[i]->getPlayerHist().back() == 1){
			if(gameTree[i]->getScore() > gameTree[i]->getParent()->getScore()){
				gameTree[i]->getParent()->setScore(gameTree[i]->getScore());
			}
		}
		else{
			if(gameTree[i]->getScore() < gameTree[i]->getParent()->getScore()){
				gameTree[i]->getParent()->setScore(gameTree[i]->getScore());
			}
		}
		if(gameTree[i]->getParent() != this){
			delete gameTree[i];
			gameTree[i] = nullptr;
		}
	}
	
	for(int i = 1; gameTree[i] != nullptr; i++){
		if(gameTree[i]->getScore() == this->score){
			makeMove(gameTree[i]->getMoveHist().back());
			break;
		}
	}
	
	for(int i = 1; gameTree[i] != nullptr && i < gameTree.size(); i++){
		delete gameTree[i];
		gameTree[i] = nullptr;
	}
}

void Game::show(){
	gameBoard.show();
	std::cout << score << std::endl << std::endl;
}
