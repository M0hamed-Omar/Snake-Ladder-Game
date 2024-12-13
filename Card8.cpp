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