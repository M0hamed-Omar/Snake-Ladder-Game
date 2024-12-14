#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include"Card.h"
//#include "AddCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* ptr) : Action(ptr) 
{
	DestinationCell = new CellPosition();
	//acPtr = new AddCardAction(ptr);
}
//====================================================

// needs to read some parameters  
	//  1-the clipboard ptr 
	// 2-need to read the destination cell , and check if:
	// i- valid cell 
	// ii- does not have a card 
	
void  PasteCardAction::ReadActionParameters()
{
	// make a pointr to input&output class to get the destination cell  and print messages on status bar

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//==================================

		
	//  1-the clipboard ptr . **Note we do not need to check if the ptr is to card or not as the clipboard accept the CardPtrs only !!! 
			// we will just check if the clipboard has ptr or not 
	if (!pGrid->GetClipboard())
	{
		pGrid->PrintErrorMessage("The clipboard is empty ! Click anywhere to continue....");
		return;
	}
	//get the destination cell
	pOut->PrintMessage("click on the destination cell");//print the message 
	*DestinationCell = pIn->GetCellClicked();// input the  cell that will be coppied 
	pOut->ClearStatusBar();

	//	validation stadge :
	// 1-need to read the destination cell , and check if:
	//i - valid cell
	// ii- does not have a card or any GameObject 
	if (DestinationCell->IsValidCell())// " i " done 
	{
		GameObject* ObjPtr = pGrid->GetGameObjectFromCell(*DestinationCell);
		if (ObjPtr)//" ii " done
		{
			pGrid->PrintErrorMessage("Error: The cell already has an GameObject ! Click anywhere to continue...");
			return;
		}
	
			
			
		
		pGrid->PrintErrorMessage("Pasted successfully ! Click anywhere to continue....");
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid Cell ! Click anywhere to continue....");
		return;
	}
}
//================================================

// now we need to add the card to the chosen cell & clear the clipboard
void PasteCardAction::Execute()
{
	ReadActionParameters();
	//acPtr->ReadActionParameters();
	//acPtr->Execute();
	Grid* pGrid = pManager->GetGrid();
	bool added =pGrid->AddObjectToCell((GameObject*)pGrid->GetClipboard(), DestinationCell);//put the object in the destination cell using "Up Casting" from Card to GameObject
	if (added)
	{
		pGrid->SetClipboard(nullptr);//kda akenna 4elna el ptr mn el clipboard
	}
}

PasteCardAction:: ~PasteCardAction()
{
	delete DestinationCell;
}