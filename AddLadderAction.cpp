#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Error: Invalid Cell ! Click to continue ...");
		return;
	}
	if (startPos.VCell() < endPos.VCell() || startPos.HCell() != endPos.HCell() )
	{
		pGrid->PrintErrorMessage("Error: Invalid Ladder position! Click to continue ...");
		startPos = endPos = CellPosition(-1, -1);
		return;
	}
	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		return;
	}
	// Create a Ladder object with the parameters read from the user
	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	if (pGrid->isOverlapping(pLadder))
	{
		pGrid->PrintErrorMessage("Error: Overlapping! Click to continue ...");
		return;
	}

			// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

			// if the GameObject cannot be added
	if (!added)
	{
				// Print an appropriate message
				pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	else
	{
		pGrid->PrintErrorMessage("Ladder added successfully! Click to continue ...");
	}
}
// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderActi