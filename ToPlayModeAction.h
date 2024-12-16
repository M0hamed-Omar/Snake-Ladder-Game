#pragma once
#include "Action.h"
class ToPlayModeAction : public Action
{

public:

	ToPlayModeAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); //No parameters

	virtual void Execute();  // Executes action

	 ~ToPlayModeAction();  
};



