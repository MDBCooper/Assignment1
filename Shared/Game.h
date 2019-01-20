#ifndef GameH 
#define GameH 

#include "Mouse.h"
#include "Snake.h"
#include "Nut.h"
#include "UserInterface.h"
#include "Underground.h"
#include "Player.h"
#include "RandomNumberGenerator.h";

class Game
{
private:
	Mouse mouse_;
	Snake snake_;
	Nut nut_;
	Underground underground_;
	UserInterface* p_ui;
	Player player_;
	bool cheatModeActive_ = false;

	const string prepare_grid();
	const bool is_arrow_key_code(int keycode);
	const void apply_rules();
	void reset_game();
	void cheat_mode(char);

	const bool has_ended(char key);
	const string prepare_end_message() const;

	static RandomNumberGenerator rng_;
public:
	Game(UserInterface*);
	const void run();
	bool retry();
};

#endif