//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#ifndef MoveableGridItemH
#define MoveableGridItemH

#include "GridItem.h"

class MoveableGridItem : public GridItem
{
private:
	int x_;
	int y_;
public:
	MoveableGridItem::MoveableGridItem(const char s, const int x, const int y);
	const int get_x() const;
	const int get_y() const;
	const bool is_at_position(int x, int y) const;
	void reset_position(int x, int y);
	void update_position(int dx, int dy);

	
};

#endif
