//=============By : Mohamed Omar==============
#pragma once
#include "Card.h"
class Card9 :public Card
{
	int DestinationCell;
public:
	Card9(const CellPosition& pos);
	//=====================================

	//we need to read the destination cell from here and do our validation that " is valid cell " only
	virtual void ReadCardParameters(Grid* pGrid);

	//=======================================
	// Applies the effect of Card on the passed Player
	//this effect is moved to destination cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void Save(ofstream& OutFile, ObjectType Obj);
	virtual void Load(ifstream& Infile);

	//=============================================
	virtual ~Card9(); // A Virtual Destructor
};

