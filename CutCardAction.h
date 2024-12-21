//================By : Mohamed Omar=============
#pragma once
#include"Action.h"
//#include "CopyCardAction.h"
class CutCardAction :public Action//,public  CopyCardAction
{
private:
	CellPosition* SourceCard; // // responsible for construction & destruction ( Aggregation )
	Card* CardPtr;//to point at the card , we will set a value to it (not responsible for constructing or destructing it ) ,So the relation is Association
	bool excute; //just to indicate if we will excute or not
public:
	CutCardAction(ApplicationManager* ptr);

	//just check the cell the user entered is valid and also if it has a GameObject( card ) or not 
	virtual void ReadActionParameters();

	//=======================================

	// 1-store the card to  clipboard
	//2-delete the card from the cell 
	virtual void Execute();

	//=======================================

	~CutCardAction();
};

