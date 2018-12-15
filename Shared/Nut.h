#ifndef NutH
#define NutH

#include "MoveableGridItem.h"

#include "Mouse.h"
#include "Constants.h"

class Nut : public MoveableGridItem
{
private:
	Mouse* p_mouse_;
public:
	//constructor
	Nut();
	Nut::Nut(const char s, const int x, const int y)
		:MoveableGridItem(s, x, y) {

	}

	//accessors
	bool has_been_collected(); 
	void disappear();
};

#endif 
