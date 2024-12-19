#include "SaveGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the outputFileName parameter
	pOut->PrintMessage("Enter the filename to save into . . .");
	
	outputFileName = pIn->GetSrting(pOut) + ".txt";
	
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void SaveGridAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//Opens a file with the read string from prev func
	ofstream outFile;
	outFile.open(outputFileName);
	if (outFile.is_open()) {
		//counts all Game Objects first 
		int laddersCount, snakesCount, cardsCount;
		pGrid->countGameObjects(laddersCount, snakesCount, cardsCount);
		outFile << laddersCount << endl;
		pGrid->SaveAll(outFile, LadderObj);
		outFile << snakesCount << endl;
		pGrid->SaveAll(outFile, SnakeObj);
		outFile << cardsCount << endl;
		pGrid->SaveAll(outFile, CardObj);
		pGrid->PrintErrorMessage("Saved successfully !");
		outFile.close();
	}
	else
	{
		pGrid->PrintErrorMessage("Failed to open file");
	}



}

