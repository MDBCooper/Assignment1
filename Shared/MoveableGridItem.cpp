#include "MoveableGridItem.h"

 int MoveableGridItem::get_x()
{
	return x_;
}

 int MoveableGridItem::get_y()
{
	return y_;
}
 bool MoveableGridItem::is_at_position(int x, int y)
 {
	 return (x_ == x) && (y_ == y);
 }
 void MoveableGridItem::update_position(int dx, int dy)
 {
	 x_ += dx;
	 y_ += dy;
 }
 int MoveableGridItem::reset_position(int x, int y)
 {
	 return (x_ == x) && (y_ == y);
 }