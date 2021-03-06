#include "Mouse.h"

Mouse::Mouse() : MoveableGridItem (MOUSE, SIZE / 2, SIZE / 2), alive_(true), escaped_(false), mouse_dx_(0), mouse_dy_(0)
{
	//position_in_middle_of_grid();
}

const bool Mouse::is_alive() const
{
	return alive_;
}

const bool Mouse::has_escaped() const
{
	return escaped_;
}

void Mouse::die()
{
	alive_ = false;
}

void Mouse::escape_into_hole() //Move?
{
	escaped_ = true;
}

void Mouse::scamper(char k)
{
	// move mouse in required direction
	// pre: k is an arrow representing the direction in which the mouse moves

	// find direction indicated by k
	switch (k)
	{
		case LEFT:
			mouse_dx_ = -1;
			mouse_dy_ = 0;
			break;
		case RIGHT:
			mouse_dx_ = +1;
			mouse_dy_ = 0;
			break;
		case UP:
			mouse_dx_ = 0;
			mouse_dy_ = -1;
			break;
		case DOWN:
			mouse_dx_ = 0;
			mouse_dy_ = +1;
			break;
	}

	// update mouse coordinates if move is possible
	if (((get_x() + mouse_dx_) >= 1) && ((get_x() + mouse_dx_) <= SIZE) && ((get_y() + mouse_dy_) >= 1) && ((get_y() + mouse_dy_) <= SIZE))
	{
		update_position(mouse_dx_, mouse_dy_);
	}
}


//void Mouse::position_in_middle_of_grid()
//{
//	x_ = SIZE / 2;
//	y_ = SIZE / 2;
//}