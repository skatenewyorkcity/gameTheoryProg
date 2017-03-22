#include "GameBoard.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;


//Set the strategies of all players you have.
//Traverse the list across each row until you are done and set the strategies randomly
void GameBoard::setStrategy(int PERC_COOP)
{
	//This sample implementation uses arrays, your task is to rewrite the body of this function so that you use linked list instead of array

	srand(time(0));
	int random = 0;
	for (int i = 0; i < length*width; ++i)
	{
		if (rand() % 100 < PERC_COOP)
			players[i].setStrategy(COOPERATE);
		else
			players[i].setStrategy(DEFECT);
	}
}


void GameBoard::setNextStrategy()
{
	//This sample implementation uses arrays, your task is to rewrite the body of this function so that you use linked list instead of array

	for (int i = 0; i < length*width; ++i)
	{
		players[i].setNextStrategy();
	}
}


void GameBoard::playGame()
{
	//This sample implementation uses arrays, your task is to rewrite the body of this function so that you use linked list instead of array	
	for (int i = 0; i < length*width; ++i)
	{
		players[i].playGame();
	}
}



void GameBoard::displayRewards()
{
	//This sample implementation uses arrays, your task is to rewrite the body of this function so that you use linked list instead of array	
	for (int i = 0; i < length*width; ++i)
	{
		cout << "| " << setw(7) << setprecision(3) << players[i].getReward() << " |";
		if ((i + 1) % length == 0)
			cout << endl;
	}
}

void GameBoard::displayLastRewards()
{
	//This sample implementation uses arrays, your task is to rewrite the body of this function so that you use linked list instead of array	
	for (int i = 0; i < length*width; ++i)
	{
		cout << "| " << setw(7) << setprecision(3) << players[i].getLastReward() << " |";
		if ((i + 1) % length == 0)
			cout << endl;
	}
}

void
GameBoard::displayBoard()
{
	//This sample implementation uses arrays, your task is to rewrite the body of this function so that you use linked list instead of array	
	for (int i = 0; i < length*width; ++i)
	{
		if (i%length == 0)
			cout << endl;
		cout << "| " << players[i].getType() << " |";

	}
}


void
GameBoard::displayStrategy()
{
	//This sample implementation uses arrays, your task is to rewrite the body of this function so that you use linked list instead of array	
	for (int i = 0; i < length*width; ++i)
	{
		if (i%length == 0)
			cout << endl;
		cout << "| " << players[i].getStrategy() << " |";

	}
}

//This function sets up the rectangular board. Leave it the way it is. 
//Changing this into linked list based implementation will be nothing less than a nightmare, although it can be done!
//Extra credits if you change this into linked list based implementation?
void GameBoard::setBoard()
{

	for (int i = 0; i < length*width; ++i)
	{
		if (i< length)
		{
			players[i].setTop(NULL);
		}
		else
			players[i].setTop(&players[i - length]);

		if (i% length == 0)
		{
			players[i].setLeft(NULL);
		}
		else
			players[i].setLeft(&players[i - 1]);

		if ((i + 1) % length == 0)
			players[i].setRight(NULL);
		else
			players[i].setRight(&players[i + 1]);

		if (i>length*(width - 1) - 1)
			players[i].setBottom(NULL);
		else
			players[i].setBottom(&players[i + length]);

		players[i].setType();

	}

}



//This function sets up the rectangular board. Leave it the way it is. 
//Changing this into linked list based implementation will be nothing less than a nightmare, although it can be done!
//Extra credits if you change this into linked list based implementation?
void GameBoard::setBoardTorus()
{

	for (int i = 0; i < length*width; ++i)
	{
		if (i< length)
		{
			players[i].setTop(&players[i + length*(width - 1)]);
		}
		else
			players[i].setTop(&players[i - length]);

		if (i% length == 0)
		{
			players[i].setLeft(&players[i + length - 1]);
		}
		else
			players[i].setLeft(&players[i - 1]);

		if ((i + 1) % length == 0)
			players[i].setRight(&players[i - length + 1]);
		else
			players[i].setRight(&players[i + 1]);

		if (i>length*(width - 1) - 1)
			players[i].setBottom(&players[i - length*(width - 1)]);
		else
			players[i].setBottom(&players[i + length]);

		players[i].setType();

	}

}
