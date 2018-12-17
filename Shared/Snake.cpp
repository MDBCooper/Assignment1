#include "Constants.h"
#include "Mouse.h"
#include "Snake.h"
#include "RandomNumberGenerator.h"
RandomNumberGenerator Snake::rng_ = RandomNumberGenerator();
const int MAXTailPieces = 3;

Snake::Snake(const char s, const int x, const int y)
	:MoveableGridItem(s, x, y) {
}

Snake::Snake() : MoveableGridItem(SNAKEHEAD, rng_.get_random_value(SIZE), rng_.get_random_value(SIZE))
{
	//position_at_random();
	// make the pointer safe before the snake spots the mouse
	p_mouse_ = nullptr;
	TailPiece t;
	t.x_ = get_x();
	t.y_ = get_y();
	snakeTail_.assign(MAXTailPieces, t);
}

Snake::~Snake()
{
}

bool Snake::has_caught_mouse() const
{
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

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
		dy = -1;						 // snake should move up
}

void Snake::move_Tail() {
	int lastSnakeHeadPosX(get_x()), lastSnakeHeadPosY(get_y());
	int lastSnakeTail1PosX(get_Tail_x(0)), lastSnakeTail1PosY(get_Tail_y(0));
	int lastSnakeTail2PosX(get_Tail_x(1)), lastSnakeTail2PosY(get_Tail_y(1));
	snakeTail_.at(0).x_ = lastSnakeHeadPosX;
	snakeTail_.at(0).y_ = lastSnakeHeadPosY;
	snakeTail_.at(1).x_ = lastSnakeTail1PosX;
	snakeTail_.at(1).y_ = lastSnakeTail1PosY;
	snakeTail_.at(2).x_ = lastSnakeTail2PosX;
	snakeTail_.at(2).y_ = lastSnakeTail2PosY;
}

int Snake::get_Tail_y(int tailPiece) const {
	return snakeTail_.at(tailPiece).y_;
}
int Snake::get_Tail_x(int tailPiece) const {
	return snakeTail_.at(tailPiece).x_;
}