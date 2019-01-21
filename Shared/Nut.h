//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

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
	const bool mouse_near(int x, int y)const;
	const bool boundary_check(int x, int y)const;
	const bool move(int x, int y, int dx, int dy);
};

#endif 
