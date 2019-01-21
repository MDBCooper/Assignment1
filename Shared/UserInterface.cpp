//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include <conio.h>	// for _getch()

#include "UserInterface.h" 

int UserInterface::get_keypress_from_user() const
{	//DO NOT CHANGE THIS FUNCTION
	// read in the selected arrow key or command letter
	int key_pressed(_getch());

	// ignore symbol following cursor key
	while (key_pressed == 224)
		key_pressed = _getch();

	// return the key in uppercase
	return(toupper(key_pressed));
}

void UserInterface::draw_grid_on_screen(const string& grid_data)
{
	// clear screen
	system("cls");

	cout << grid_data;
}

void UserInterface::show_results_on_screen(string message)
{
	cout << message;
}

const void UserInterface::hold_window()
{
	cout << "\n\n";
	system("pause");
}

const string UserInterface::get_Name()
{
	string temp;
	cout << "Please enter your name: ";
	cin >> temp;
	return temp;
}