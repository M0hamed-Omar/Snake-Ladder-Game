#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	int burnAttackNum;
	int freezeAttackNum;
	int poisonAttackNum;
	int lightningAttackNum;

	int isburned; // to track burned player
	int ispoisoned; // to track poisoned player
	bool isfrozen; // to track frozen player


	
	bool isMoving;
	
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount
	void setJustRolledDiceNum(int dicenum);
	int GetJustRolledDiceNum() const; // A getter for the JustRollDice  ==>> added by Medhat
	int getPlayerNum() const;
	void setPlayerState(bool state); // to change isMoving state
	bool getPlayerState() const;

	///TODO: You can add setters and getters for data members here (if needed)
	void ResetPlayer(Grid*);
	void decrementTurnCount();
	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

	void LightiningAttack(Grid* pGrid);
	void BurnAttack(Grid* pGrid,int targetPlayer);
	void PoisonAttack(Grid* pGrid, int targetPlayer);
	void FreezeAttack(Grid* pGrid, int targetPlayer);

	bool stillHaveAttack(); // checks if the player can attack or not ( 2 attacks only per player)
	void decrementWallet(int amount); // decrements the wallet by the amount passed
	void makeBurned(); // sets the player to be burned
	void makePoisoned(); // sets the player to be poisoned
	void makeFrozen(); // sets the player to be frozen
	bool getFrozenState() const;
	void setFrozenState(bool state);
	bool canAttack();
};

