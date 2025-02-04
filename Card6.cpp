#include"Card6.h"

Card6::Card6(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}

void Card6::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("You will move backward again by the last roll dice..");
	int RollDiceNum = pPlayer->GetJustRolledDiceNum();
	pPlayer->Move(pGrid, -1*RollDiceNum);
	pPlayer->decrementTurnCount(); // to decrease the turn count by 1 as the player already moved when he got the card
}

void Card6::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameters (It doesn't have)
	OutFile << endl;
}

void Card6::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	//no parameters to load

}