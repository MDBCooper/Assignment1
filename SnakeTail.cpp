#include "SnakeTail.h"

SnakeTail::SnakeTail(const char s, const int x, const int y) : symbol_(s), x_(x), y_(y)
{
}

SnakeTail::~SnakeTail()
{
}

void SnakeTail::updatePosition(int x, int y)
{
	x_ = x;
	y_ = y;
}
int SnakeTail::get_x() const
{
	return x_;
}
int SnakeTail::get_y() const 
{
	return y_;
}

char SnakeTail::get_symbol() const
{
	return symbol_;
}
