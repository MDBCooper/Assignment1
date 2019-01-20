#ifndef SnakeTailH
#define SnakeTailH
#include "MoveableGridItem.h"

class SnakeTail : public MoveableGridItem
{
public:
	SnakeTail(const char s, const int x, const int y);
	~SnakeTail();

};

#endif
