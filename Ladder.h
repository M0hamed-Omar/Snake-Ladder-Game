#pragma once

#include "GameObject.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	virtual bool IsOverLapping(GameObject* Obj); // Checks if the passed GameObject overlaps with this ladder

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual void Save(ofstream& OutFile, ObjectType Obj); // saving to a file when the ObjectType enum passed is LadderObj else it returns
	virtual void Load(ifstream& Infile);
	virtual ~Ladder(); // Virtual destructor
	
};

