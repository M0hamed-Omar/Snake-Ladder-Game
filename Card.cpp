#include "Card.h"


Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	if (cnum >= 1 && cnum <= 13)
	{
		cardNumber = cnum; // needs validation
	}
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position,this->cardNumber);//done by omar 
	//the position is come from the base class "GameObject"

}
void Card:: DrawNew(CellPosition cPos)
{
	position = cPos;
}
void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, ObjectType Obj)
{

	OutFile << cardNumber << " " << position.GetCellNum();
}

void Card::Load(ifstream& Infile)
{
	int cellNum;
		Infile >> cellNum;
	position = position.GetCellPositionFromNum(cellNum);
}

Card::~Card()
{
}
