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
	
	
	if (s) // I am not sure if i put l is correct or not 
	{
		const CellPosition new_cellposition = ((GameObject*)s)->GetPosition(); // to get the new cell poaition which have the start of ladder
		int startcell = new_cellposition.GetCellNum(); // to get the cell number of the new cell position
		int currentcell = pPlayer->GetCell()->GetCellPosition().GetCellNum();
		pPlayer->Move(pGrid, startcell - currentcell); // move the player to the new cell number
		pPlayer->decrementTurnCount(); // to decrease the turn count by 1 as the player already moved when he got the card
	}
	else
		pGrid->PrintErrorMessage("No snake to move for..");
}

void Card4::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameters (It doesn't have)
	OutFile << endl;
}

void Card4::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	// no parameters to load

}