#pragma once
#include "Card.h"


class Card8 : public Card
{

	int nextRollDice;

public:
	Card8(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, ObjectType Obj);
};