#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Grid* pGrid = pManager->GetGrid();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game Already Ended .. Please Start a new game");
		return;
	}
	// -- If not ended, do the following --:
	
	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
	if (pGrid->GetCurrentPlayer()->getPlayerState() == false) {
		diceNumber = 0;
		pGrid->PrintErrorMessage("You aren't allowed to move, click to continue..");
	}

	if (pGrid->GetCurrentPlayer()->getFrozenState() == true)
	{
		diceNumber = 0;
		pGrid->PrintErrorMessage("You are Frozen, click to continue..");
		pGrid->GetCurrentPlayer()->setFrozenState(!pGrid->GetCurrentPlayer()->getFrozenState());
	}

	pGrid->PrintErrorMessage( to_string(diceNumber) +"      Click to Apply, player "+to_string(pGrid->GetCurrentPlayer()->getPlayerNum()));
	// 3- Get the "current" player from pGrid
	Player* pCurrentPlayer = pGrid->GetCurrentPlayer();

	// 4- Move the currentPlayer using function Move of class player

	pCurrentPlayer->Move(pGrid, diceNumber);

	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>> CHECK FIRST IS THAT CARD 8 OR NOT <<<<<<<<<<<<---------------------
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
