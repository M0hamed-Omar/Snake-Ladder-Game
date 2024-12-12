#include"Card7.h"
#include"ApplicationManager.h"
#include"RollDiceAction.h"

Card7::Card7(const CellPosition& pos) :Card(pos)
{

}

void Card7::Apply(Grid* pGrid, Player* pPlayer)
{
	/*((RollDiceAction*)pGrid)->Execute();*/
	((ApplicationManager*)pGrid)->ExecuteAction(ROLL_DICE);
}