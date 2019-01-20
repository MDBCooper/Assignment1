#include "Nut.h"
RandomNumberGenerator Nut::rng_ = RandomNumberGenerator();

Nut::Nut() : MoveableGridItem(NUT, rng_.get_random_value(SIZE), rng_.get_random_value(SIZE)), collected_(false)
{

}


bool Nut::has_been_collected()
{
	return collected_;
}

void Nut::disappear()
{
	update_position(-get_x(), -get_y());
	collected_ = true;
}

void Nut::reset()
{
	reset_position(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
	collected_ = false;
}