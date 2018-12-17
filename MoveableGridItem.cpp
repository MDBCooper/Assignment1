#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(const char s, const int x, const int y)
	: GridItem(s), x_(x), y_(y) {

}

 int MoveableGridItem::get_x()
{
	return x_;
}

 int MoveableGridItem::get_y()
{
	return y_;
}
 bool MoveableGridItem::is_at_position(int x, int y) const
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
 //void MoveableGridItem::set_x(int initx)
 //{
	// x_ = initx;
 //}
 //void MoveableGridItem::set_y(int inity)
 //{
	// y_ = inity;
 //}