//================By : Mohamed Omar=============
#pragma once
#include"Action.h"
//#include "CopyCardAction.h"
class CutCardAction :public Action//,public  CopyCardAction
{
private:
	/*CopyCardAction* coPtr;  //  (the relation is Agg. as we responsible for construcing & destructing this ptr
	 we will use this pointer becauce the functionality of the copy card is the same as cut card ,but cut will remove the card from the cell
	 */
	CellPosition* SourceCard; // // responsible for construction & destruction ( Aggregation )
	Card* CardPtr;//to point at the card ( Association )
public:
	CutCardAction(ApplicationManager* ptr);

	//just check the cell the user entered is valid and also if it has a GameObject or not 
	virtual void ReadActionParameters();

	//=======================================

	// 1-store the card to  clipboard
	//2-delete the card from the cell 
	virtual void Execute();

	//=======================================

	~CutCardAction();
};

