#include "Card9.h"

Card9::Card9(const CellPosition& pos):Card(pos)
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (1 here)
}
Card9:: ~Card9()
{
}

void  Card9::ReadCardParameters(Grid* pGrid)
{
	//we need to read the destination cell from here and do our validation that " is valid cell " only
	//we will follow the guidlines of card 1
	
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	
		// [ Note ]:
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the destination cell from the user using the Input class and set the destination cell  parameter with it
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("Enter the Cell to be moved to");
	CellPosition TempCell=pIn->GetCellClicked();

	// now validate if the input cell is valid or not 
	if (!TempCell.IsValidCell())
	{
		pGrid->PrintErrorMessage("Error : The entered cell is invalid ! Click anywhere to continue....");
		return;
	}
	else
	{
		DestinationCell = &TempCell;
	}
}

void  Card9::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int x = DestinationCell->GetCellNum();
	int y = pPlayer->GetCell()->GetCellPosition().GetCellNum();
	int Dist = x - y;
	pPlayer->Move(pGrid, Dist);
}
void Card9::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameters (It doesn't have)
	OutFile <<" " << DestinationCell->GetCellNum() << endl;
}
void Card9::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	int DestinationCellNum;
		Infile >> DestinationCellNum;

	CellPosition testCell = (CellPosition::GetCellPositionFromNum(DestinationCellNum));
	if (testCell.IsValidCell())
		DestinationCell = &testCell;
	else
		return;
}