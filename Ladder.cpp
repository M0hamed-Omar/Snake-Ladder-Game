#include "Ladder.h"


Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if(startCellPos.GetCellNum()<endCellPos.GetCellNum())
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	// ============done by M.Omar=============
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

void Ladder::Save(ofstream& OutFile, ObjectType Obj) 
{
	if (Obj != LadderObj)
		return;

	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}
 void Ladder::Load(ifstream& Infile)
 {
	 int start, end;
	 Infile >> start >> end;
	 position = position.GetCellPositionFromNum(start);
	 endCellPos = position.GetCellPositionFromNum(end);
}

 bool Ladder::IsOverLapping(GameObject* Obj)
 {
	 if (Ladder* pLadder = dynamic_cast<Ladder*>(Obj))
	 {
		 if (position.HCell() == pLadder->GetPosition().HCell() && ( endCellPos.VCell() < pLadder->GetPosition().VCell() || pLadder->GetEndPosition().VCell() < position.VCell()  ))
			 return true;
	 }
	 return false;
 }

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
