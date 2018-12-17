#ifndef PlayerH
#define PlayerH
#include <string>
#include "Score.h"

using namespace std;

class Player 
{
private:
	const string name;
	Score score;

public:
	//Player();
	Player(string name_);
	const string get_name();
	const int get_score();
	void update_score(int amt);
};

#endif 

