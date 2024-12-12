#pragma once

#include"Action.h"

class deleteGameObj:public Action
{
	CellPosition StartObjCell;
public:

	deleteGameObj(ApplicationManager* pApp); // A Constructor

	 void ReadActionParameters(); // Reads AddCardAction action parameters 

	 void Execute(); // delete Object on  the cell position
	
	 ~deleteGameObj(); // A Virtual Destructor
};

