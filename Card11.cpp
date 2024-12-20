#include "Card11.h"

Card11::Card11(const CellPosition& pos) :Card(pos)
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number 
	count++;
	Fee = 0;
	CardPrice = 0;
	
}
bool Card11::Flag = false;
int Card11::count = 0;
Player* Card11::CardOwner = NULL;
Card11::~Card11()
{
}
void  Card11::ReadCardParameters(Grid* pGrid)
{

	//we need to know the following things
	/*
		1-price --> from user
		2-the fee -->from user
		*/


		// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	if (count == 1)
	{
		// 1- Get a Pointer to the Input / Output Interfaces from the Grid
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		// 2- Read an Integer from the user using the Input class and set the Price  parameter & another int to the fee parameter 
		//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
		pOut->PrintMessage("Enter the price of the Card ....");
		CardPrice = pIn->GetInteger(pOut);
		if (CardPrice <= 0)
		{
			pGrid->PrintErrorMessage("The price should be greater than 0 ! Click anywhere to continue.....");
			return;
		}
		pOut->PrintMessage("Enter the amount of the fee ....");
		Fee = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
		if (Fee < 0)
		{
			pGrid->PrintErrorMessage("The fee should be greater than 0 ! Click anywhere to continue...");
			return;
		}
	}
}

void Card11::Apply(Grid* pGrid, Player* pPlayer)
//here we will excute the logic of the card by applying the following steps 
	//ask th player if he will buy the card or not (get the answer as a string):
	//1- if yes :
	//i-search for the other cards with the same number (if exist) and apply the price & fees to them 
	//ii-if the player (differenet than the owner ) stands on it --> take the fee from his wallet 
	//2- if no : no action taken 
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (!CardOwner)
	{
		pOut->PrintMessage("Would you like to buy this card ?....Note: Answer with \"yes\" or \"no\" ");
		string answer = pIn->GetSrting(pOut);
		if (answer == "no" || answer == "No")
		{
			pGrid->PrintErrorMessage("Click anywhere to continue....");
			return;
		}
		else if (answer == "yes" || answer == "Yes")
		{
			CardOwner = pPlayer;
			if (pPlayer->GetWallet() >= CardPrice)// check if the player has enough money or not 
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				pGrid->PrintErrorMessage("Bought successfully ! Click anywhere to continue....");
			}
			else
			{
				pGrid->PrintErrorMessage("Cannot buy \"do not have enough money\"! Click anywhere to continue....");
				return;
			}
		}
	}
	else
	{
		if (pGrid->GetCurrentPlayer() != CardOwner)
		{
			pGrid->PrintErrorMessage("Owner : You have arrived at my card !!,  Pay the fee immediately, or you'll be on your way to bankruptcy! Click to continue...");
			pPlayer->SetWallet(pPlayer->GetWallet() - Fee);
			CardOwner->SetWallet(CardOwner->GetWallet() + Fee);
			pGrid->PrintErrorMessage("The fee transfered successfully ! Click any where to continue...");
			pGrid->PrintErrorMessage("Owner : You can go now ! Click anywhere to continue...");
		}
		else
		{
			pGrid->PrintErrorMessage("You are the owner of this card , No fee to pay ! Click anywhere to continue...");
		}
	}

}


void Card11::Save(ofstream& OutFile, ObjectType Obj)
{
	// Check Obj 
	if (Obj != CardObj)
		return;

	// Call base class Save only if the check passes
	Card::Save(OutFile, Obj);

	// Now add Card parameters 
	if (Flag)
		OutFile << endl;
	else
	{
		OutFile << " " << CardPrice << " " << Fee << endl;
		Flag = true;
	}
}

void Card11::Load(ifstream& Infile)
{
	// load the card postition first by calling the base class load
	Card::Load(Infile);
	//load the card parameters 
	if (Flag)
		Infile >> CardPrice >> Fee;
	else
	{
		Infile >> CardPrice >> Fee;
		Flag = true;
	}


}