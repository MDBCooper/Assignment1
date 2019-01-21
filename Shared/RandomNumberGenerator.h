//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#ifndef RandomNumberGeneratorH 
#define RandomNumberGeneratorH 

#include <stdlib.h>	// for srand and rand routines
#include <cassert>	// for assert
#include <ctime>	// for time used in RandomNumberGenerator::seed routines
using namespace std;

class RandomNumberGenerator
{
	public:
		// constructors
		RandomNumberGenerator();

		// assessors
		const int get_random_value(int) const;

	private:
		// supporting functions
		const void seed();
};

#endif