#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "Player.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


bool Grid::AddObjectToCell(GameObject* pNewObject, CellPosition* cell)// added by M.Omar
{
	if (cell->IsValidCell())
	{
		GameObject* pPrevObject = CellList[cell->VCell()][cell->HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false
		// Set the game object of the Cell with the new game object
		CellList[cell->VCell()][cell->HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed
		if (CellList[pos.VCell()][pos.HCell()]->GetGameObject())
			delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
		CellList[pos.VCell()][pos.HCell()]->DrawCellOrCard(pOut);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========




Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========

GameObject* Grid:: GetGameObjectFromCell(const CellPosition& cell) const
{
	/*
	first we check if the cell is a valid  : 
	1-if invalid --> return null
	2- if valid   :
	      - check if the cell has an object :
		  i-if no --> return NULL 
		  ii- if yes --> return a pointer of the object 
		     *****(we will use dynamic cast to convert from game object to snake or ladder or card)****
	*/
	if (cell.IsValidCell())
	{
		/* 
		* we need a function that returns a game object
		* this funcion is already exist in the Cell class , but we need an object from cell class to call this function
		* the cell list is a array of pointers to the cell class and returns a pointer of object -if exist - or null if empty cell
		*/
		Cell*CellPtr= CellList[cell.VCell()][cell.HCell()];
		if (CellPtr)
		{
			return CellPtr->GetGameObject();
		}

	}

	return NULL;
}

Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell();// represents the start hCell in the current row to search for the ladder in
	
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			Cell* ptr = CellList[i][j];
			Ladder * l = ptr->HasLadder();
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (l)
			{
				return ((Ladder*)(ptr->GetGameObject()));
			}

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake * Grid::GetNextSnake(const CellPosition& position) 
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the snake in
	 
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a Snake, if yes return it
			Cell* ptr = CellList[i][j];
			Snake* s = ptr->HasSnake();
			if (s)
			{
				return(Snake*)(ptr->GetGameObject());
				
			}

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


void Grid::SaveAll(ofstream& out, ObjectType Obj) // responsible for calling the GameObject :: Save() function for the GameObject of each cell (if any) in the Grid’s CellList
{
	//could count the passed Object Type here and output the number to the file here rather than in saveGrid action yet will loop more times
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObject* pGameObj =CellList[i][j]->GetGameObject(); //Gets pointer to gameobj if exist otherwise it's NULL
			if (pGameObj)
				pGameObj->Save(out,Obj); //Calls the save func of the gameobj with polymorphism

		}
	}

}

void Grid::DeleteAll()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			RemoveObjectFromCell(CellList[i][j]->GetCellPosition()); //Calls the remove obj for all cells to clear the grid

		}
	}

}

void Grid::resetAllPlayers()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i]->ResetPlayer(this); //Resets  all players and resets their wallet to contain 100
		//UpdatePlayerCell(PlayerList[i], CellList[NumVerticalCells - 1][0]->GetCellPosition());
	}
}
void Grid::SetCurrentPlayer(int n)
{
	currPlayerNumber = n;
}
void Grid::resetStations()
{

}

void Grid::countGameObjects(int& ladders, int& snakes, int& cards)
{
	ladders = snakes = cards = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
				ladders++;
			else if (CellList[i][j]->HasSnake())
				snakes++;
			else if (CellList[i][j]->HasCard())
				cards++;
		}
	}
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}

