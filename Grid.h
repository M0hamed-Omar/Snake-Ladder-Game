#pragma once

#include "UI_Info.h"
#include "DEFS.h"

#include "Input.h"
#include "Output.h"
#include "CellPosition.h"
#include "fstream"

// forward declarations (the includes are in the cpp)
class Cell;
class GameObject;
class Ladder;
class Snake;
class Card;
class Player;

class Grid
{
	Output * pOut;   // A pointer to the Output object
	Input * pIn;     // A pointer to the Input object

	Cell * CellList[NumVerticalCells][NumHorizontalCells];  // An array of "Pointers" to All Cells of the Grid Cells
															// We make it array of pointers not objects because
															// there are NO default constructor for class Cell

	Player* PlayerList[MaxPlayerCount]; // An array of "Pointers" to the Players of the Game (MaxPlayerCount Players)
	int currPlayerNumber;   // The player number that has the turn to play 
							// currPlayerNumber is: from 0 to MaxPlayerCount - 1

	Card * Clipboard;	   // This is used in copy/cut/paste card (should be set in copy/cut and got in paste)

	bool endGame;	       // A boolean indicating if the Game is ended or not (a player reaches the end cell of the grid or not)

public:

	Grid(Input * pIn, Output * pOut);	  // Gives the Grid a Pointer to the Output Object and the Input Object
										  // and makes any needed initializations

	// ========= Adding or Removing GameObjects to Cells =========

	bool AddObjectToCell(GameObject * pNewObject);		 // Adds a GameObject to the Cell of its "position" data member
	                                                     // only if the Cell does NOT already contain an object, 
	                                                     // otherwise return false and don't add

	void RemoveObjectFromCell(const CellPosition & pos); // Removes the GameObject of the Cell of the passed "position"

	void UpdatePlayerCell(Player * player, const CellPosition & newPosition); // Update the player's pCell with the CellList's Cell pointer of the "newPosition",
	                                                                          // Clears the player's circle from the previous cell
	    																	  // and  Draws it in the new cell

	// ========= Setters and Getters Functions =========
	Card* HasCard(CellPosition pos);// added by omar to use in edit card action 
	Input * GetInput() const;	// Gets a Pointer to the Input
	Output * GetOutput() const; // Gets a Pointer to the Output 

	void SetClipboard(Card * card);  // A setter to be used in copy/cut (in order NOT to break class responsibilities)
	Card * GetClipboard() const;	 // A getter to be used in paste (in order NOT to break class responsibilities)

	void SetEndGame(bool endGame);	 // A setter for endGame data member
	bool GetEndGame() const;		 // A getter for endGame data member

	void AdvanceCurrentPlayer();     // Increments the currPlayerNum and if reaches MaxPlayerCount reset to 0 (using %)
	void SetCurrentPlayer(int n); // changes the current player number >>Karim

	///TODO: add any needed setter/getter "EXCEPT" ANY setters or getters of "CellList" or "PlayerList" (Forbidden for class Responsibilities)

	// ========= Other Getters =========
	void SetGameObjectToCell(CellPosition*pos,GameObject*pGame);// added by omar
	GameObject* GetGameObjectFromCell(const CellPosition& cell) const;// done by M.O
	Player * GetCurrentPlayer() const;	// Gets a Pointer to the Current Player	                                    
	Ladder * GetNextLadder(const CellPosition & position);  // Gets a Pointer to the first Ladder after the passed "position"
	Snake* GetNextSnake(const CellPosition& position); // Gets a Pointer to the first snake after the passed "position" ==>> added by Medhat


	

	// ========= User Interface Functions =========

	void UpdateInterface() const;		// It Updates the Grid according to the last state of the game
	                                    // In Design mode, it draws all cells/cards THEN all ladders/snakes THEN all players
	                                    // In Play mode, it only draws the player's info on the right side of the toolbar
	                                    // Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
	                                    //       and the cards/snakes/ladders positions do NOT change already in Play Mode

	void PrintErrorMessage(string msg); // Prints an error message on statusbar, Waits for mouse click then clears statusbar
									    // We added this function once here because it is used many times by other classes
	//>>>>>>> Karim
	void SaveAll(ofstream& out, ObjectType Obj); //Calls the save func of each gameobject in the cell list 
	void DeleteAll(); // Removes all Gameobjects from the Grid 
	void countGameObjects(int& ladders, int& snakes, int& cards); //Changes the ints passed by refrence and make them equal to the count of different gameobjects 
	void resetAllPlayers();
	void resetStations(); // resets the owenership of all stations in the grid.
	bool isOverlapping(GameObject* newObj); // checks if the new object is overlapping with any other object in the grid
	void ResetFlags(); //Resets the flags of all game objects in the grid ( card10 to 13 ) to save file I/O correctly
	
	//Applying Special Attacks
	void ApplyBurnAttack(int playerIndex); //Applies the burn attack on the player
	void ApplyFreezeAttack(int playerIndex); //Applies the freeze attack on the player
	void ApplyPoisonAttack(int playerIndex); //Applies the poison attack on the player
	void ApplyLightningAttack(int playerIndex); //Applies the lightning attack on all players except the player with the index passed


	~Grid(); // A destructor for any needed deallcations
};

