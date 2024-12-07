#include"CopyCardAction.h"

#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"Card.h"

CopyCardAction::CopyCardAction(ApplicationManager* ptr) : Action(ptr)
{
	SourceCard = new CellPosition(); // responsible for construction & destruction ( Aggregation )
	CardPtr = NULL; // Association 
}

void CopyCardAction::ReadActionParameters()
{
	// make a pointr to input&output class to get the DestinationNumber and print messages on status bar

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//==================================

	//get the source card 
	pOut->PrintMessage("click on the source cell");//print the message 
	*SourceCard = pIn->GetCellClicked();// input the  cell that will be coppied 

	//	validation stadge :
   //   1- is a valid cell     2- is the cell contain a card  ( dynamic cast from gameobject to card)
	if (SourceCard->IsValidCell())
	{

		GameObject* ObjPtr = pGrid->GetGameObjectFromCell(*SourceCard);
		CardPtr = dynamic_cast<Card*>(ObjPtr);
		if (CardPtr)
		{
			pOut->ClearStatusBar();
		}
		else return;
	}
	else return;
}


//========================================


// just store the card to the clipboard
void CopyCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->SetClipboard(CardPtr);
}
//======================================

CopyCardAction:: ~CopyCardAction()
{
	delete SourceCard; // responsible for construction & destruction ( Aggregation )
}