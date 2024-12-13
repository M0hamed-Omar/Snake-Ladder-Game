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