#pragma once
#include"Action.h"
class CopyCardAction :public Action {
	
	Card* CardPtr;//to point at the card ( Association )
	CellPosition* SourceCard; // // responsible for construction & destruction ( Aggregation )
public:
	CopyCardAction (ApplicationManager* ptr) ;
	// this class is not responsible for destruction or constrcution the ApplicationManager pointer  
	//=======================================

	/*Read the needed info. about the operation  , this info. :
	1- the distination position to put  card copied at //Done
	2-the card details : number , the action done by the card 
	*/
	virtual void ReadActionParameters();

	//=======================================
	// store the card to  clipboard
	
	virtual void Execute();
	
	//=======================================
	
	~CopyCardAction();
};
