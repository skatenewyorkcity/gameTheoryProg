#ifndef PLAYER_H
#define PLAYER_H
#include <cstdlib>

enum STRATEGY { COOPERATE, DEFECT };

class Player
{

private:
	double reward;
	double game_reward;
	STRATEGY strategy;
	int type;
	Player *left, *right, *top, *bottom;

	void setReward(double r){ reward = r; }
	void calculateRewards();
	Player* findBestNbr();

	double getReward(STRATEGY s, STRATEGY nbr);
	void setLastReward(double r){ game_reward = r; }

public:
	Player(){ reward = 0; game_reward = 0; strategy = COOPERATE; type = 1; left = NULL; right = NULL; top = NULL; bottom = NULL; }
	~Player(){};

	double getReward(){ return reward; }
	double getLastReward(){ return game_reward; }

	STRATEGY getStrategy() { return strategy; }
	double getType() { return type; }

	Player *getLeft(){ return left; }
	Player *getRight(){ return right; }
	Player *getTop(){ return top; }
	Player *getBottom(){ return bottom; }

	void setStrategy(STRATEGY s){ strategy = s; }

	void setLeft(Player *l){ left = l; }
	void setRight(Player *r){ right = r; }
	void setTop(Player *t){ top = t; }
	void setBottom(Player *b){ bottom = b; }


	void setNextStrategy();

	void playGame();
	void setType();

};
#endif
