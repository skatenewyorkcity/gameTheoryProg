#include "player.h"

//Play the game, it is essentially calculating the reward after you have already given yourself a strategy and your neighbors have done the same 
void
Player::playGame()
{
	calculateRewards();
}

//Given your strategy and your neighbors strategy, what will be your reward? 
double
Player::getReward(STRATEGY s, STRATEGY nbr)
{
	if (s == COOPERATE && nbr == COOPERATE)
		return 4;
	else if (s == COOPERATE && nbr == DEFECT)
		return 1;
	else if (s == DEFECT && nbr == COOPERATE)
		return 4;
	else if (s == DEFECT && nbr == DEFECT)
		return 2;
}

//Which one of your neighbors received the best payoff in the last game. This function will be quite long 
Player *
Player::findBestNbr()
{
	int type = getType();
	if (type == 4)
	{
		if (left->getLastReward() >= right->getLastReward())
		{
			if (left->getLastReward() >= top->getLastReward())
			{
				if (left->getLastReward() >= bottom->getLastReward())
					return left;
				else
					return bottom;
			}
			else if (top->getLastReward() >= bottom->getLastReward())
			{
				return top;
			}
			else
				return bottom;
		}
		else if (right->getLastReward() >= top->getLastReward())
		{
			if (right->getLastReward() >= bottom->getLastReward())
				return right;
			else
				return bottom;
		}
		else if (top->getLastReward() >= bottom->getLastReward())
		{
			return top;
		}
		else
			return bottom;
	}
	else
	{
		if (left == NULL && top != NULL && bottom != NULL)
		{
			if (right->getLastReward() >= top->getLastReward())
			{
				if (right->getLastReward() >= bottom->getLastReward())
					return right;
				else
					return bottom;
			}
			else
			{
				if (top->getLastReward() >= bottom->getLastReward())
					return top;
				else
					return bottom;

			}

		}
		else if (right == NULL && top != NULL && bottom != NULL)
		{
			if (left->getLastReward() >= top->getLastReward())
			{
				if (left->getLastReward() >= bottom->getLastReward())
					return left;
				else
					return bottom;
			}
			else
			{
				if (top->getLastReward() >= bottom->getLastReward())
					return top;
				else
					return bottom;

			}

		}
		else if (top == NULL && left != NULL && right != NULL)
		{
			if (right->getLastReward() >= bottom->getLastReward())
			{
				if (right->getLastReward() >= left->getLastReward())
					return right;
				else
					return left;
			}
			else
			{
				if (bottom->getLastReward() >= left->getLastReward())
					return bottom;
				else
					return left;

			}

		}

		else if (bottom == NULL && left != NULL && right != NULL)
		{
			if (right->getLastReward() >= top->getLastReward())
			{
				if (right->getLastReward() >= left->getLastReward())
					return right;
				else
					return left;
			}
			else
			{
				if (top->getLastReward() >= left->getLastReward())
					return top;
				else
					return left;

			}

		}
		else if (top == NULL && left == NULL)
		{
			if (right->getLastReward() >= bottom->getLastReward())
				return right;
			else
				return bottom;
		}
		else if (top == NULL && right == NULL)
		{
			if (left->getLastReward() >= bottom->getLastReward())
				return left;
			else
				return bottom;
		}

		else if (bottom == NULL && left == NULL)
		{
			if (right->getLastReward() >= top->getLastReward())
				return right;
			else
				return top;
		}
		else if (bottom == NULL && right == NULL)
		{
			if (left->getLastReward() >= top->getLastReward())
				return left;
			else
				return top;
		}
	}
}

//Set your next strategy based by observing your neighbors and your payoff. Perhaps use the strategy which gave the best payoff
//It might be your own strategy or one of your neighbors
void
Player::setNextStrategy()
{
	Player *p = findBestNbr();
	if (p->getLastReward() > game_reward)
		setStrategy(p->getStrategy());

	return;
}

//Calculate your reward for the last game and total over all past games. 
//You should add up the rewards from games with each neighbor and divide by the number of neighbors you have.
//If you are a corner or border node, you have fewer neighbors 
void
Player::calculateRewards()
{
	double r = 0;
	if (left != NULL)
		r += getReward(getStrategy(), left->getStrategy());
	if (right != NULL)
		r += getReward(getStrategy(), right->getStrategy());
	if (top != NULL)
		r += getReward(getStrategy(), top->getStrategy());
	if (bottom != NULL)
		r += getReward(getStrategy(), bottom->getStrategy());
	setLastReward(r / getType());
	setReward(getReward() + r / getType());
	return;
}

//You can set your type by counting how many neighbors you have i.e., how many neighbors are not NULL. This number can be 2,3 or 4       
void
Player::setType()
{
	int count = 0;
	if (right != NULL)
		count++;
	if (left != NULL)
		count++;
	if (top != NULL)
		count++;
	if (bottom != NULL)
		count++;

	type = count;

	return;
}
