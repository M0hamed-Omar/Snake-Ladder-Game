#include"Card7.h"
#include"ApplicationManager.h"
#include"RollDiceAction.h"
#include<time.h>
Card7::Card7(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;
}

void Card7::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	/*((RollDiceAction*)pGrid)->Execute();*/
	/*((ApplicationManager*)pGrid)->ExecuteAction(ROLL_DICE);    */          
	//ApplicationManager AppMan;
	//AppMan.ExecuteAction(ROLL_DICE);
	//AppMan.UpdateInterface(); // Maybe this is the right way 
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6;
	pGrid->GetOutput()->PrintMessage("You will have another Roll dice..");
	pGrid->PrintErrorMessage(to_string(diceNumber) + "      Click to move");
	if(pPlayer->GetTurnCount() != 2)
	pPlayer->Move(pGrid, diceNumber);
	else
	{
		pGrid->PrintErrorMessage("The wallet will be charged with " + to_string(diceNumber) + "    Click to charge the wallet..");
		pPlayer->Move(pGrid, diceNumber);
	}
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