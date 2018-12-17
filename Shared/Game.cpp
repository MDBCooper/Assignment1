#include "Game.h"
#include <cassert>		// For Asserts
#include <iostream>		// for output and input
#include <string>		// for string
#include <sstream>		// for streamstring

const void Game::set_up(UserInterface* pui)
{
	// set up the holes
	underground_.set_hole_no_at_position(0, 4, 3);  //Move?
	underground_.set_hole_no_at_position(1, 15, 10);  //Move? //Move?
	underground_.set_hole_no_at_position(2, 7, 15); //Move?

	// mouse state already set up in its contructor

	// set up snake
	//snake_.position_at_random();
	snake_.spot_mouse(&mouse_);

	// set up nut
	nut_.mouse_location(&mouse_);

	// set up the UserInterface
	p_ui = pui;
}

const void Game::run()
{
	//assert(p_ui != nullptr);

	p_ui->draw_grid_on_screen(prepare_grid());
	key_ = p_ui->get_keypress_from_user();

	while (!has_ended(key_))
	{
		if (is_arrow_key_code(key_))
		{
			mouse_.scamper(key_);
			snake_.chase_mouse();
			p_ui->draw_grid_on_screen(prepare_grid());
			apply_rules();
		}

		key_ = p_ui->get_keypress_from_user();
	}

	p_ui->show_results_on_screen(prepare_end_message());
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
				if ((row == snake_.get_Tail_y(0)) && (col == snake_.get_Tail_x(0)))
				{
					os << snake_.get_Tail_Symbol(0);
				}
				else
				{
					if ((row == snake_.get_Tail_y(1)) && (col == snake_.get_Tail_x(1)))
					{
						os << snake_.get_Tail_Symbol(1);
					}
					else
					{
						if ((row == snake_.get_Tail_y(2)) && (col == snake_.get_Tail_x(2)))
						{
							os << snake_.get_Tail_Symbol(2);
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
									const int hole_no(underground_.find_hole_number_at_position(col, row));  //Move?

									if (hole_no != -1)
										os << underground_.get_hole_no(hole_no).get_symbol(); //Move?
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

	return os.str();
}

const bool Game::is_arrow_key_code(int keycode)
{
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}



const void Game::apply_rules()
{
	if (snake_.has_caught_mouse())
	{
		mouse_.die();
	}
	else
	{
		nut_.has_been_collected();
		if (underground_.has_Mouse_reached_a_hole(mouse_) && nut_.has_been_collected()) //Move?
		{
			mouse_.escape_into_hole(); //Move?
		}
	}
}

const bool Game::has_ended(char key)
{
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}

const string Game::prepare_end_message()
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