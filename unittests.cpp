#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "board.hpp"
#include "game.hpp"
#include <iostream>

TEST_CASE("Test Board functions", "[Board]"){
	Board b;
	
	for(int i = 0; i < 9; i++){
		REQUIRE(b.getBoard()[i] == 0);
		REQUIRE(b.makeMove(i, 8));
		REQUIRE(!b.makeMove(i, -5));
	}
	
	b = Board();
	
	b.makeMove(0, 1);
	b.makeMove(1, 1);
	b.makeMove(2, 1);
	REQUIRE(b.getWinner() == 1);
	
	b = Board();
	
	b.makeMove(0, -1);
	b.makeMove(3, -1);
	b.makeMove(6, -1);
	REQUIRE(b.getWinner() == -1);
	
	
	b = Board();
	
	b.makeMove(1, 1);
	b.makeMove(5, 1);
	b.makeMove(7, 1);
	REQUIRE(b.getWinner() == 0);
}

TEST_CASE("Test Game Functions", "[Game]"){
	Game g;
	
	REQUIRE(g.getMoveHist() == std::vector<int>());
	REQUIRE(g.getPlayerHist() == std::vector<int>());
	
	REQUIRE(g.makeMove(0));
	REQUIRE(g.makeMove(1));
	REQUIRE(g.makeMove(3));
	REQUIRE(g.makeMove(2));
	REQUIRE(g.makeMove(4));
	REQUIRE(g.makeMove(5));
	REQUIRE(g.getMoveHist() == std::vector<int>{0,1,3,2,4,5});
	REQUIRE(g.getPlayerHist() == std::vector<int>{1,-1,1,-1,1,-1});
	REQUIRE(!g.makeMove(0));
	REQUIRE(!g.makeMove(1));
	REQUIRE(!g.makeMove(3));
	REQUIRE(!g.makeMove(2));
	REQUIRE(!g.makeMove(4));
	REQUIRE(!g.makeMove(5));
	g.show();
	REQUIRE(g.getMoveHist() == std::vector<int>{0,1,3,2,4,5});
	REQUIRE(g.getPlayerHist() == std::vector<int>{1,-1,1,-1,1,-1});
	
	Game gcopy;
	REQUIRE(gcopy.makeMoves(g.getMoveHist()));
	REQUIRE(gcopy.getMoveHist() == std::vector<int>{0,1,3,2,4,5});
	REQUIRE(gcopy.getPlayerHist() == std::vector<int>{1,-1,1,-1,1,-1});
	
	//g.makeOptimalMove();
	g.show();
	
	
	
	g = Game();
	g.makeMove(0);
	g.makeMove(1);
	g.makeMove(2);
	g.makeMove(3);
	g.makeMove(4);
	g.show();
	g.makeOptimalMove();
	g.show();
	g.makeOptimalMove();
	g.show();
	
	g = Game();
	g.makeMove(0);
	g.makeMove(4);
	g.makeMove(2);
	g.makeMove(1);
	g.makeMove(7);
	g.makeMove(5);
	g.makeMove(3);
	g.makeMove(6);
	g.show();
	g.makeOptimalMove();
	g.show();
	
}




