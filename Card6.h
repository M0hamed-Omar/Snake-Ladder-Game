#pragma once
#include"Card.h"

class Card6 : public Card
{

public:
	Card6(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, ObjectType Obj);
	virtual void Load(ifstream& Infile);

};