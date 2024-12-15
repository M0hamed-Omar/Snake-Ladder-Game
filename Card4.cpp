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
	
	if (s) // I am not sure if i put l is correct or not 
	{
		const CellPosition new_cellposition = ((GameObject*)s)->GetPosition(); // to get the new cell poaition which have the start of ladder
		int startcell = new_cellposition.GetCellNum(); // to get the cell number of the new cell position
		int currentcell = pPlayer->GetCell()->GetCellPosition().GetCellNum();
		pPlayer->Move(pGrid, startcell - currentcell); // move the player to the new cell number
	}
}