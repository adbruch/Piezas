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