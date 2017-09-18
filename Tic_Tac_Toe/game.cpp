#include "game_file.h"
void refresh_screen()
{ 
	for (int i = 0; i < 101; ++i) 
	{ 
		std::cout << "\n" << std::endl; 
	} 
}
//*********************************************************************************
//--GAME DOMAIN--
//*********************************************************************************
///////////////////////////////////////////////////////////////////////////////////
//!!CLASSES IN DOMAIN ARE LOCATED BELOW!!
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//**BASE_GAME CLASS**
//=================================================================================
//---------------------------------------------------------------------------------
//++PROTECTED MEMBER FUNCTIONS++
//---------------------------------------------------------------------------------
//1.)Get user's name. 
std::string base_game::get_user_name()
{
	std::string return_name;
	refresh_screen();
	std::cout << "Please Enter a username: ";
	std::cin >> return_name; std::cout << std::endl;
	return return_name;
}
//---------------------------------------------------------------------------------
void base_game::reset_move_set(std::vector<int> & player_moves)
{
	if (player_moves.empty() == false)
	{
		while (player_moves.empty() == false)
		{
			player_moves.pop_back();
		}
	}

	else
	{
		return;
	}
}
//---------------------------------------------------------------------------------
bool base_game::array_check(std::vector<int> user_vector)
{
	int tmp[5] = { 0,0,0,0,0 };
	int index = 0;
	while (user_vector.empty() == false)
	{
		tmp[index] = user_vector.back();
		user_vector.pop_back();
		++index;
	}

	bool tmp_check = false;
	int tmp_index = 0;
	int win_counter = 0;
	int y = 0;
	for (int x = 0; x < 8; ++x)
	{
		while (y < 3)
		{
			if (tmp[tmp_index] == winning_combos[x][y])
			{
				++win_counter;
				++tmp_index;
				y = 0;
			}

			else
			{
				++y;
			}

			if (win_counter == 3)
			{
				return true;
			}

			if (y == 3 && tmp[tmp_index + 1] != 0)
			{
				++tmp_index;
				y = 0;
			}
		}
		win_counter = 0;
		y = 0;
		tmp_index = 0;
		if (x == 7)
		{
			return false;
		}
	}
	return false;
}
//---------------------------------------------------------------------------------
//++CONSTRUCTORS++
//---------------------------------------------------------------------------------
//1.)Default Constructor - initializes a new game. 
base_game::base_game()
{
	game_complete = false;
	player_1_turn = true; 
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//++RESET_GAME++
//---------------------------------------------------------------------------------
//1.)reset_game
void base_game::reset()
{
	reset_move_set(player_1_moves);
	reset_move_set(player_2_moves);
	reset_move_set(completed_moves);
	current_move = 0;
	this->game_complete = false;
	this->player_1_turn = true;
	game_board.board_reset();
}
//---------------------------------------------------------------------------------
//++CELL_CHECK++
//---------------------------------------------------------------------------------
bool base_game::cell_check(const int & box_selected)
{
	int size = completed_moves.size();
	for (int index = 0; index < size; ++index)
	{
		if (box_selected == completed_moves[index])
		{
			return false;
		}
	}
	return true;
}
//=================================================================================
//**END OF BASE_GAME CLASS**
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//**PVP CLASS**
//=================================================================================
//---------------------------------------------------------------------------------
void pvp::new_game()
{
	//Get Player_1's information.
	{
		std::string user_name = get_user_name();
		player_1.set_name(user_name);
		player_1.set_icon('X');
	}

	//Get Player_2's information. 
	{
		std::string user_name = get_user_name();
		player_2.set_name(user_name);
		player_2.set_icon('O');
	}

	//INSERT A JUMP SCREEN HERE 
	game_board.board_generation(player_1,player_2);
}
//---------------------------------------------------------------------------------
void pvp::player_move()
{

	if (player_1_turn == true)
	{
		player_1.name_output();
		current_move = player_1.get_player_input();
		if ( current_move <= 0 || current_move >= 10 || cell_check(current_move) == false)
		{
			//Keep re-asking for a cell until the user input's a valid input to the system.
			bool tmp = true;
			while (tmp == true)
			{
				if (current_move <= 0 || current_move >= 10 || cell_check(current_move) == false)
				{
					this->board_refresh();
					player_1.name_output();
					std::cout << " please re-enter your number: ";
					current_move = player_1.get_player_input();
				}
				else
				{
					tmp = false;
				}
			}
		}

		player_1_moves.push_back(current_move);
		completed_moves.push_back(current_move);
		player_1_turn = false;
	}

	else if (player_1_turn == false)
	{
		player_2.name_output();
		current_move = player_2.get_player_input();
		if ( current_move <= 0 || current_move >= 10 || cell_check(current_move) == false)
		{
			//Keep re-asking for a cell until the user input's a valid input to the system.
			bool tmp = true;
			while (tmp == true)
			{
				if ( current_move <= 0 || current_move >= 10 || cell_check(current_move) == false)
				{
					this->board_refresh();
					player_2.name_output();
					std::cout << " please re-enter your number: ";
					current_move = player_2.get_player_input();
				}
				else
				{
					tmp = false;
				}
			}
		}
		player_2_moves.push_back(current_move);
		completed_moves.push_back(current_move);
		player_1_turn = true;
	}
}
//---------------------------------------------------------------------------------
void pvp::check_game()
{
	if (player_1_turn == false)
	{
		if (player_1_moves.size() >= 3)
		{
			bool tmp = array_check(player_1_moves);
			if (tmp == true)
			{
				game_complete = true;
				player_1.add_win();
			}
			else
			{
				return;
			}
		}

		else
		{
			return;
		}
	}

	else if (player_1_turn == true)
	{
		if (player_2_moves.size() >= 3)
		{
			bool tmp = array_check(player_2_moves);
			if (tmp == true)
			{
				game_complete = true;
				player_2.add_win();
			}

			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
}
//---------------------------------------------------------------------------------
void pvp::play()
{
	game_complete = false;
	refresh_screen();
	board_refresh();
	bool game_close = false;
	int counter = 0;
	int player_1_wins = player_1.return_win_count();
	int player_2_wins = player_2.return_win_count();
	
	while (player_1_wins <= 10 || player_2_wins <= 10)
	{
		while (game_close == false)
		{

			while (game_complete == false)
			{
				if (counter == 9)
				{
					this->check_game();
					current_move = 0;
					counter = 0;
					for (int index = 0; index < 9; ++index)
					{
						completed_moves[index] = 0;
					}
					this->reset();
					this->board_refresh();
					std::cout << "All blocks have been filled without a winner, please play again!" << std::endl;
				}

				this->player_move();
				this->check_game();
				this->board_refresh();
				++counter;
			}

			if (game_complete == true)
			{
				player_1_wins = player_1.return_win_count();
				player_2_wins = player_2.return_win_count();
				char tmp;
				refresh_screen();
				std::cout << "Would you like to play again? [y/n]: ";
				std::cin >> tmp; std::cout << std::endl;

				if (tmp == 'y')
				{
					if (player_1_wins == 10 || player_2_wins == 10)
					{
						game_close = true;
						refresh_screen();
						std::cout << "Thanks for playing!" << std::endl;
						player_1.name_output(); std::cout << ": "; player_1.return_money_won();
						std::cout << std::endl;
						player_2.name_output(); std::cout << ": "; player_2.return_money_won();
					}

					else
					{
						this->reset();
						this->play();
					}

				}

				else
				{
					game_close = true;
					refresh_screen();
					std::cout << "Thanks for playing!" << std::endl;
					player_1.name_output(); std::cout << ": "; player_1.return_money_won();
					std::cout << std::endl;
					player_2.name_output(); std::cout << ": "; player_2.return_money_won();
				}
			}
		}
	}

	if (player_1_wins == 10 || player_2_wins == 10)
	{
		refresh_screen();
		std::cout << "Thanks for playing!" << std::endl;
		player_1.name_output(); std::cout << ": "; player_1.return_money_won();
		std::cout << std::endl;
		player_2.name_output(); std::cout << ": "; player_2.return_money_won();
	}
}
//---------------------------------------------------------------------------------
void pvp::board_refresh()
{
	refresh_screen();
	if (player_1_turn == false)
	{
		game_board.create_cell(player_1, current_move);
		game_board.board_generation(player_1, player_2);
	}

	else if (player_1_turn == true)
	{
		game_board.create_cell(player_2, current_move);
		game_board.board_generation(player_1, player_2);
	}
}
//---------------------------------------------------------------------------------
void pvp::run_game()
{
	this->new_game();
	this->play();
}
//---------------------------------------------------------------------------------
//=================================================================================
//**END OF PVP CLASS**
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//**PVM CLASS**
//=================================================================================
void pvm::new_game()
{
	//Get Player_1's information
	{
		std::string user_name = get_user_name();
		player_1.set_name(user_name);
		player_1.set_icon('X');
	}

	//Machine Character Generation
	{
		player_2.set_name("npc");
		player_2.set_icon('O');
	}

	//INSERT A JUMP SCREEN HERE 
	game_board.board_generation(player_1, player_2);
}
//---------------------------------------------------------------------------------
void pvm::player_move()
{
	if (player_1_turn == true)
	{
		player_1.name_output();
		current_move = player_1.get_player_input();
		if (current_move <= 0 || current_move >= 10 || cell_check(current_move) == false)
		{
			//Keep re-asking for a cell until the user input's a valid input to the system.
			bool tmp = true;
			while (tmp == true)
			{
				if (current_move <= 0 || current_move >= 10 || cell_check(current_move) == false)
				{
					this->board_refresh();
					player_1.name_output();
					std::cout << " please re-enter your number: ";
					current_move = player_1.get_player_input();
				}
				else
				{
					tmp = false;
				}
			}
		}

		player_1_moves.push_back(current_move);
		completed_moves.push_back(current_move);
		player_1_turn = false;
	}

	else if (player_1_turn == false)
	{
		current_move = player_2.get_machine_input();
		if (cell_check(current_move) == false)
		{
			//Keep looping until the machine picks a cell not already chosen.
			bool tmp = true;
			while (tmp == true)
			{
				if (cell_check(current_move) == false)
				{
					current_move = player_2.get_machine_input();
				}
				else
				{
					tmp = false;
				}
			}
		}
		player_2_moves.push_back(current_move);
		completed_moves.push_back(current_move);
		player_1_turn = true;
	}
}
//---------------------------------------------------------------------------------
void pvm::check_game()
{
	if (player_1_turn == false)
	{
		if (player_1_moves.size() >= 3)
		{
			bool tmp = array_check(player_1_moves);
			if (tmp == true)
			{
				game_complete = true;
				player_1.add_win();
			}
			else
			{
				return;
			}
		}

		else
		{
			return;
		}
	}

	else if (player_1_turn == true)
	{
		if (player_2_moves.size() >= 3)
		{
			bool tmp = array_check(player_2_moves);
			if (tmp == true)
			{
				game_complete = true;
				player_2.add_win();
			}

			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
}
//---------------------------------------------------------------------------------
void pvm::play()
{
	game_complete = false;
	refresh_screen();
	board_refresh();
	bool game_close = false;
	int counter = 0;
	int player_1_wins = player_1.return_win_count();
	int player_2_wins = player_2.return_win_count();

	while (player_1_wins <= 10 || player_2_wins <= 10)
	{
		while (game_close == false)
		{
			while (game_complete == false)
			{
				if (counter == 9)
				{
					this->check_game();
					current_move = 0;
					counter = 0;
					for (int index = 0; index < 9; ++index)
					{
						completed_moves[index] = 0;
					}
					this->reset();
					this->board_refresh();
					std::cout << "All blocks have been filled without a winner, please play again!" << std::endl;
				}

				this->player_move();
				this->check_game();
				this->board_refresh();
				++counter;
			}

			if (game_complete == true)
			{
				player_1_wins = player_1.return_win_count();
				player_2_wins = player_2.return_win_count();
				char tmp;
				refresh_screen();
				std::cout << "Would you like to play again? [y/n]: ";
				std::cin >> tmp; std::cout << std::endl;

				if (tmp == 'y')
				{
					if (player_1_wins == 10 || player_2_wins == 10)
					{
						game_close = true;
						refresh_screen();
						std::cout << "Thanks for playing!" << std::endl;
						player_1.name_output(); std::cout << ": "; player_1.return_money_won();
						std::cout << std::endl;
						player_2.name_output(); std::cout << ": "; player_2.return_money_won();
					}

					else
					{
						this->reset();
						this->play();
					}
				}

				else
				{
					game_close = true;
					refresh_screen();
					std::cout << "Thanks for playing!" << std::endl;
					player_1.name_output(); std::cout << ": "; player_1.return_money_won();
					std::cout << std::endl;
					player_2.name_output(); std::cout << ": "; player_2.return_money_won();
				}
			}
		}
	}

	if (player_1_wins == 10 || player_2_wins == 10)
	{
		refresh_screen();
		std::cout << "Thanks for playing!" << std::endl;
		player_1.name_output(); std::cout << ": "; player_1.return_money_won();
		std::cout << std::endl;
		player_2.name_output(); std::cout << ": "; player_2.return_money_won();
	}
}
//---------------------------------------------------------------------------------
void pvm::board_refresh()
{
	refresh_screen();
	if (player_1_turn == false)
	{
		game_board.create_cell(player_1, current_move);
		game_board.board_generation(player_1, player_2);
	}

	else if (player_1_turn == true)
	{
		game_board.create_cell(player_2, current_move);
		game_board.board_generation(player_1, player_2);
	}
}
//---------------------------------------------------------------------------------
void pvm::run_game()
{
	this->new_game();
	this->play();
}
//---------------------------------------------------------------------------------
//=================================================================================
//**END OF PVM CLASS**
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************
//--END OF GAME DOMAIN--
//************************************************************************************
