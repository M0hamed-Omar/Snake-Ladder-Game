#pragma once
#include "Action.h"
class OpenGridAction :	public Action
{
	// [Action Parameters]
	string outputFileName; // name of the file to create and write in or if it already exsists overwite it

	// Note: These parameters should be read in ReadActionParameters()

public:
	OpenGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads action parameters (filename)

	virtual void Execute(); // opens a file to write into with passed parameteres then saves all game objects to it and closes after

	virtual ~OpenGridAction(); // A Virtual Destructor
};
