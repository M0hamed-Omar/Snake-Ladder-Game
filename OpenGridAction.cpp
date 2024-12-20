
#include "OpenGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "ladder.h"
#include "Snake.h"
#include "CardOne.h"
#include "Card2.h"
#include "Card3.h"
#include "Card4.h"
#include "Card5.h"
#include "Card6.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"
#include "Card13.h"

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

	inputFileName = pIn->GetSrting(pOut) + ".txt";

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
	inFile.open(inputFileName);
	if (inFile.is_open()) {

		//clears current grid
		pGrid->DeleteAll();
		

		int laddersCount = 0;
		int snakesCount = 0;
		int cardsCount = 0;
		CellPosition tmp1, tmp2; // temporary to intialize objects with;

		inFile >> laddersCount;
		for (int i = 0; i < laddersCount; i++)
		{
			
			Ladder* pLadder = new Ladder(tmp1, tmp2);
			pLadder->Load(inFile);
			pGrid->AddObjectToCell(pLadder);
		}

		inFile >> snakesCount;
		for (int i = 0; i < snakesCount; i++)
		{
			Snake* pSnake = new Snake(tmp1, tmp2);
			pSnake->Load(inFile);
			pGrid->AddObjectToCell(pSnake);
		}

		inFile >> cardsCount;
		for (int i = 0; i < cardsCount; i++)
		{
			int tmpNum = 0;
			inFile >> tmpNum;
			if (tmpNum > 13 || tmpNum < 1)
			{
				pGrid->PrintErrorMessage("There is an invalid cardNum (will skip it and continue)");
					continue;
			}
			Card* pCard;
			switch (tmpNum)
			{
			case 1:
				pCard = new CardOne(tmp1);
				break;
			case 2:
				pCard = new Card2(tmp1);
				break;

			case 3:
				pCard = new Card3(tmp1);
				break;
			case 4:
				pCard = new Card4(tmp1);
				break;
			case 5:
				pCard = new Card5(tmp1);
				break;
			case 6:
				pCard = new Card6(tmp1);
				break;
			case 7:
				pCard = new Card7(tmp1);
				break;
			case 8:
				pCard = new Card8(tmp1);
				break;
			case 9:
				pCard = new Card9(tmp1);
				break;
			case 10:
				pCard = new Card10(tmp1);
				break;
			case 11:
				pCard = new Card11(tmp1);
				break;
			case 12:
				pCard = new Card12(tmp1);
				break;
			case 13:
				pCard = new Card13(tmp1);
				break;
			}

			pCard->Load(inFile);
			pGrid->AddObjectToCell(pCard);
		}
		inFile.close();
		pGrid->ResetFlags();
		pGrid->PrintErrorMessage("Loaded successfully !   Click to see changes");
	}

	else
	{
		pGrid->PrintErrorMessage("Failed to open file");
	}



}

