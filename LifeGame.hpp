#ifndef __LIFEGAME__
#define __LIFEGAME__

typedef enum eCellState
{
	DEAD = 0,
	ALIVE,
}eCellState;

class Cell
{
public:
	Cell( eCellState );
	~Cell();
	eCellState GetState();
	void UpdateState( int theNumOfAliveNeighborCells );
private:
	eCellState _state;
};

#endif
