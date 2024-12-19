#include "InputDiceAction.h"

#include "Grid.h"
#include "Player.h"

InputDiceAction::InputDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void InputDiceAction::Execute()
{


	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game Already Ended .. Please Start a new game");
	}
	// -- If not ended, do the following --:
	
	pOut->PrintMessage("Please Input Dice Value : (1 to 6)");
	
	int diceNumber = pIn->GetInteger(pOut);
	if (diceNumber < 1 || diceNumber > 6)
	{
		pGrid->PrintErrorMessage("Invalid Dice Value !");
		return;
	}

	// 3- Get the "current" player from pGrid
	Player* pCurrentPlayer = pGrid->GetCurrentPlayer();

	// 4- Move the currentPlayer using function Move of class player
	pCurrentPlayer->Move(pGrid, diceNumber);

	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	pOut->ClearStatusBar();
	//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>> CHECK FIRST IS THAT CARD 8 OR NOT <<<<<<<<<<<<---------------------
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

InputDiceAction::~InputDiceAction()
{
}
