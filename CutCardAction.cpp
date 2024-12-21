//========By : Mohamed Omar =================

#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"Card.h"
#include"CutCardAction.h"


CutCardAction::CutCardAction(ApplicationManager* ptr) : Action(ptr) //, CopyCardAction(ptr)
{
	SourceCard = new CellPosition(); // responsible for construction & destruction ( Aggregation )
	excute = true;
}



void CutCardAction::ReadActionParameters()
{
	//this->CopyCardAction::ReadActionParameters();// pohymerphism

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
	}
	else
	{
		excute = false;
		return;
	}
}


void CutCardAction::Execute()
{
	ReadActionParameters();
	if (excute)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->SetClipboard(CardPtr);
		pGrid->SetGameObjectToCell(SourceCard, NULL); // we will use func not the remove func , as the remove func deletes the object from the cell and 
		// set the object ptr to NULL and the clipboard has this ptr ,so when it points to Null the clipboard also points to null so it give a run time error  
		
		// ================  INCORRECT : pGrid->RemoveObjectFromCell(*SourceCard);  =========================
		pGrid->PrintErrorMessage(" Cut successfully  ! Click any where to continue...");// m4 error hya bs ashan el print error msge bt3ml clear
		//ll status bar bs 
	}
}


CutCardAction:: ~CutCardAction()
{
	delete SourceCard; // responsible for construction & destruction ( Aggregation )
}