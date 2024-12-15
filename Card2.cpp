#include "Card2.h"


Card2::Card2(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

Card2::~Card2(void)
{
}

void Card2::ReadCardParameters(Grid* pGrid)
{

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	// print a descriptive message to the user like:"New Card2: Enter its wallet amount ..."
	pOut->PrintMessage("New Card2: Enter its wallet amount ...");
	walletAmount = pIn->GetInteger(pOut);

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void Card2::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of Card2

	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);

}

void Card2::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	Infile >> walletAmount;
	
}

void Card2::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card2 parameter
	OutFile <<" " << walletAmount << endl;
}
