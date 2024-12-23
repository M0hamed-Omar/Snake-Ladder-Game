#include"Card5.h"

Card5::Card5(const CellPosition& pos) :Card(pos)
{
	cardNumber = 5;
}

void Card5::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("You will move forward again by the last roll dice..");
	int RollDiceNum = pPlayer->GetJustRolledDiceNum();
	pPlayer->Move(pGrid, RollDiceNum);
	Cell* ptr = pPlayer->GetCell();
	if (ptr->HasLadder() || ptr->HasSnake())
	{
		ptr->GetGameObject()->Apply(pGrid,pPlayer);
	}
	pPlayer->decrementTurnCount(); // to decrease the turn count by 1 as the player already moved when he got the card

}

void Card5::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameters (It doesn't have)
	OutFile << endl;
}

void Card5::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	// no parameters to load

}