//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "Player.h"

Player::Player(string name_) : name(name_), cheated(false)
{

}

const string Player::get_name() const
{
	return name;
}

const int Player::get_score() const
{
	return score.get_amount();
}

void Player::update_score(int amt)
{
	if (!cheated) {
		score.update_amount(amt);
	}
}

void Player::has_cheated()
{
	cheated = true;
}

void Player::reset()
{
	cheated = false;
}
