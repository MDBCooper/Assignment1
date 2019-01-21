//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#ifndef UndergroundH
#define UndergroundH 


#include <cassert>
#include <vector>

#include "constants.h"
#include "Mouse.h"
#include "Hole.h"

using namespace std;

class Underground
{
	private:
		bool is_valid_hole_number(int n) const;
		vector<Hole> holes_;
	public:
		Underground();
		Hole get_hole_no(int no) const;

		const bool has_Nut_reached_a_hole(const Nut& nut) const;
		const bool has_Mouse_reached_a_hole(const Mouse& mouse) const;
		const int find_hole_number_at_position(int x, int y) const;
};

#endif