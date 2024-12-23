#include"Card3.h"


Card3::Card3(const CellPosition& pos):Card(pos)
{
	cardNumber = 3;
}

void Card3::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply( pGrid,  pPlayer);

	Cell *x = pPlayer->GetCell(); // to get the cell which player at
	const CellPosition cellposition = x->GetCellPosition();
	Card::Apply(pGrid, pPlayer); // like given card 1
	Ladder *l = pGrid->GetNextLadder(cellposition); // to get the next ladder after the current cell which player at
	
	if (l) // I am not sure if i put l is correct or not 
	{
		const CellPosition new_cellposition = ((GameObject*)l)->GetPosition(); // to get the new cell poaition which have the start of ladder
		int startcell = new_cellposition.GetCellNum(); // to get the cell number of the new cell position
		int currentcell = pPlayer->GetCell()->GetCellPosition().GetCellNum();
		pPlayer->Move(pGrid, startcell - currentcell); // move the player to the new cell number
		pPlayer->decrementTurnCount(); // to decrease the turn count by 1 as the player already moved when he got the card
	}
	else
		pGrid->PrintErrorMessage("No ladder to move for..");
	
}

void Card3::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameter (It doesn't have)
	OutFile <<endl;
}

void Card3::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	// no parameters to load
	

}

