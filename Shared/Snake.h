//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

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
	void move_Tail();
	static RandomNumberGenerator rng_;
	Mouse* p_mouse_;
public:
	vector<SnakeTail> snakeTail_;
	Snake();
	Snake(const char s, const int x, const int y);
	~Snake();
	void reset();
	const bool has_caught_mouse() const;
	void spot_mouse(Mouse* p_mouse);
	void chase_mouse();
};


#endif 