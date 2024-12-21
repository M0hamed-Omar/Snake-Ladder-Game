#pragma once
#include "Card.h"
class Card2 :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	Card2(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream& OutFile, ObjectType Obj); // saving to a file when the ObjectType enum passed is CardObj else it returns
	virtual void Load(ifstream& Infile);
	void SetWalletAmount2(int newValue); // added by omar to be used in edit card 

	virtual ~Card2(); // A Virtual Destructor
};
