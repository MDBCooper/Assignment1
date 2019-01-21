//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#ifndef MouseH 
#define MouseH 

#include "MoveableGridItem.h"
#include "Constants.h"
#include "Nut.h"
#include "RandomNumberGenerator.h"

class Mouse : public MoveableGridItem
{
private:
	// data members
	bool alive_;
	bool escaped_;
	Nut* p_nut_;
	static RandomNumberGenerator rng_;

	// supporting functions

public:
	// constructor
	Mouse();

	// assessors
	const bool is_alive() const;
	const bool has_escaped() const;


	// mutators
	void die();
	void escape_into_hole();
	void scamper(char k);
	void AssignAlive(bool);
	void AssignEscaped(bool);
	void reset();
	void nut_location(Nut* p_nut);

};

#endif