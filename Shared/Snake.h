
#ifndef SnakeH
#define SnakeH 

#include "MoveableGridItem.h"
#include <vector>
#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake : public MoveableGridItem
{
	private:
		struct TailPiece {
			char Symbol_ = SNAKETAIL;
			int x_;
			int y_;
		};
		void set_direction(int& dx, int& dy);
		static RandomNumberGenerator rng_;
		Mouse* p_mouse_;
		vector<TailPiece> snakeTail_;
	public:
		Snake();
		Snake(const char s, const int x, const int y);
		~Snake();
		bool has_caught_mouse() const;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void move_Tail();
		int get_Tail_x(int tailPiece) const;
		int get_Tail_y(int tailPiece) const;
};


#endif 