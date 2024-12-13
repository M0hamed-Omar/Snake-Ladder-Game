#pragma once
#include"Action.h"
class CopyCardAction :public Action {
	
	Card* CardPtr;//to point at the card ( Association )
	CellPosition* SourceCard; // // responsible for construction & destruction ( Aggregation )
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
