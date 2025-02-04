#include "ToDesignModeAction.h"
#include "Grid.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
}// Constructor

// ============ Virtual Functions ============
void ToDesignModeAction::ReadActionParameters()
{
}//No parameters

void ToDesignModeAction::Execute()// Executes action
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
	pGrid->resetAllPlayers(); //resets the position of all players and resets their wallet to contain 100
	pGrid->SetCurrentPlayer(0); // sets the current player to be player 0;
	pGrid->resetStations(); //Resets the ownership of all stations in the grid
	pGrid->SetEndGame(false); //sets the end game flag to false

}

ToDesignModeAction::~ToDesignModeAction()
{

}