#pragma once
#include"Card.h"

class Card5 : public Card
{

public:
	Card5(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, ObjectType Obj);
	virtual void Load(ifstream& Infile);

};
