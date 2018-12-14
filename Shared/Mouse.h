#ifndef MouseH 
#define MouseH 


#include "constants.h"

class Mouse
{
	public:
		// constructor
		Mouse();

		// assessors
		const int get_x();
		const int get_y();
		const char get_symbol() const;
		const bool is_at_position(int x, int y);
		const bool is_alive() const;
		const bool has_escaped() const;


		// mutators
		void die();
		void escape_into_hole(); //Move? Keep, is a setter
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
		void update_position(int dx, int dy);

		char symbol_;

};

#endif