#pragma once

#include "Card.h"

class ApplicationManager;
class RollDiceAction;

class Card7 : public Card
{



public:
	Card7(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, ObjectType Obj);
};