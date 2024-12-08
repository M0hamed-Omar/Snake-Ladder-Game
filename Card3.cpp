#include"Card3.h"


Card3::Card3(const CellPosition& pos):Card(pos)
{

}

void Card3::Apply(Grid* pGrid, Player* pPlayer)
{
	Cell *x = pPlayer->GetCell(); // to get the cell which player at
	const CellPosition cellposition = x->GetCellPosition();
	Card::Apply(pGrid, pPlayer); // like given card 1
	Ladder *l = pGrid->GetNextLadder(cellposition); // to get the next ladder after the current cell which player at
	
	if (pGrid == NULL) // I am not sure if i put l is correct or not 
	{

	}
	else
	{
		const CellPosition new_cellposition = ((GameObject*)l)->GetPosition(); // to get the new cell poaition which have the start of ladder
		int startcell = new_cellposition.GetCellNum(); // to get the cell number of the new cell position
		pPlayer->Move(pGrid,startcell); // move the player to the new cell number
	}
}
