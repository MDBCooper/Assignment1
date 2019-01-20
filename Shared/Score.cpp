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