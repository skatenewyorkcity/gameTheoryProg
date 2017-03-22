#include <iostream>
#include "GameBoard.h"
/*Driver program to test the game and to find some statistics*/

int main(int argc, char** argv) {
	GameBoard g(6, 4);
	//Set some percentage of strategies as COOPERATE
	g.setStrategy(90);

	g.displayBoard();
	std::cout << std::endl;

	g.displayStrategy();
	std::cout << std::endl;
	//Play the game a lot of times
	for (int i = 0; i < 10; ++i)
	{
		g.playGame();
		std::cout << std::endl;

		g.displayLastRewards();
		//std::cout << std::endl;

		g.displayStrategy();
		std::cout << std::endl;
		g.setNextStrategy();

		//ToDo: Print the percentage of players using COOPERATE strategy after each game.         
	}
	std::cout << std::endl;

	g.displayLastRewards();

	g.displayStrategy();
	std::cout << std::endl;

	system("PAUSE");
	return 0;
}
