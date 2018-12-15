
#ifndef SnakeH
#define SnakeH 

#include "MoveableGridItem.h"

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake : public MoveableGridItem
{
	public:
		Snake();
		~Snake();
		bool has_caught_mouse() ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		//void position_at_random();
		RandomNumberGenerator rng_;
		Mouse* p_mouse_;

		Snake::Snake(const char s, const int x, const int y)
			:MoveableGridItem(s, x, y) {

		}
};

#endif 