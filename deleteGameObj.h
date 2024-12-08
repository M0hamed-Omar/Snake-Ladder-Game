#pragma once

#include"Action.h"

class deleteGameObj:public Action
{
	CellPosition StartObjCell;
	
public:

	deleteGameObj(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters 

	virtual void Execute(); // delete Object on  the cell position
	
	virtual ~deleteGameObj(); // A Virtual Destructor
};

