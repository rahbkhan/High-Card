//============================================================================
// Name        : cards.cpp
// Author      : Robert H Conner II
// Description : "High Card" Card Game
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stack>
//#include <windows.h>
#include <unistd.h>
#include <string>
#include <limits.h>

using namespace std;

string Suit[]= {"Spades", "Hearts", "Diamonds", "Clubs"};
string Value[]= {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string Deck[52];

int dealerWinTotal=0;
int player1WinTotal=0;
int player2WinTotal=0;
int draws=0;

int flipRate=0;
string player1Name="temp";
string player2Name="temp";
string showCards="no";

//Function that takes 3 ints and compares them to see which is larger
void whoWon(int dealer, int Player1, int Player2)
{
	if(dealer> Player1 && dealer>Player2)
	{
		cerr<<"Dealer Wins"<<endl<<endl;
		dealerWinTotal++;
	}

	else if(Player2> Player1 && Player2>dealer)
		{
			cerr<<player2Name<< " Wins"<<endl<<endl;
			player2WinTotal++;
		}

	else if(Player1> dealer && Player1>Player2)
		{
			cerr<<player1Name<< " Wins"<<endl<<endl;
			player1WinTotal++;
		}
	else
	{
		draws++;
		cerr<< "No clear victor"<<endl<<endl;
	}

}

//Display how many wins each player has
void displayTotalWins()
{
	cout<<"Dealer has " <<dealerWinTotal<< " total wins!!!"<<endl;
	cout<<player1Name <<" has "<<player1WinTotal<< " total wins!!!"<<endl;
	cout<<player2Name <<" has "<<player2WinTotal<< " total wins!!!"<<endl;
	cout<<"Games ending in a draw... " <<draws<<"!!!"<<endl;
}


//Player class that will create an object that will be used for the 3 players
class Player
{
private:
	//Creates two stacks. Temp will be used to display cards and myStack will have the cards actually drawn from them to be compared.
	stack <string> myStack;
	stack <string> tempStack;

public:

//Pulls the top card off of the stack and returns it.
string pullCard()
{
	string selection = myStack.top();
			    cout<< selection<<endl;
			    myStack.pop();

	return selection;
}


//Grabs the first character from each card
int cardCompare(string card)
{

	char input  = card.at(0);


	switch(input)
	{
	case '2':
		return 1;
			break;
	case '3':
		return 2;
			break;
	case '4':
		return 3;
			break;
	case '5':
		return 4;
			break;
	case '6':
		return 5;
			break;
	case '7':
		return 6;
			break;
	case '8':
		return 7;
			break;
	case '9':
		return 8;
			break;
	case '1':
		return 9;
			break;
	case 'J':
		return 10;
			break;
	case 'Q':
		return 11;
			break;
	case 'K':
		return 12;
			break;
	case 'A':
		return 13;
			break;
	}

return 0;
}

//Simple swap function to be used in shuffling the cards.
void swap (string *a, string *b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}

//Shuffle the deck array before stack insertion.
void shuffle (string arr[])
{
	int n=52;

    srand ( time(NULL) );
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % (n);

        swap(&arr[i], &arr[j]);
    }
}

//fills the deck array with the correct Value and Suit of the cards.
void getCards()
{
int z=0;

for(int i=0; i<=3; i++)
{
	for(int j=0; j<=12; j++)
	{
		Deck[z]= Value[j] + " of "+ Suit[i];
		z++;
	}
}

}

//Function to print the deck array.(Used for testing)
void print(string deck[])
{
	for(int i=0; i<52; i++)
	{
		cout<< deck[i]<< endl;
	}
}

//Fills the Stack with what is in the deck array then displays whats in the stack by printing the "temp Stack".
void fillStack(string deck[])
{

	int z=1;
	for(int i=0; i<52; i++)
		{
			myStack.push(deck[i]);
		}


	tempStack=myStack;

	if(showCards== "yes")
	{
	while(!tempStack.empty())
		{

		cout<<z<< " ";
		    string selection = tempStack.top();
		    cout<< selection<<endl;
		    tempStack.pop();
		    z++;
		}
	}
	cout<<"------------------------------------------------------|";
}
};

