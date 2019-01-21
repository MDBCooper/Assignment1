//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(const char s, const int x, const int y)
	: GridItem(s), x_(x), y_(y)
{
}

const int FixedGridItem::get_x() const
{
	return x_;
}

const int FixedGridItem::get_y() const
{
	return y_;
}
const bool FixedGridItem::is_at_position(int x, int y) const
{
	return (x_ == x) && (y_ == y);
}