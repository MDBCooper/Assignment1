#include "Constants.h"
#include "Mouse.h"
#include "Snake.h"
#include "RandomNumberGenerator.h"
Snake::Snake(const char s, const int x, const int y)
	:MoveableGridItem(s, x, y) {
	

}

Snake::Snake() : MoveableGridItem(SNAKEHEAD, 5, 5)
{
	//position_at_random();
	

	// make the pointer safe before the snake spots the mouse
	p_mouse_ = nullptr;
}

Snake::~Snake()
{
}


bool Snake::has_caught_mouse()
{
	return (get_x() == p_mouse_->get_x()) && (get_y() == p_mouse_->get_y());
}

//bool Snake::has_caught_mouse()
//{
//	return is_at_position(p_mouse_->x_, p_mouse_->y_);
//}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: The mouse needs to exist 
	//assert(p_mouse != nullptr);

	p_mouse_ = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	//go in that direction
	update_position(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	//assert(p_mouse_ != nullptr);

	// assume snake only move when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (get_x() < p_mouse_->get_x())          // if snake on left of mouse
		dx = 1;                          // snake should move right
	else if (get_x() > p_mouse_->get_x())     // if snake on left of mouse
		dx = -1;						 // snake should move left

	if (get_y() < p_mouse_->get_y())          // if snake is above mouse
		dy = 1;                          // snake should move down
	else if (get_y() > p_mouse_->get_y())     // if snake is below mouse
		dy = -1;						 // snake should move up
}


//void Snake::position_at_random()
//{
//	// WARNING: this may place on top of other things
//
//	x_ = rng_.get_random_value(SIZE);
//	y_ = rng_.get_random_value(SIZE);
//}