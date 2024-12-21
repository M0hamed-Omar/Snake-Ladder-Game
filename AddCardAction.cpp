#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
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

AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	excute = true;
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("type card number");
	int TempCardNumber = pIn->GetInteger(pOut);
	// TemporaryCardNumber to validate it before assign it to the CardNumber parameter
	// validate the temporary card number 
	if (TempCardNumber < 1 || TempCardNumber>13)
	{
		pGrid->PrintErrorMessage("Invalid Card, Click anywhere to continue....");
		return;
	}
	CardNumber = TempCardNumber;
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("click on card cell");
	CardPosition = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters

	//the needed validations are :
	// 1- is valid cell
	// 2-the cell clicked does not have any game object

	//======= first validation  ==========
	if (!CardPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("The cell you entered is invalid cell ! click any where to continue...");
		excute = false;
		return;
	}
	//=======second validation========
	if (pGrid->GetGameObjectFromCell(CardPosition))
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		excute = false;
		return;
	}


	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	if (excute)
	{
		// 2- Switch case on cardNumber data member and create the appropriate card object type
		Card* pCard = NULL; // will point to the card object type
		switch (CardNumber)
		{
		case 1:
			pCard = new CardOne(CardPosition);
			break;
		case 2:
			pCard = new Card2(CardPosition);
			break;
		case 3:
			pCard = new Card3(CardPosition);
			break;
		case 4:
			pCard = new Card4(CardPosition);
			break;
		case 5:
			pCard = new Card5(CardPosition);
			break;
		case 6:
			pCard = new Card6(CardPosition);
			break;
		case 7:
			pCard = new Card7(CardPosition);
			break;
		case 8:
			pCard = new Card8(CardPosition);
			break;
		case 9:
			pCard = new Card9(CardPosition);
			break;
		case 10:
			pCard = new Card10(CardPosition);
			break;
		case 11:
			pCard = new Card11(CardPosition);
			break;
		case 12:
			pCard = new Card12(CardPosition);
			break;
		case 13:
			pCard = new Card13(CardPosition);
			break;
		}

		// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pCard)
		{
			// A- We get a pointer to the Grid from the ApplicationManager
			Grid* pGrid = pManager->GetGrid();
			// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
			pCard->ReadCardParameters(pGrid);
			// C- Add the card object to the GameObject of its Cell:
			bool Added = pGrid->AddObjectToCell(pCard);
			// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
			if (!Added)
			{
				pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			}
		}
		// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
	}
}