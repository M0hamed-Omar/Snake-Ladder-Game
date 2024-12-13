#include"Card4.h"


Card4::Card4(const CellPosition& pos) :Card(pos)
{
	cardNumber = 4;
}

void Card4::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Cell* x = pPlayer->GetCell();
	const CellPosition cellposition = x->GetCellPosition();
	Card::Apply(pGrid, pPlayer);
	Snake* s = pGrid->GetNextSnake(cellposition);
	const CellPosition new_cellposition = ((GameObject*)s)->GetPosition();
	int startcell = new_cellposition.GetCellNum();
	if (pGrid == NULL) // I am not sure if i put s is correct or not 
	{

	}
	else
	{
		pPlayer->Move(pGrid, startcell);
	}
}