//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "GridItem.h"
GridItem::GridItem(const char symbol) : symbol_(symbol)
{

}

char GridItem::get_symbol() const
{
	return symbol_;
}