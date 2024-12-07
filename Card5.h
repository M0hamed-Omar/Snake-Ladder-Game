#pragma once
#include"Card.h"

class Card5 : public Card
{

public:
	Card5(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
};
