#pragma once
#include "Action.h"
class ToDesignModeAction : public Action
{

public:

	ToDesignModeAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); //No parameters

	virtual void Execute();  // Executes action

	~ToDesignModeAction();
};



