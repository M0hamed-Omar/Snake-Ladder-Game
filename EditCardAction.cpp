//========= By : Mohamed Omar ==============

#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"
#include "CardOne.h"
#include "Card2.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"
#include "Card13.h"
EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
	excute = true;
	pos = new CellPosition;
}
EditCardAction:: ~EditCardAction()
{
	delete pos;
}
void EditCardAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "card" parameter and set its data member
	pOut->PrintMessage(" Click on the source to edit");
	*pos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 3- Make the needed validations on the read parameters
	//i- is valid cell 
	//ii- has a card 
	//iii-the card number is : 1 or 2 or 9 or [10 :13 ]
	if (!pos->IsValidCell()) // i-> done
	{
		pGrid->PrintErrorMessage("Invalid cell ! Click anywhere to continue....");
		excute = false;
		return;
	}
	if (!pGrid->HasCard(*pos)) // ii -> done
	{
		pGrid->PrintErrorMessage("The cell clicked does not have a card ! Click anywhere to continue.... ");
		excute = false;
		return;
	}
	Card* ptr = dynamic_cast<Card*>(pGrid->GetGameObjectFromCell(*pos));
	crd = ptr;

	if (crd->GetCardNumber() == 3 || crd->GetCardNumber() == 4 || crd->GetCardNumber() == 5 || crd->GetCardNumber() == 6 || crd->GetCardNumber() == 7 || crd->GetCardNumber() == 8)
		// iii->done
	{
		pGrid->PrintErrorMessage("This card is not Modifiable ! Click anywhere to continue ....");
		excute = false;
		return;
	}
}

void EditCardAction::Execute()
{
	ReadActionParameters();
	// Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (excute)
	{
		int cardnum = crd->GetCardNumber();
		switch (cardnum)
		{
		case 1:
		{
			CardOne* ptr = dynamic_cast<CardOne*>(crd); // to convert from card ptr to card 1
			if (ptr)
			{
				pOut->PrintMessage(" Enter the new wallet amount ....");
				int newAmount = pIn->GetInteger(pOut);
				ptr->SetWalletAmount(newAmount);
				pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue...");
			}
			break;
		}
		case 2:
		{
			Card2* ptr2 = dynamic_cast<Card2*>(crd); // to convert from card ptr to card 2
			if (ptr2)
			{
				pOut->PrintMessage(" Enter the new wallet amount ....");
				int newAmount = pIn->GetInteger(pOut);
				ptr2->SetWalletAmount2(newAmount);
				pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue...");
			}
			break;
		}
		case 9:
		{
			Card9* ptr9 = dynamic_cast<Card9*>(crd); // to convert from card ptr to card 9
			if (ptr9)
			{
				pOut->PrintMessage("Write the New Cell number to be moved to . . . ");
				int num = pIn->GetInteger(pOut);
				ptr9->SetDestinationCell(num);
				pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue...");
			}
			break;
		}
		case 10:
		{
			Card10* ptr10 = dynamic_cast<Card10*>(crd);
			if (ptr10)
			{
				//===== Asking about Card price ===========
				pOut->PrintMessage("Will you change the card price ? ..... Answer with \"Yes\" or \"No\" ");
				string answer = pIn->GetSrting(pOut);
				if (answer == "Yes" || answer == "yes")
				{
					pOut->PrintMessage("Enter the new price...");
					int p = pIn->GetInteger(pOut);
					if (p < 0)
					{
						pGrid->PrintErrorMessage("Invalid price ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr10->SetCardPrice(p);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
				//==============================
				//======== Asking about Fee ===================
				pOut->PrintMessage("Will you change the Fee ? ..... Answer with \"Yes\" or \"No\" ");
				string fee = pIn->GetSrting(pOut);
				if (fee == "Yes" || fee == "yes")
				{
					pOut->PrintMessage("Enter the new Fee...");
					int f = pIn->GetInteger(pOut);
					if (f < 0)
					{
						pGrid->PrintErrorMessage("Invalid Fee ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr10->SetFee(f);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
			}
			break;
		}
		case 11:
		{
			Card11* ptr11 = dynamic_cast<Card11*>(crd);
			if (ptr11)
			{
				//===== Asking about Card price ===========
				pOut->PrintMessage("Will you change the card price ? ..... Answer with \"Yes\" or \"No\" ");
				string answer = pIn->GetSrting(pOut);
				if (answer == "Yes" || answer == "yes")
				{
					pOut->PrintMessage("Enter the new price...");
					int p = pIn->GetInteger(pOut);
					if (p < 0)
					{
						pGrid->PrintErrorMessage("Invalid price ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr11->SetCardPrice(p);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
				//==============================
				//======== Asking about Fee ===================
				pOut->PrintMessage("Will you change the Fee ? ..... Answer with \"Yes\" or \"No\" ");
				string fee = pIn->GetSrting(pOut);
				if (fee == "Yes" || fee == "yes")
				{
					pOut->PrintMessage("Enter the new Fee...");
					int f = pIn->GetInteger(pOut);
					if (f < 0)
					{
						pGrid->PrintErrorMessage("Invalid Fee ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr11->SetFee(f);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
			}
			break;
		}
		case 12:
		{
			Card12* ptr12 = dynamic_cast<Card12*>(crd);
			if (ptr12)
			{
				//===== Asking about Card price ===========
				pOut->PrintMessage("Will you change the card price ? ..... Answer with \"Yes\" or \"No\" ");
				string answer = pIn->GetSrting(pOut);
				if (answer == "Yes" || answer == "yes")
				{
					pOut->PrintMessage("Enter the new price...");
					int p = pIn->GetInteger(pOut);
					if (p < 0)
					{
						pGrid->PrintErrorMessage("Invalid price ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr12->SetCardPrice(p);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
				//==============================
				//======== Asking about Fee ===================
				pOut->PrintMessage("Will you change the Fee ? ..... Answer with \"Yes\" or \"No\" ");
				string fee = pIn->GetSrting(pOut);
				if (fee == "Yes" || fee == "yes")
				{
					pOut->PrintMessage("Enter the new Fee...");
					int f = pIn->GetInteger(pOut);
					if (f < 0)
					{
						pGrid->PrintErrorMessage("Invalid Fee ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr12->SetFee(f);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
			}
			break;
		}
		case 13:
		{
			Card13* ptr13 = dynamic_cast<Card13*>(crd);
			if (ptr13)
			{
				//===== Asking about Card price ===========
				pOut->PrintMessage("Will you change the card price ? ..... Answer with \"Yes\" or \"No\" ");
				string answer = pIn->GetSrting(pOut);
				if (answer == "Yes" || answer == "yes")
				{
					pOut->PrintMessage("Enter the new price...");
					int p = pIn->GetInteger(pOut);
					if (p < 0)
					{
						pGrid->PrintErrorMessage("Invalid price ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr13->SetCardPrice(p);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
				//==============================
				//======== Asking about Fee ===================
				pOut->PrintMessage("Will you change the Fee ? ..... Answer with \"Yes\" or \"No\" ");
				string fee = pIn->GetSrting(pOut);
				if (fee == "Yes" || fee == "yes")
				{
					pOut->PrintMessage("Enter the new Fee...");
					int f = pIn->GetInteger(pOut);
					if (f < 0)
					{
						pGrid->PrintErrorMessage("Invalid Fee ! Click anywhere to continue...");
						return;
					}
					else
					{
						ptr13->SetFee(f);
						pGrid->PrintErrorMessage("Set Successfully ! Click anywhere to continue... ");
					}
				}
				else
				{
					pOut->ClearStatusBar();
				}
			}
			break;
		}
		}
	}
}

