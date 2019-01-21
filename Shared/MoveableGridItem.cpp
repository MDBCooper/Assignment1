//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(const char s, const int x, const int y)
	: GridItem(s), x_(x), y_(y) {

}

const int MoveableGridItem::get_x()const
{
	return x_;
}

 const int MoveableGridItem::get_y()const
{
	return y_;
}

const bool MoveableGridItem::is_at_position(int x, int y) const
{
	return (x_ == x) && (y_ == y);
}

void MoveableGridItem::update_position(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}

void MoveableGridItem::reset_position(int x, int y)
{
	x_ = x;
	y_ = y;
}