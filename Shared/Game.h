#ifndef GameH 
#define GameH 

#include "Underground.h"
#include "Mouse.h"
#include "Snake.h"
#include "UserInterface.h"

class Game
{
private:
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;

	int key_;
	const string prepare_grid();
	const bool is_arrow_key_code(int keycode);
	const void apply_rules();

	const bool has_ended(char key);
	const string prepare_end_message();
public:
	const void set_up(UserInterface* pui);
	const void run();
};

#endif