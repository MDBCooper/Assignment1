//Marcus Tryamane Kwame Angel-Whyte - 27010863
//Joshua Wastnidge - 27018846
//Matthew Cooper - 27014660

#include "Game.h"
#include <cassert>		// For Asserts
#include <iostream>		// for output and input
#include <string>		// for string
#include <sstream>		// for streamstring

RandomNumberGenerator Game::rng_ = RandomNumberGenerator();

Game::Game(UserInterface* pui) : p_ui(pui), player_(p_ui->get_Name())
{
	// mouse state already set up in its contructor

	// set up snake
	snake_.spot_mouse(&mouse_);

	// set up nut
	//nut_.mouse_location(&mouse_);
	mouse_.nut_location(&nut_);
}

const void Game::run()
{
	assert(p_ui != nullptr);
	int key_;

	p_ui->draw_grid_on_screen(prepare_grid());
	key_ = p_ui->get_keypress_from_user();
	do {
		Undo(key_);
		cheat_mode(key_);
		if (is_arrow_key_code(key_))
		{
			mouse_.scamper(key_);
			if (!cheatModeActive_) {
				snake_.chase_mouse();
			}
			p_ui->draw_grid_on_screen(prepare_grid());
			apply_rules();
		}
		undoData.Undone = false;
		undoData.Start = false;
		key_ = p_ui->get_keypress_from_user();
	} while (!has_ended(key_));

	p_ui->show_results_on_screen(prepare_end_message());
	reset_game();
}

const string Game::prepare_grid()
{
	// this function builds up a big string which holds the entire game state

	ostringstream os;

	for (int row(1); row <= SIZE; ++row)
	{
		for (int col(1); col <= SIZE; ++col)
		{
			if ((row == snake_.get_y()) && (col == snake_.get_x()))
			{
				os << snake_.get_symbol();
			}
			else
			{
				if ((row == snake_.snakeTail_.at(0).get_y()) && (col == snake_.snakeTail_.at(0).get_x()))
				{
					os << snake_.snakeTail_.at(0).get_symbol();
				}
				else
				{
					if ((row == snake_.snakeTail_.at(1).get_y()) && (col == snake_.snakeTail_.at(1).get_x()))
					{
						os << snake_.snakeTail_.at(1).get_symbol();
					}
					else
					{
						if ((row == snake_.snakeTail_.at(2).get_y()) && (col == snake_.snakeTail_.at(2).get_x()))
						{
							os << snake_.snakeTail_.at(2).get_symbol();
						}
						else
						{
							if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
							{
								os << mouse_.get_symbol();
							}
							else
							{
								if ((row == nut_.get_y()) && (col == nut_.get_x())) {
									os << nut_.get_symbol();
								}
								else {
									const int hole_no(underground_.find_hole_number_at_position(col, row));

									if (hole_no != -1)
										os << underground_.get_hole_no(hole_no).get_symbol();
									else
										os << FREECELL;
								}
							}
						}
					}
				}
			}
		}
		os << endl;
	}
	if (!cheatModeActive_) {
		os << "\n\n\n\nPlayer: " << player_.get_name() << "\nScore: " << player_.get_score();
	}
	else {
		os << "\n\n\n\nPlayer: " << player_.get_name() << "\nScore: " << player_.get_score() << "\n\nCHEAT MODE ACITVE!!!";
	}

	if (!undoData.Undone) {
		os << "";
	}
	else {
		os << "\nMOVE UNDONE!!!";
	}
	return os.str();
}

