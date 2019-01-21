//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#ifndef FixedGridItemH
#define FixedGridItemH

#include "GridItem.h"

class FixedGridItem : public GridItem
{
private:
	int x_, y_;
public:
	FixedGridItem(const char s, const int x, const int y);
	const int get_x() const;
	const int get_y() const;
	const bool is_at_position(int x, int y) const;
};

#endif
