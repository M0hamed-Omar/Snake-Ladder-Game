#include "SpecialAttacksAction.h"


#include "Grid.h"
#include "Player.h"

SpecialAttacksAction::SpecialAttacksAction(ApplicationManager* pApp) : Action(pApp)
{
	attackNumber = -1;
}

void SpecialAttacksAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Action Value : 1->Burn  2->Freeze  3->Poison  4->Lightining");

	attackNumber = pIn->GetInteger(pOut);
	if (attackNumber < 1 || attackNumber > 6)
	{
		attackNumber = -1;
		return;
	}

}

void SpecialAttacksAction::Execute()
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
	if (attackNumber == -1)
	{
		pGrid->PrintErrorMessage("Invalid Atttack Value !");
		return;
	}

	// 3- Get the "current" player from pGrid
	Player* pCurrentPlayer = pGrid->GetCurrentPlayer();

	int turnCount = pCurrentPlayer->GetTurnCount(); // get the turn count of the current player to check if he can attack or not
	if (turnCount != 2) 
	{
		pGrid->PrintErrorMessage("You Can only attack on the third roll (turn 2)");
		return;
	}
	if (!pCurrentPlayer->CanAttack())
	{
		pGrid->PrintErrorMessage("You Can only attack twice per Game");
		return;
	}

	// 4- Switch case on the "attackNumber" to perform the appropriate action
	
	switch (attackNumber)
	{
	case 1:
		pCurrentPlayer->LightiningAttack(pGrid);
		break;
		
	case 2:
		pCurrentPlayer->BurnAttack(pGrid);
		break;
	case 3:
		pCurrentPlayer->FreezeAttack(pGrid);
		break;
	case 4:
		pCurrentPlayer->PoisonAttack(pGrid);
		break;
	default:
		return;
		
	}

	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	pOut->ClearStatusBar();
	//------------->>>>>>>>>>>>>>>>>>>>>>>>>>>> CHECK FIRST IS THAT CARD 8 OR NOT <<<<<<<<<<<<---------------------
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

SpecialAttacksAction::~SpecialAttacksAction()
{
}
