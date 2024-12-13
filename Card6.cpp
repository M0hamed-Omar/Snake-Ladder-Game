#include"Card6.h"

Card6::Card6(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}

void Card6::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	int RollDiceNum = pPlayer->GetJustRolledDiceNum();
	pPlayer->Move(pGrid, -1*RollDiceNum);
	
}