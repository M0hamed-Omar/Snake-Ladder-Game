#include"Card3.h"


Card3::Card3(const CellPosition& pos):Card(pos)
{

}

void Card3::Apply(Grid* pGrid, Player* pPlayer)
{
	Cell *x = pPlayer->GetCell();
	const CellPosition cellposition = x->GetCellPosition();
	Card::Apply(pGrid, pPlayer);
	Ladder *l = pGrid->GetNextLadder(cellposition);
	const CellPosition new_cellposition = ((GameObject*)l)->GetPosition();
	int startcell = new_cellposition.GetCellNum();
	if (pGrid == NULL) // I am not sure if i put l is correct or not 
	{

	}
	else
	{
		pPlayer->Move(pGrid,startcell);
	}
}