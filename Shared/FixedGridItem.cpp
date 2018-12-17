#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(const char s, const int x, const int y)
	: GridItem(s), x_(x), y_(y)
{
}

int FixedGridItem::get_x() const
{
	return x_;
}

int FixedGridItem::get_y() const
{
	return y_;
}
bool FixedGridItem::is_at_position(int x, int y) const
{
	return (x_ == x) && (y_ == y);
}