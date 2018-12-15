#include "Nut.h"
#include "Constants.h"
#include "Mouse.h"
#include "Snake.h"
#include "RandomNumberGenerator.h"

Nut::Nut() : symbol_(NUT), x_(0), y_(0)
{
	
}


bool Nut::has_been_collected()
{
	return is_at_position(p_mouse_->x_, p_mouse_->y_);
}
void Nut::disappear()
{

}