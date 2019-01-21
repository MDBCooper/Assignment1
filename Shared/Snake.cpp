//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "Snake.h"
RandomNumberGenerator Snake::rng_ = RandomNumberGenerator();
const int MAXTailPieces = 3;

Snake::Snake(const char s, const int x, const int y)
	:MoveableGridItem(s, x, y) {
}

Snake::Snake() : MoveableGridItem(SNAKEHEAD, rng_.get_random_value(SIZE), rng_.get_random_value(SIZE))
{
	// make the pointer safe before the snake spots the mouse
	p_mouse_ = nullptr;
	SnakeTail t( get_x(), get_y());
	snakeTail_.assign(MAXTailPieces, t);
}

Snake::~Snake()
{

}

const bool Snake::has_caught_mouse() const
{
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: The mouse needs to exist 
	assert(p_mouse != nullptr);

	p_mouse_ = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);
	move_Tail();
	//go in that direction
	update_position(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse_ != nullptr);

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
		dy = -1;						// snake should move up
	for (int i = 0; i <= 2; i++) {
		if (get_x() + dx == snakeTail_.at(i).get_x())
			dx = 0;
		if (get_y() + dy == snakeTail_.at(i).get_y())
			dy = 0;
	}
	
}

void Snake::reset()
{
	reset_position(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
	snakeTail_.at(0).reset_position(get_x(), get_y());
	snakeTail_.at(1).reset_position(get_x(), get_y());
	snakeTail_.at(2).reset_position(get_x(), get_y());
}

void Snake::move_Tail() {
	snakeTail_.at(2).reset_position(snakeTail_.at(1).get_x(), snakeTail_.at(1).get_y());
	snakeTail_.at(1).reset_position(snakeTail_.at(0).get_x(), snakeTail_.at(0).get_y());
	snakeTail_.at(0).reset_position(get_x(), get_y());
}
