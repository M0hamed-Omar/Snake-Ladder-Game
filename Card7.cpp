#include"Card7.h"
#include"ApplicationManager.h"
#include"RollDiceAction.h"

Card7::Card7(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;
}

void Card7::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	/*((RollDiceAction*)pGrid)->Execute();*/
	/*((ApplicationManager*)pGrid)->ExecuteAction(ROLL_DICE);    */          
	ApplicationManager AppMan;
	AppMan.ExecuteAction(ROLL_DICE);
	AppMan.UpdateInterface(); // Maybe this is the right way 
}

void Card7::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameters (It doesn't have)
	OutFile << endl;
}

void Card7::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 


}