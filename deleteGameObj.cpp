#include "deleteGameObj.h"


#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"Card.h"
#include"Snake.h"
#include"Ladder.h"
#include"GameObject.h"

deleteGameObj::deleteGameObj(ApplicationManager* ptr) : Action(ptr)
{
	
}


//======================================


void deleteGameObj::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage("Delete Game Object: Click on its Start Cell ...");
	StartObjCell = pIn->GetCellClicked();
	if (!StartObjCell.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid cell ! Click anywhere to continue....");
		return;
	}
	if (!pGrid->GetGameObjectFromCell(StartObjCell))
	{
		pGrid->PrintErrorMessage("The cell does not have an object ! Click anywhere to continue....");
		return;
	}
	pGrid->PrintErrorMessage("Deleted successfully , Click anywhere to continue....");
		
	pOut->ClearStatusBar();
}


//========================================


void deleteGameObj::Execute()
{		
	this->ReadActionParameters();
	Grid* ptr = pManager->GetGrid();
	ptr->RemoveObjectFromCell(StartObjCell);
	
}
//======================================

deleteGameObj::~deleteGameObj()
{
}
