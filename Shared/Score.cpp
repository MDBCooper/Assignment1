//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "Score.h"

Score::Score()
{
	amount = 0;
}

const int Score::get_amount() const
{
	return amount;
}

void Score::update_amount(int amt)
{
	amount += amt;
}