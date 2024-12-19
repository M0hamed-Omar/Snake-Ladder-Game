#include"Card8.h"


Card8::Card8(const CellPosition & pos) :Card(pos)
{
	cardNumber = 8;
}

void Card8::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int prevTurnCount = pPlayer->GetTurnCount();
	//if()
	/*AdvanceCurrentPlayer()*/ //use it
}

void Card8::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameters (It doesn't have)
	OutFile << endl;
}

void Card8::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	// no parameters

}