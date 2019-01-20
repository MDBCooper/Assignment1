#include "GridItem.h"
GridItem::GridItem(const char symbol) : symbol_(symbol)
{

}

char GridItem::get_symbol() const
{
	return symbol_;
}