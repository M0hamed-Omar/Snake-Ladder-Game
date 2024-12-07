#include"Card5.h"

Card5::Card5(const CellPosition& pos) :Card(pos)
{

}

void Card5::Apply(Grid* pGrid, Player* pPlayer)
{
	
	
	int RollDiceNum = pPlayer->GetJustRolledDiceNum();
	/*pPlayer->Move(pGrid, RollDiceNum);
	if (((Cell*)pGrid)->Cell::HasLadder() || ((Cell*)pGrid)->Cell::HasSnake())
	{
		
	}*/
}