const bool Game::is_arrow_key_code(int keycode)
{
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

void Game::apply_rules()
{
	if (snake_.has_caught_mouse())
	{
		mouse_.die();
		player_.update_score(-1);
	}
	else
	{
		if (underground_.has_Nut_reached_a_hole(nut_))
			nut_.disappear();

		if (underground_.has_Mouse_reached_a_hole(mouse_) && nut_.has_been_collected())
		{
			mouse_.escape_into_hole();
			player_.update_score(1);
		}
		else if(underground_.has_Mouse_reached_a_hole(mouse_) && !nut_.has_been_collected()) {
			switch (underground_.find_hole_number_at_position(mouse_.get_x(), mouse_.get_y()))
			{
			case (0):
				if (rng_.get_random_value(2) == 1) 
					mouse_.reset_position(underground_.get_hole_no(1).get_x(), underground_.get_hole_no(1).get_y());
				else
					mouse_.reset_position(underground_.get_hole_no(2).get_x(), underground_.get_hole_no(2).get_y());
				break;
			case (1):
				if (rng_.get_random_value(2) == 1)
					mouse_.reset_position(underground_.get_hole_no(0).get_x(), underground_.get_hole_no(0).get_y());
				else
					mouse_.reset_position(underground_.get_hole_no(2).get_x(), underground_.get_hole_no(2).get_y());
				break;
			case (2):
				if (rng_.get_random_value(2) == 1)
					mouse_.reset_position(underground_.get_hole_no(0).get_x(), underground_.get_hole_no(0).get_y());
				else
					mouse_.reset_position(underground_.get_hole_no(1).get_x(), underground_.get_hole_no(1).get_y());
				break;
			default:
				break;
			}
		}
	}
}

const bool Game::has_ended(char key) const
{
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}

const string Game::prepare_end_message() const
{
	ostringstream os;
	if (mouse_.has_escaped())
	{
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!\nMISSION FAILED! WE'LL GET 'EM NEXT TIME";
	}
	else
	{
		if (!mouse_.is_alive())
		{
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!\nLADIES AND GENTLEMEN... WE GOT 'EM!";
		}
		else
		{
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
		}
	}
	return os.str();
}

void Game::cheat_mode(char key) {
	if (key == 'C') {
		player_.has_cheated();
		cheatModeActive_ = !cheatModeActive_;
	}
}

void Game::Undo(char key) {
	
	if (key == 'U' && !undoData.Undone && !undoData.Start) {
		mouse_.reset_position(undoData.MouseX, undoData.MouseY);
		mouse_.AssignAlive(undoData.MouseAlive);
		mouse_.AssignEscaped(undoData.MouseEscaped);
		snake_.reset_position(undoData.SnakeX, undoData.SnakeY);
		snake_.snakeTail_.at(0).reset_position(undoData.Tail1X, undoData.Tail1Y);
		snake_.snakeTail_.at(1).reset_position(undoData.Tail2X, undoData.Tail2Y);
		snake_.snakeTail_.at(2).reset_position(undoData.Tail3X, undoData.Tail3Y);
		nut_.reset_position(undoData.NutX, undoData.NutY);
		nut_.AssignCollected(undoData.NutCollected);
		undoData.Undone = true;
		p_ui->draw_grid_on_screen(prepare_grid());
	}
	undoData.MouseX = mouse_.get_x();
	undoData.MouseY = mouse_.get_y();
	undoData.MouseAlive = mouse_.is_alive();
	undoData.MouseEscaped = mouse_.has_escaped();
	undoData.SnakeX = snake_.get_x();
	undoData.SnakeY = snake_.get_y();
	undoData.Tail1X = snake_.snakeTail_.at(0).get_x();
	undoData.Tail1Y = snake_.snakeTail_.at(0).get_y();
	undoData.Tail2X = snake_.snakeTail_.at(1).get_x();
	undoData.Tail2Y = snake_.snakeTail_.at(1).get_y();
	undoData.Tail3X = snake_.snakeTail_.at(2).get_x();
	undoData.Tail3Y = snake_.snakeTail_.at(2).get_y();
	undoData.NutX = nut_.get_x();
	undoData.NutY = nut_.get_y();

	undoData.NutCollected = nut_.has_been_collected();
}

bool Game::retry()
{
	cout << "\nRetry? (Y/N): ";
	char temp;
	cin >> temp;
	return toupper(temp) == 'Y';
}

void Game::reset_game()
{
	snake_.reset();
	mouse_.reset();
	nut_.reset();
	cheatModeActive_ = false;
	undoData.Start = true;
	player_.reset();
}