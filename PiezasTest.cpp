/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, startofgame)
{
  Piezas game;
	ASSERT_EQ(game.pieceAt(0, 2), Blank);
}

TEST(PiezasTest, X_check){
  Piezas game;
	ASSERT_EQ(game.dropPiece(2), X);
}


TEST(PiezasTest, O_check){
  Piezas game;

	ASSERT_EQ(game.dropPiece(1), O);
}

TEST(PiezasTest, col_negative) {
  Piezas game;
  ASSERT_EQ(game.pieceAt(0, -2), Invalid);
}
TEST(PiezasTest, row_negative) {
  Piezas game;
  ASSERT_EQ(game.pieceAt(-2, 0), Invalid);
}

TEST(PiezasTest, col_positive_out) {
  Piezas game;
  ASSERT_EQ(game.pieceAt(0, 4), Invalid);
}

TEST(PiezasTest, bad_drop){
  Piezas game;
	ASSERT_EQ(game.dropPiece(5), Invalid);
}


///////


TEST(PiezasTest, piece_column){
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(0), Blank);
}

TEST(PiezasTest, game_reset){
  Piezas game;
  game.dropPiece(0);
  game.reset();
	ASSERT_EQ(game.pieceAt(0,0), Blank);
}




TEST(PiezasTest, game_not_over){
  Piezas game;
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(0);
	ASSERT_EQ(game.gameState(), Invalid);
}

TEST(PiezasTest, XWins){
  Piezas board;
  board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.gameState(), X);
}


// X O X X
// O X X O
// X O O O
// 11 12 7 9
// 10  3 5 8
// 1   2 4 6


TEST(PiezasTest, OWins){
  Piezas board;
  board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	ASSERT_EQ(board.gameState(), O);
}

// X O X X
// O X O O
// // O X O X
// X O X O
// O X O X
// X O X O
//
// 9 10 11 12
// 8  7 6 5
// 1   2 3 4



TEST(PiezasTest, Tie){
  Piezas board;
  board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	ASSERT_EQ(board.gameState(), Blank);
}