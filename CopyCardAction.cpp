//===== BY Mohamed Omar =========
#include"CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include"Card.h"

CopyCardAction::CopyCardAction(ApplicationManager* ptr) : Action(ptr)
{
	SourceCard = new CellPosition(); // responsible for construction & destruction ( Aggregation )
	excute = true;
}

void CopyCardAction::ReadActionParameters()
{
	// make a pointr to input&output class to get the source card  and print messages on status bar

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//==================================

	//get the source card 
	pOut->PrintMessage("click on the source cell");//print the message 
	*SourceCard = pIn->GetCellClicked();// input the  cell that will be coppied 
	pOut->ClearStatusBar();
	//	validation stadge :
   //   1- is a valid cell     2- is the cell contain a card  ( dynamic cast from gameobject to card)
	if (SourceCard->IsValidCell())
	{
		CardPtr = dynamic_cast<Card*>(pGrid->GetGameObjectFromCell(*SourceCard));
		if (!CardPtr)
		{
			pGrid->PrintErrorMessage("The cell does not have a Card ! Click any where to continue...");
			excute = false;
			return;
		}
		else
			pGrid->PrintErrorMessage(" Copied successfully  ! Click any where to continue...");// m4 error hya bs ashan el print error msge bt3ml clear
		//ll status bar bs 
	}
	else
	{
		excute = false;
		return;
	}
}


//========================================


// just store the card to the clipboard
void CopyCardAction::Execute()
{
	ReadActionParameters();
	if (excute)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->SetClipboard(CardPtr);
	}
}
//======================================

CopyCardAction:: ~CopyCardAction()
{
	delete SourceCard; // responsible for construction & destruction ( Aggregation )
}