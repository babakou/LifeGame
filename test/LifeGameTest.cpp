#include "LifeGame.hpp"
#include "gtest/gtest.h"

namespace
{
	class BirthAndDeathTest : public :: testing::Test
	{
	protected:
		Cell* aliveCell;
		Cell* deadCell;
		
		virtual void SetUp()
			{
				aliveCell = new Cell( ALIVE );
				deadCell = new Cell( DEAD );
			}
	
		virtual void TearDown()
			{
				delete aliveCell;
				delete deadCell;
			}
	};
};

TEST_F( BirthAndDeathTest, CreateCellWithInitialState )
{
	Cell* aliveCell = new Cell( ALIVE );
	EXPECT_EQ( ALIVE, aliveCell->GetState() );
	delete aliveCell;
	
	Cell* deadCell = new Cell( DEAD );
	EXPECT_EQ( DEAD, deadCell->GetState() );
	delete deadCell;
}

TEST_F( BirthAndDeathTest, Birth )
{
	aliveCell->UpdateState( 3 );
	EXPECT_EQ( ALIVE, aliveCell->GetState() );

	deadCell->UpdateState( 3 );
	EXPECT_EQ( ALIVE, deadCell->GetState() );
}

TEST_F( BirthAndDeathTest, Aliving )
{
	aliveCell->UpdateState( 2 );
	EXPECT_EQ( ALIVE, aliveCell->GetState() );

	deadCell->UpdateState( 2 );
	EXPECT_EQ( DEAD, deadCell->GetState() );
}

TEST_F( BirthAndDeathTest, DeadByTooDense )
{
	aliveCell->UpdateState( 4 );
	EXPECT_EQ( DEAD, aliveCell->GetState() );

	deadCell->UpdateState( 4 );
	EXPECT_EQ( DEAD, deadCell->GetState() );
}

TEST_F( BirthAndDeathTest, DeadByTooSparce )
{
	aliveCell->UpdateState( 1 );
	EXPECT_EQ( DEAD, aliveCell->GetState() );

	deadCell->UpdateState( 1 );
	EXPECT_EQ( DEAD, deadCell->GetState() );
}



int main( int argc, char **argv )
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
