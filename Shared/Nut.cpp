#include "Nut.h"
#include "Constants.h"
#include "Mouse.h"
#include "Snake.h"
#include "RandomNumberGenerator.h"

Nut::Nut() : MoveableGridItem(NUT, 0, 0)
{
	
}


bool Nut::has_been_collected()
{
	return is_at_position(p_mouse_->x_, p_mouse_->y_);
}

void Nut::disappear()
{

}