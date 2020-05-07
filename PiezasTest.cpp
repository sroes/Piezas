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

	ASSERT_EQ(game.dropPiece(2), O);
}

TEST(PiezasTest, col_negative) {
  Piezas game;
  ASSERT_EQ(game.pieceAt(0, -2), Invalid);
}

TEST(PiezasTest, col_positive) {
  Piezas game;
  ASSERT_EQ(game.pieceAt(0, 4), Invalid);
}

TEST(PiezasTest, drop_piece_x) {
  Piezas game;
  ASSERT_EQ(game.dropPiece(4), X);
}

TEST(PiezasTest, drop_piece_O) {
  Piezas game;
  ASSERT_EQ(game.dropPiece(4), O);
}

TEST(PiezasTest, drop_piece_x_nagative) {
  Piezas game;
  ASSERT_EQ(game.dropPiece(-4), X);
}

TEST(PiezasTest, drop_piece_o_nagative) {
  Piezas game;
  ASSERT_EQ(game.dropPiece(-4), O);
}

///////


TEST(PiezasTest, piece_column){
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(0), Blank);
}

TEST(PiezasTest, afterreset){
  Piezas game;
  game.dropPiece(0);
  game.reset();
	ASSERT_EQ(game.pieceAt(0,0), Blank);
}


TEST(PiezasTest, game_is_tied){
  Piezas game;
    game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(1);
	ASSERT_EQ(game.gameState(), Blank);
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

TEST(PiezasTest, X_wins_game){
  Piezas game;
    game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.gameState(), X);
}

TEST(PiezasTest, O_wins_game){
  Piezas game;
    game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.gameState(), O);
}