#ifndef HoleH 
#define HoleH 

#include "FixedGridItem.h"

#include "constants.h"
// None of these are constants because every attribute is being changed
class Hole : public FixedGridItem
{
public:
	Hole::Hole(const char s, const int x, const int y)
		: FixedGridItem (s, x, y)
	{
	}


};

#endif