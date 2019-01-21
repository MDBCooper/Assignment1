//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#ifndef HoleH 
#define HoleH 

#include "FixedGridItem.h"

#include "constants.h"
// None of these are constants because every attribute is being changed
class Hole : public FixedGridItem
{
public:
	Hole();
	Hole(const int x, const int y);
};

#endif