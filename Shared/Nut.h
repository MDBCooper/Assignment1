#ifndef NutH
#define NutH

#include "MoveableGridItem.h"
#include "Constants.h"
#include "RandomNumberGenerator.h"

class Nut : public MoveableGridItem
{
private:
	bool collected_;
	static RandomNumberGenerator rng_;

public:
	//constructor
	Nut();


	//accessors
	bool has_been_collected();
	void AssignCollected(bool);
	void disappear();
	void reset();
	bool mouse_near(int x, int y);
	bool boundary_check(int x, int y);
	bool move(int x, int y);
};

#endif 
