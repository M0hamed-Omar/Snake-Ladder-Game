//==========By : Mohamed Omar=============
#pragma once
#include "Action.h"
//#include "AddCardAction.h"


class PasteCardAction : public Action 
{
	CellPosition* DestinationCell;
	//AddCardAction *acPtr;
public:
	PasteCardAction(ApplicationManager* ptr);

	//===================================================
	 
	// needs to read some parameters 
	// 1-need to read the destination cell , and check if:
	// i- valid cell 
	// ii- does not have a card or any GameObject 
	// 2-the clipboard ptr 
	virtual void ReadActionParameters(); 
	//=============================================

	//1-put the card on the destination cell 
	//2-clear the clipboard
	virtual void Execute();
	//===========================================
	~PasteCardAction();
};

