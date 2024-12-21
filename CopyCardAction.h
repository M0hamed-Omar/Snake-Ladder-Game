//=============By : Mohamed Omar ============
#pragma once
#include"Action.h"
class CopyCardAction :public Action {
	
	Card* CardPtr;//to point at the card , we will set a value to it (not responsible for constructing or destructing it ) ,So the relation is Association
	CellPosition* SourceCard; // // responsible for construction & destruction ( Aggregation )
	bool excute; //just to indicate if we will excute or not
public:
	CopyCardAction (ApplicationManager* ptr) ;
	

	//just check the cell the user entered is valid and also if it has a GameObject or not 
	virtual void ReadActionParameters();
	
	//=======================================
	
	// store the card to  clipboard
	virtual void Execute();
	
	//=======================================
	
	~CopyCardAction();
};
