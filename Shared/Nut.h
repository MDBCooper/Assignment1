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
	void disappear();
	void reset();
};

#endif 
