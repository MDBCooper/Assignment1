#ifndef ScoreH
#define ScoreH

class Score
{
private:
	int amount;

public:
	Score();
	const int get_amount() const;
	void update_amount(int amt);
};

#endif 

