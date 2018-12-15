#ifndef FixedGridItemH
#define FixedGridItemH

#include "GridItem.h"

class FixedGridItem : public GridItem
{
private:
	const int x_;
	const int y_;
public:

	FixedGridItem::FixedGridItem(const char s, const int x, const int y)
		: GridItem(s), x_(x), y_(y)
	{
	}
	int get_x();
	int get_y();
	bool is_at_position(int x, int y);
};

#endif
