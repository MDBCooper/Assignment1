#include "Nut.h"
RandomNumberGenerator Nut::rng_ = RandomNumberGenerator();

Nut::Nut() : MoveableGridItem(NUT, rng_.get_random_value(SIZE), rng_.get_random_value(SIZE)), collected_(false)
{
	if (get_x() == 1 || get_x() == SIZE) {
		reset();
	}

	if (get_y() == 1 || get_y() == SIZE) {
		reset();
	}
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

bool Nut::boundary_check(int x, int y)
{
	if (x >= 1 && x <= SIZE && y >= 1 && y <= SIZE)
	{
		return true;
	}
	else
		return false;
}

bool Nut::mouse_near(int mouse_dx, int mouse_dy) {
	if ((mouse_dx >= 1) && (mouse_dx <= -1) && (mouse_dy >= 1) && (mouse_dy <= -1))
		return true;
	else
		return false;
}

bool Nut::move(int mouse_x, int mouse_y)
{
	int nut_x_ = (get_x() - mouse_x);
	int nut_y_ = (get_y() - mouse_y);

	if (mouse_near(nut_x_, nut_y_))
	{
		if (boundary_check(nut_x_ * 2, nut_y_ * 2))
		{
			int nut_dx_ = nut_x_;
			int nut_dy_ = nut_y_;
			// update nut coordinates if move is possible
			if (((get_x() + nut_dx_ * 2) >= 2) && ((get_x() + nut_dx_ * 2) <= SIZE - 1) && ((get_y() + nut_dy_ * 2) >= 2) && ((get_y() + nut_dy_ * 2) <= SIZE - 1))
			{
				update_position(nut_dx_, nut_dy_);
				return true;
			}
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
