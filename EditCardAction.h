//========= By : Mohamed Omar ==============

#pragma once

#include "Action.h"

class EditCardAction : public Action
{
	CellPosition* pos;// to check if user clicked on a cell does not hasve a card 
	bool excute;
	Card*crd;// association
public:
	EditCardAction(ApplicationManager* pApp);
	//====================
	// there are parameters to read , these parameters include 2 categories 
	// 1- first category : the general info like : the card  & check if the card is editable 
	// 2- second category : special info for the specific card 
	virtual void ReadActionParameters();
	//=======================

	virtual void Execute();


	//================================


	~EditCardAction();

};

