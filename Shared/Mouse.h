#ifndef MouseH 
#define MouseH 

#include "MoveableGridItem.h"
#include "constants.h"

class Mouse : public MoveableGridItem
{
	public:
		// constructor
		Mouse();

		// assessors
		const bool is_alive() const;
		const bool has_escaped() const;
		

		// mutators
		void die();
		void escape_into_hole(); //Move?
		void scamper(char k);

		int  x_, y_;

	private:
		// data members
		bool alive_;
		bool escaped_;
		int mouse_dx_;
		int mouse_dy_;

		// supporting functions 
		void position_in_middle_of_grid();


};

#endif