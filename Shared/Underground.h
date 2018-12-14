#ifndef UndergroundH
#define UndergroundH 


#include <cassert>
#include <vector>

#include "constants.h"
#include "RandomNumberGenerator.h"
#include "Hole.h"
#include "Mouse.h"

using namespace std;

class Underground
{
	private:
		bool is_valid_hole_number(int n) const;
		vector<Hole> holes_;
	public:
		Underground();
		Hole get_hole_no(int no) const;
		void set_hole_no_at_position(int no, int x, int y);
		bool has_Mouse_reached_a_hole(Mouse mouse); //Move?
		int find_hole_number_at_position(int x, int y); //move?
};

#endif