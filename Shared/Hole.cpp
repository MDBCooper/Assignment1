#include "Hole.h"
Hole::Hole():FixedGridItem(HOLE,0,0)
{
};
Hole::Hole(const char s, const int x, const int y)
	: FixedGridItem(s, x, y)
{
}