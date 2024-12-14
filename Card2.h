#pragma once
#include "Card.h"
class Card2 :	public Card
{
	int walletAmount; // the wallet value to increase the player

public:
	Card2(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card2 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card2 on the passed Player
	// by adding the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, ObjectType Obj); // saving to a file when the ObjectType enum passed is CardObj else it returns


	virtual ~Card2(); // A Virtual Destructor
};

