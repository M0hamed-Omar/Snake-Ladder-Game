#include "NewGameAction.h"
#include "Grid.h"
NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->resetAllPlayers(); //resets the position of all players and resets their wallet to contain 100
	pGrid->SetCurrentPlayer(0); // sets the current player to be player 0;
	pGrid->resetStations(); //Resets the ownership of all stations in the grid
	
}

NewGameAction::~NewGameAction()
{
}