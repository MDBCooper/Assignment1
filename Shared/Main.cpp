//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include <iostream>		// for output and input
#include <string>		// for string
#include <sstream>		// for streamstring

using namespace std;

#include "Game.h"

int main()
{
	UserInterface ui;
	Game game(&ui);

	do
	{
		game.run();
	} while (game.retry());

	ui.hold_window();
	return 0;
}