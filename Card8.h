#pragma once
#include "Card.h"


class Card8 : public Card
{


public:
	Card8(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, ObjectType Obj);
	virtual void Load(ifstream& Infile);
};