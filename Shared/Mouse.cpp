//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "Mouse.h"
RandomNumberGenerator Mouse::rng_ = RandomNumberGenerator();

Mouse::Mouse() : MoveableGridItem(MOUSE, rng_.get_random_value(SIZE), rng_.get_random_value(SIZE)), alive_(true), escaped_(false)
{
	p_nut_ = nullptr;
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

void Mouse::escape_into_hole()
{
	escaped_ = true;
}

void Mouse::nut_location(Nut* p_nut) {
	p_nut_ = p_nut;
}

void Mouse::scamper(char k)
{
	int mouse_dx_ = 0;
	int mouse_dy_ = 0;
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
	if (((get_x() + mouse_dx_) >= 1) && ((get_x() + mouse_dx_) <= SIZE) && ((get_y() + mouse_dy_) >= 1) && ((get_y() + mouse_dy_) <= SIZE) &&
		p_nut_->move(get_x(), get_y(), get_x() + mouse_dx_, get_y() + mouse_dy_))
	{
		update_position(mouse_dx_, mouse_dy_);
	}
}

void Mouse::AssignAlive(bool alive) {
	alive_ = alive;
}
void Mouse::AssignEscaped(bool escaped) {
	escaped_ = escaped;
}
void Mouse::reset()
{
	reset_position(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
	alive_ = true;
	escaped_ = false;
}