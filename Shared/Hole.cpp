//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "Hole.h"
Hole::Hole() :FixedGridItem(HOLE, 0, 0)
{

};

Hole::Hole(const int x, const int y)
	: FixedGridItem(HOLE, x, y)
{

}