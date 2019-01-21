//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

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
	void apply_rules();
	void reset_game();
	void cheat_mode(char);

	const bool has_ended(char key) const;
	const string prepare_end_message() const;
	void Undo(char);
	static RandomNumberGenerator rng_;
	struct UndoData
	{
		int MouseX;
		int MouseY;
		int SnakeX;
		int SnakeY;
		int Tail1X;
		int Tail1Y;
		int Tail2X;
		int Tail2Y;
		int Tail3X;
		int Tail3Y;
		int NutX;
		int NutY;
		bool MouseAlive;
		bool MouseEscaped;
		bool NutCollected;
		bool Undone = false;
		bool Start = true;
	};
	UndoData undoData;
public:
	Game(UserInterface*);
	const void run();
	bool retry();
};

#endif