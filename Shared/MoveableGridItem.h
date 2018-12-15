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
	int get_x();
	int get_y();
	void set_x(int initx);
	void set_y(int inity);
	bool is_at_position(int x, int y) const;
	int reset_position(int x, int y);
	void update_position(int dx, int dy);

	
};

#endif
