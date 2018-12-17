#include "Nut.h"
#include "Constants.h"
#include "Mouse.h"
#include "Snake.h"
#include "RandomNumberGenerator.h"

Nut::Nut() : MoveableGridItem(NUT, 8, 9), collected(false)
{
	p_mouse_ = nullptr;
}


bool Nut::has_been_collected()
{
	if (is_at_position(p_mouse_->get_x(), p_mouse_->get_y())) {
		collected = true;
	}
	disappear();
	return collected;
}

void Nut::disappear()
{
	if (collected) {
		update_position(-get_x(), -get_y());
	}
}

void Nut::mouse_location(Mouse* p_mouse) {
	p_mouse_ = p_mouse;
}