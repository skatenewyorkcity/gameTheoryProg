#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "player.h"
class GameBoard
{
public:
	GameBoard(){ length = 3; width = 3; players = new Player[length*width]; setBoard(); }
	GameBoard(int l, int w){ length = l; width = w; players = new Player[length*width]; setBoard(); }
	~GameBoard(){ delete[] players; }

	Player *getBoard(){ return players; }

	void setStrategy(int);
	void setNextStrategy();

	void playGame();

	void displayRewards();
	void displayLastRewards();
	void displayBoard();
	void displayStrategy();


private:
	Player *players;
	int length, width;
	void setBoard();
	void setBoardTorus();
};
#endif
