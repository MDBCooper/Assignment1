#ifndef GridItemH
#define GridItemH

class GridItem
{
private:
	const char symbol_;
public:

	GridItem::GridItem(const char symbol): symbol_(symbol)
	{
	
	}
	char get_symbol();
};

#endif