int main() {
	//Creating 3 players to play the game.
	Player Dealer,Player1,Player2;

	cout<<"Enter the name of player 1 ";
	cin>>player1Name;

	cout<<"Enter the name of player 2 ";
		cin>>player2Name;

		string go="no";

		while(go =="no")
			{
	cout<<"Enter the the rate at which the card is flipped. (1000=1 second) "<<endl;
			cin>>flipRate;


			if(cin.fail())
			{
				cout<<"incorrect entry, the program will continue with the default (0)."<<endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				go="no";
				//flipRate=1;
			}


				if(flipRate<0 || flipRate>5000)
				{
	
				cerr<<"Please enter a valid number!!!"<<endl;
				go="no";
			}
			else
			{
				go="yes";
			}
			}
	
	
	cout<<"Would you like to view the cards in each hand?(Type 'yes' to view)";
		cin>>showCards;

	//filling the "deck" array, shuffling, then entering the deck into a stack for each player
	cout<<"------------------------------------------------------|"<<endl;
	cout<<"Dealer's hand"<<endl;
	cout<<"------------------------------------------------------|"<<endl;
		Dealer.getCards();
		Dealer.shuffle(Deck);
		Dealer.fillStack(Deck);
		//Sleep(1000);
		usleep(1000000);

	cout<<endl<<player1Name<<"'s hand"<<endl;
	cout<<"------------------------------------------------------|"<<endl;
		Player1.getCards();
		Player1.shuffle(Deck);
		Player1.fillStack(Deck);
		//Sleep(1000);
		usleep(1000000);

	cout<<endl<<player2Name<<"'s hand"<<endl;
	cout<<"------------------------------------------------------|"<<endl;
		Player2.getCards();
		Player2.shuffle(Deck);
		Player2.fillStack(Deck);
		//Sleep(1000);
		usleep(1000000);
		cout<<endl;

		string finish="yes";
		int cards=51;

		//Entering a while loop to continuously play the game for all 52 cards.
		while(finish=="yes")
		{
			cout<<"Press 'ENTER' to continue."<<endl;
						if (cin.get() == '\n')
						{
						    finish="yes";
						}
						if(cards==0)
						{
							finish="no";
						}

		//Show the top cards for all players
		cout<<"Cards that are being played..."<<endl;
		cout<<endl<<"DEALER"<<endl;
			cout<<"------------------------------------------------------|"<<endl;
			string dealerResults=Dealer.pullCard();
			//Sleep(flipRate);
			usleep(flipRate*1000);
			cout<<"------------------------------------------------------|"<<endl;
			cout<<player1Name<<endl;
			cout<<"------------------------------------------------------|"<<endl;
			string player1Results=Player1.pullCard();
			//Sleep(flipRate); 
			usleep(flipRate*1000);
			cout<<"------------------------------------------------------|"<<endl;
			cout<<player2Name<<endl;
			cout<<"------------------------------------------------------|"<<endl;
			string player2Results=Player2.pullCard();
			//Sleep(flipRate); 
			usleep(flipRate*1000);
			cout<<"------------------------------------------------------|"<<endl;

		//Evaluate which card has the higher value and saves it as an into to be compared later.
			int dealerPlay  = Dealer.cardCompare(dealerResults);
			int player1Play = Player1.cardCompare(player1Results);
			int player2Play = Player2.cardCompare(player2Results);

			/*
			cout<<endl<<"How many points the card is worth!!!"<<endl;
			cout<<dealerPlay<< " "<<player1Play<< " "<<player2Play<<endl;
			 */

		//Function that compares each int to see who won.
			whoWon(dealerPlay,player1Play,player2Play);


		//Shows how may cards are remaining in the deck
			cerr<<endl<<cards<< " Card(s) remaining"<<endl;
			cards--;
		}


		//Prints results of how many wins each player has.
		displayTotalWins();

		return 0;
}
