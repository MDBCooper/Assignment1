//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#ifndef UserInterfaceH
#define UserInterfaceH 


#include <iostream>		
#include <string>		

using namespace std;

class UserInterface
{
public:
	int get_keypress_from_user() const;
	void draw_grid_on_screen(const string& grid_data);
	void show_results_on_screen(string message);
	const void hold_window();
	const string get_Name();
};

#endif