//=============By : Mohamed Omar==============
#pragma once
#include "Card.h"
class Card11 :public Card
{
	int CardPrice;
	int Fee;
	static int count;
	static Player* CardOwner; //to own the all card10 cards in the grid  
public:
	Card11(const CellPosition& pos);

	//we need to know the following things
	/*
		1-price --> from user
		2-the fee -->from user
		*/
	virtual void ReadCardParameters(Grid* pGrid);
	//==========================================

	//here we will excute the logic of the card by applying the following steps 
	//ask th player if he will buy the card or not (get the answer as a string):
	//1- if yes :
	//i-search for the other cards with the same number (if exist) and apply the price & fees to them 
	//ii-if the player (differenet than the owner ) stands on it --> take the fee from his wallet 
	//2- if no : no action taken 
	virtual void Apply(Grid* pGrid, Player* pPlayer);


	virtual ~Card11(); // A Virtual Destructor
};

