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
	bool cheated;

public:
	Player(string name_);
	const string get_name() const;
	const int get_score() const;
	void update_score(int amt);
	void has_cheated();
	void reset();
};

#endif 

