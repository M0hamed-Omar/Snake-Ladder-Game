
#include "OpenGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

OpenGridAction::~OpenGridAction()
{
}

void OpenGridAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the outputFileName parameter
	pOut->PrintMessage("Enter the filename to load grid from . . .");

	outputFileName = pIn->GetSrting(pOut) + ".txt";

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void OpenGridAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//Opens a file with the read string from prev func
	ifstream inFile;
	inFile.open(outputFileName);
	if (inFile.is_open()) {
		
		pGrid->PrintErrorMessage("Loaded successfully !");
		inFile.close();
	}
	else
	{
		pGrid->PrintErrorMessage("Failed to open file");
	}



}

