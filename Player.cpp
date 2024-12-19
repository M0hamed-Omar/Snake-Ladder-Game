#include "Player.h"

#include "GameObject.h"
#include "Card.h"
#include "Card8.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======
void Player::ResetPlayer(Grid *pGrid)
{
	CellPosition zeroCell(NumVerticalCells - 1, 0 ); //distination Cell (first cell of the grid)
		pGrid->UpdatePlayerCell(this,zeroCell );
	turnCount = 0;
	stepCount = 0;
	wallet = 100;

}

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	if (this->wallet < 0)
	{
		this->wallet = 0;
	}
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::setJustRolledDiceNum(int dicenum)
{
	this->justRolledDiceNum = dicenum;
}

int Player::GetJustRolledDiceNum() const
{
	return justRolledDiceNum;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	CellPosition playerPosition = pCell->GetCellPosition();

	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(playerPosition, playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	CellPosition playerPosition = pCell->GetCellPosition();
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(playerPosition, playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;

	if (pCell->HasCard()) // check if i have card 8 so i won't move but by that logic the player is stuck at this cell and can't move to the rest of the game i need a counter Maybe
	{                      // another quaestion what will be the apply of the card 8 ?  
		Card8* pCard8 = dynamic_cast<Card8*>(pCell->GetGameObject());
		
		if (pCard8)
		{
			diceNumber = 0;
		}
	}
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3)
	{
		SetWallet(10 * diceNumber);
		turnCount = 0;
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	setJustRolledDiceNum(diceNumber);
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	if (GetWallet() > 0)
	{
		CellPosition& pos = pCell->GetCellPosition();
		pos.AddCellNum(diceNumber);
		pGrid->UpdatePlayerCell(this,pos);
		if (pCell->HasCard() || pCell->HasSnake() || pCell->HasLadder())
		{
			GameObject* gameobj = pCell->GetGameObject();
			gameobj->Apply(pGrid,this);
		}
		
		bool checkEnd = (this->GetCell()->GetCellPosition().GetCellNum() >= 99);
		pGrid->SetEndGame(checkEnd);
		
	}
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}