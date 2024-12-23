#include "InputDiceAction.h"

#include "Grid.h"
#include "Player.h"

InputDiceAction::InputDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Input Dice Value : (1 to 6)");

	 diceNum = pIn->GetInteger(pOut);
	if (diceNum < 1 || diceNum > 6)
	{
		diceNum = -1;
		return;
	}

}

void InputDiceAction::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game Already Ended .. Please Start a new game");
		return;
	}
	// -- If not ended, do the following --:
	if (diceNum == -1)
	{
		pGrid->PrintErrorMessage("Invalid Dice Value !");
		return;
	}
	if (pGrid->GetCurrentPlayer()->getPlayerState() == false) {
		diceNum = 0;
		pGrid->PrintErrorMessage("You aren't allowed to move, click to continue..");
	}

	if (pGrid->GetCurrentPlayer()->getFrozenState() == true)
	{
		diceNum = 0;
		pGrid->PrintErrorMessage("You are Frozen, click to continue..");
		pGrid->GetCurrentPlayer()->setFrozenState(!pGrid->GetCurrentPlayer()->getFrozenState());
	}
	// 3- Get the "current" player from pGrid
	Player* pCurrentPlayer = pGrid->GetCurrentPlayer();

	// 4- Move the currentPlayer using function Move of class player

	pCurrentPlayer->Move(pGrid, diceNum);

	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	pOut->ClearStatusBar();
	//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>> CHECK FIRST IS THAT CARD 8 OR NOT <<<<<<<<<<<<---------------------
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

InputDiceAction::~InputDiceAction()
{
}
