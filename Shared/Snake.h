
#ifndef SnakeH
#define SnakeH 

#include "MoveableGridItem.h"
#include <vector>
#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "SnakeTail.h"
class Snake : public MoveableGridItem
{
	private:
		void set_direction(int& dx, int& dy);
		static RandomNumberGenerator rng_;
		Mouse* p_mouse_;
		vector<SnakeTail> snakeTail_;
		void move_Tail();
	public:
		Snake();
		Snake(const char s, const int x, const int y);
		~Snake();
		bool has_caught_mouse() const;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		int get_Tail_x(int tailPiece) const;
		int get_Tail_y(int tailPiece) const;
		char get_Tail_Symbol(int tailPiece) const;
};


#endif 