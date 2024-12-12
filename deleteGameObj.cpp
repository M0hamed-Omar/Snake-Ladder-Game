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
	

		
	pOut->ClearStatusBar();
}


//========================================


void deleteGameObj::Execute()
{		
	    this->ReadActionParameters();
		Grid* ptr = pManager->GetGrid();
		ptr->RemoveObjectFromCell(StartObjCell);
		
		ptr->UpdateInterface();
	
	

}
//======================================

deleteGameObj::~deleteGameObj()
{
}
