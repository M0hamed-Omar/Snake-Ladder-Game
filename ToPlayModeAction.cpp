#include "ToPlayModeAction.h"
#include "Grid.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
}// Constructor

// ============ Virtual Functions ============
 void ToPlayModeAction::ReadActionParameters()
{
}//No parameters

 void ToPlayModeAction::Execute()// Executes action
 {
	 Grid* pGrid = pManager->GetGrid();
	 Output* pOut = pGrid->GetOutput();
	 pOut->CreatePlayModeToolBar();
	 pGrid->resetAllPlayers(); //resets the position of all players and resets their wallet to contain 100
	 pGrid->SetCurrentPlayer(0); // sets the current player to be player 0;
	 pGrid->resetStations(); //Resets the ownership of all stations in the grid
	 pGrid->SetEndGame(false); //sets the end game flag to false
	 
 }

 ToPlayModeAction::~ToPlayModeAction()
 {

}
