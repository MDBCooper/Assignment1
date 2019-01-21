//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "Nut.h"
RandomNumberGenerator Nut::rng_ = RandomNumberGenerator();

Nut::Nut() : MoveableGridItem(NUT, rng_.get_random_value(SIZE - 3) + 1, rng_.get_random_value(SIZE - 3) + 1), collected_(false)
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

const bool Nut::boundary_check(int x, int y)const
{
	if (x >= 1 && x <= SIZE && y >= 1 && y <= SIZE)
	{
		return true;
	}
	else
		return false;
}

const bool Nut::mouse_near(int mouse_dx, int mouse_dy)const {
	if (mouse_dx == get_x() & mouse_dy == get_y())
		return true;
	else
		return false;
}

const bool Nut::move(int mouse_x, int mouse_y, int mouse_dx, int mouse_dy)
{
	int nut_dx_ = (get_x() - mouse_x);
	int nut_dy_ = (get_y() - mouse_y);

	if (mouse_near(mouse_dx, mouse_dy))
	{
		if (boundary_check(get_x() + (nut_dx_ * 2), get_y() + (nut_dy_ * 2)))
		{
			update_position(nut_dx_, nut_dy_);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

void Nut::AssignCollected(bool collected) {
	collected_ = collected;
}
