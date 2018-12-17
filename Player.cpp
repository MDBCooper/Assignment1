#include "Player.h"
#include "Score.h"

Player::Player(string name_): name(name_)
{
	
}

const string Player::get_name()
{
	return name;
}

const int Player::get_score()
{
	return score.get_amount();
}

void Player::update_score(int amt)
{
	score.update_amount(amt);
}
