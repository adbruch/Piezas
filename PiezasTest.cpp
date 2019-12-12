/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <vector>
 
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
//Bottom tests are about ToggleTurn
TEST(PiezasTest, toggleTurnO)
{
	Piezas pieza;
	ASSERT_EQ( pieza.toggleTurn(), O);
}

TEST(PiezasTest, toggleTurnX)
{
	Piezas pieza;
	pieza.toggleTurn();
	ASSERT_EQ( pieza.toggleTurn(), X);
}
//dropPiece test-------------------------------------------------------------------------
TEST(PiezasTest, dropPiece0X)
{
	Piezas pieza;
	ASSERT_EQ( pieza.dropPiece(0), X);
}

TEST(PiezasTest, dropPiece0O)
{
	Piezas pieza;
	pieza.dropPiece(0);
	ASSERT_EQ( pieza.dropPiece(0), O);
}
TEST(PiezasTest, dropPieceInvalid)
{
	Piezas pieza;
	ASSERT_EQ( pieza.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPieceFull)
{
	Piezas pieza;
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	ASSERT_EQ( pieza.dropPiece(2), Blank);
}

TEST(PiezasTest, dropPieceRandom)
{
	Piezas pieza;
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(3);
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	ASSERT_EQ( pieza.dropPiece(2), X);
}
//reset test-----------------------

TEST(PiezasTest, resetTest)
{
	Piezas pieza;
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.reset();
	ASSERT_EQ( pieza.pieceAt(0,2), Blank);
}
//pieceAt tests-----------------------------------------------
TEST(PiezasTest, pieceAtRandom)
{
	Piezas pieza;
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(3);
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	ASSERT_EQ( pieza.pieceAt(0,0), X);
}

TEST(PiezasTest, pieceAtRandom2)
{
	Piezas pieza;
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(3);
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	ASSERT_EQ( pieza.pieceAt(1,3), O);
}

TEST(PiezasTest, PieceAtInvalid)
{
	Piezas pieza;
	pieza.dropPiece(0);
	ASSERT_EQ( pieza.dropPiece(-1,4), Invalid);
}

TEST(PiezasTest, PieceAtBlank)
{
	Piezas pieza;
	pieza.dropPiece(0);
	ASSERT_EQ( pieza.dropPiece(1,1), Blank);
}

//gameState tests------------------------------
TEST(PiezasTest, gameStateInvalid)
{
	Piezas pieza;
	pieza.dropPiece(0);
	ASSERT_EQ( pieza.gameState(), Invalid);
}

TEST(PiezasTest, gameStateInvalid2)
{
	Piezas pieza;
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	ASSERT_EQ( pieza.gameState(), Invalid);
}

TEST(PiezasTest, gameStateTie)
{
	Piezas pieza;
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	ASSERT_EQ( pieza.gameState(), Blank);
}

TEST(PiezasTest, gameStateX)
{
	Piezas pieza;
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(0);
	pieza.dropPiece(2);
	pieza.dropPiece(0);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(1);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	ASSERT_EQ( pieza.gameState(), X);
}

TEST(PiezasTest, gameStateO)
{
	Piezas pieza;
	pieza.toggleTurn();
	pieza.dropPiece(0);
	pieza.dropPiece(1);
	pieza.dropPiece(0);
	pieza.dropPiece(2);
	pieza.dropPiece(0);
	pieza.dropPiece(3);
	pieza.dropPiece(1);
	pieza.dropPiece(2);
	pieza.dropPiece(2);
	pieza.dropPiece(1);
	pieza.dropPiece(3);
	pieza.dropPiece(3);
	ASSERT_EQ( pieza.gameState(), O);
}