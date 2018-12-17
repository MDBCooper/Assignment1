#pragma once
class SnakeTail
{
public:
	SnakeTail();
	SnakeTail(const char s, const int x, const int y);
	~SnakeTail();
	void updatePosition(int x, int y);
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
private:
	int x_, y_;
	char symbol_;
};

