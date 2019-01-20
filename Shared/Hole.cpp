#include "Hole.h"
Hole::Hole() :FixedGridItem(HOLE, 0, 0)
{
};
Hole::Hole(const int x, const int y)
	: FixedGridItem(HOLE, x, y)
{
}