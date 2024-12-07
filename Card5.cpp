#include"Card5.h"

Card5::Card5(const CellPosition& pos) :Card(pos)
{

}

void Card5::Apply(Grid* pGrid, Player* pPlayer)
{
	
	
	int RollDiceNum = pPlayer->GetJustRolledDiceNum();
	pPlayer->Move(pGrid, RollDiceNum);
	Cell* ptr = pPlayer->GetCell();
	if (ptr->HasLadder() || ptr->HasSnake())
	{
		ptr->GetGameObject()->Apply(pGrid,pPlayer);
	}

}