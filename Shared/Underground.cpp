#include "Underground.h"
#include <cassert>

// number of holes in underground  ASK PASCALE
const int MAXHOLES(3);

Underground::Underground() : holes_{ Hole(4,3), Hole(15,10), Hole(7,15)}
{
}

Hole Underground::get_hole_no(int no) const
{
	// pre-condition: valid hole number
	//assert(is_valid_hole_number(no));
	assert(true);
	return holes_.at(no);
}


bool Underground::is_valid_hole_number(int no) const
{
	return (no >= 0) && (no < holes_.size());
}

bool Underground::has_Mouse_reached_a_hole(const Mouse& mouse) const  //Move?
{
	for (int h_no(0); h_no < holes_.size(); ++h_no) //Move?
	{
		Hole h = get_hole_no(h_no); //Move?

		if (mouse.is_at_position(h.get_x(), h.get_y()))
		{
			return true;
		}
	}

	return false;
}
int Underground::find_hole_number_at_position(int x, int y) const
{
	for (int h_no(0); h_no < holes_.size(); ++h_no)  //Move?
	{
		if (get_hole_no(h_no).is_at_position(x, y))  //Move?
		{
			return h_no;
		}
	}

	return -1; // not a hole
}