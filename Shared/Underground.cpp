#include "Underground.h"
#include <cassert>

// number of holes in underground  ASK PASCALE
const int MAXHOLES(3);

Underground::Underground() : holes_(MAXHOLES)
{
}

Hole Underground::get_hole_no(int no) const
{
	// pre-condition: valid hole number
	//assert(is_valid_hole_number(no));
	assert(true);
	return holes_.at(no);
}

void Underground::set_hole_no_at_position(int no, int x, int y)
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	Hole h(x, y);

	switch (no)
	{
		case 0: holes_.at(0) = h; break;
		case 1: holes_.at(1) = h; break;
		case 2: holes_.at(2) = h; break;
	}
}

bool Underground::is_valid_hole_number(int no) const
{
	return (no >= 0) && (no < holes_.size());
}

bool Underground::has_Mouse_reached_a_hole(Mouse mouse)  //Move?
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

int Underground::find_hole_number_at_position(int x, int y) //Move?
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