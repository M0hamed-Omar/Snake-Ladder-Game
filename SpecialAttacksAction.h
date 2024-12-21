#pragma once
#include "Action.h"


class SpecialAttacksAction :	public Action
{
	int attackNumber; // The Number of the Attack
protected:
	int howManyOccured; // Number of Ocurance of each attack; 
public:
	SpecialAttacksAction(ApplicationManager* pApp); // A Constructor
	virtual void ReadActionParameters(); // Reads Special Attacks Parameters
	virtual void Execute(); // Executes Special Attacks
	virtual ~SpecialAttacksAction(); // Virtual Destructor
};

