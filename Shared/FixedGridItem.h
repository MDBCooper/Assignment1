#ifndef FixedGridItemH
#define FixedGridItemH

#include "GridItem.h"

class FixedGridItem : public GridItem
{
private:
	int x_, y_;
public:
	FixedGridItem(const char s, const int x, const int y);
	int get_x();
	int get_y();
	bool is_at_position(int x, int y);
};

#endif
