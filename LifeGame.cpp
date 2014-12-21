#include "LifeGame.hpp"

Cell::Cell( eCellState state )
{
	_state = state;
}

Cell::~Cell()
{
}

eCellState Cell::GetState()
{
	return _state;
}

void Cell::UpdateState( int theNumOfAliveNeighborCells )
{
	if( theNumOfAliveNeighborCells == 3 )
	{
		_state = ALIVE;
	}
	else if( theNumOfAliveNeighborCells >= 4 ||
			 theNumOfAliveNeighborCells <= 1 )
	{
		_state = DEAD;
	}
}
