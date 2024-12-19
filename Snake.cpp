#include"Snake.h"
#include "Ladder.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");


	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);


}
bool Snake::IsOverLapping(GameObject* Obj)
{
	if (Snake* pSnake = dynamic_cast<Snake*>(Obj))
	{
		if (position.HCell() == pSnake->GetPosition().HCell())
		{
			if (endCellPos.VCell() < pSnake->GetPosition().VCell() || pSnake->GetEndPosition().VCell() < position.VCell())
				return false;
			else
				return true;
		}
	}
	else if (Ladder* pLadder = dynamic_cast<Ladder*>(Obj))
	{
		if (position.HCell() == pLadder->GetPosition().HCell())
		{
			if (pLadder->GetPosition().VCell() == endCellPos.VCell())
				return true;
		}
	}
	return false;

}
void Snake::Save(ofstream& OutFile, ObjectType Obj)
{
	if (Obj != SnakeObj)
		return;

	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Snake::Load(ifstream& Infile)
{
	int start, end;
	Infile >> start >> end;
	position = position.GetCellPositionFromNum(start);
	endCellPos = position.GetCellPositionFromNum(end);
}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
