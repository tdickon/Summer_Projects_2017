#include "game_file.h"

bool array_check(std::vector<int> user_vector)
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

//-------------------------------------------------------------------------
void reset_move_set(std::vector<int> & player_moves)
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

//********************************************************************************
//--CHARACTER DOMAIN--
//*********************************************************************************
///////////////////////////////////////////////////////////////////////////////////
//!!CLASSES IN DOMAIN ARE LOCATED BELOW!!
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//**CHARACTER_CLASS**
//=================================================================================
//---------------------------------------------------------------------------------
//++CONSTRUCTORS++
//---------------------------------------------------------------------------------
//1.)Default Constructor
character::character()
{
	character_name = "\0";
	character_icon = '\0';
	win_count = 0;
	money_won = 0;
}
//---------------------------------------------------------------------------------
//2.) CTOR that takes a string name and a char icon
character::character(std::string user_name, char user_icon)
{
	character_name = user_name;
	character_icon = user_icon;
	win_count = 0;
	money_won = 0;
}
//----------------------------------------------------------------------------------
//++ACCESSORS++
//----------------------------------------------------------------------------------
//1.)name_output - outputs the user's name.
void character::name_output()
{
	std::cout << character_name;
}
//----------------------------------------------------------------------------------
//2.)icon_output - outputs the user's icon. 
void character::icon_output()
{
	std::cout << character_icon;
}
//-----------------------------------------------------------------------------------
//3.)win_count_output - outputd the user's win total
void character::win_count_output()
{
	std::cout << win_count;
}
//-----------------------------------------------------------------------------------
//4.)return_char_icon - returns the user's icon to be used in other functions
char character::return_char_icon()
{
	return character_icon;
}
//-----------------------------------------------------------------------------------
//===================================================================================
//**END OF CHARACTER CLASS**
//===================================================================================
/////////////////////////////////////////////////////////////////////////////////////
//===================================================================================
//**PLAYER_CHARACTER CLASS**
//===================================================================================
//-----------------------------------------------------------------------------------
//++GETTERS++
//-----------------------------------------------------------------------------------
//1.) get_user_input - returns the user's cell input.
int player_character::get_player_input()
{
	int user_cell_selection;
	std::cout << "Please choose a cell:  "; std::cin >> user_cell_selection;
	std::cout << std::endl;
}
//------------------------------------------------------------------------------------
//====================================================================================
//**END PLAYER_CHARACTER CLASS**
//====================================================================================
//////////////////////////////////////////////////////////////////////////////////////
//====================================================================================
//**MACHINE_CHARACTER CLASS**
//====================================================================================
//------------------------------------------------------------------------------------
//++GETTERS++
//------------------------------------------------------------------------------------
//1.) get_machine_input - generates a random number and returns it. 
int machine_character::get_machine_input()
{
	srand(time(NULL));
	return (rand() % 10);
}
//------------------------------------------------------------------------------------
//====================================================================================
//**END MACHINE_CHARACTER CLASS**
//====================================================================================

//=========================================================================
//**BOARD CLASS**
//-------------------------------------------------------------------------
//++CONSTRUCTORS++
//-------------------------------------------------------------------------
//1.)Default Constructor
board::board()
{
	for (int box_index = 0; box_index < 10; ++box_index)
	{
		board_boxes[box_index] = box_index + '0';
	}
}
//-------------------------------------------------------------------------
//++CREATE_BOARD++
//-------------------------------------------------------------------------
void board::create_box(player & user, const int box_value)
{
	char user_icon = user.return_user_icon();
	int index = 0;
	while (index < 10)
	{
		if (index == box_value)
		{
			board_boxes[index] = user_icon;
			return;
		}
		else
		{
			++index;
		}
	}
}
//------------------------------------------------------------------------
void board::board_reset()
{
	for (int box_index = 0; box_index < 10; ++box_index)
	{
		board_boxes[box_index] = box_index + '0';
	}
}
//-------------------------------------------------------------------------
//++BOARD GENERATION
//-------------------------------------------------------------------------
void board::board_generation(player & player_1, player & player_2)
{
	std::cout << "\n\n\tTIC-TAC-TOE\n" << std::endl;
	player_1.name_output(); std::cout << "("; player_1.icon_output(); std::cout << "): "; player_1.win_count_output();
	std::cout << " to "; player_2.win_count_output(); std::cout << ":("; player_2.icon_output(); std::cout << ")";
	player_2.name_output(); std::cout << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_boxes[1] << "  |  " << board_boxes[2]
		<< "  |  " << board_boxes[3] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_boxes[4] << "  |  " << board_boxes[5]
		<< "  |  " << board_boxes[6] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_boxes[7] << "  |  " << board_boxes[8]
		<< "  |  " << board_boxes[9] << std::endl;
	std::cout << "     |     |     " << std::endl;
}
//----------------------------------------------------------------------
//END OF BOARD CLASS
//----------------------------------------------------------------------
//=========================================================================
//FREE FUNCTIONS
//=========================================================================
//1.)A function that returns a string value name.
std::string get_name()
{
	std::string return_name;
	system("CLS");
	std::cout << "Please Enter a username: ";
	std::cin >> return_name; std::cout << std::endl;
	return return_name;
}
//-------------------------------------------------------------------------
//2.)A function that returns a character value icon
char get_icon()
{
	char return_icon;
	system("CLS");
	std::cout << "Please Enter a Single Character for your Icon: ";
	std::cin >> return_icon; std::cout << std::endl;
	return return_icon;
}
//-------------------------------------------------------------------------
//=========================================================================
//END OF FREE FUNCTIONS
//=========================================================================
//======================================================================
//GAME CLASS
//======================================================================
//CONSTRUCTORS
//----------------------------------------------------------------------
//1.)Default Constructor
game::game()
{
	game_complete = false;
	player_1_turn = true;
}
//----------------------------------------------------------------------
void game::new_game()
{
	//Get Player 1's information.
	{
		std::string user_name = get_name();
		char user_icon = get_icon();
		player tmp_player(user_name, user_icon);
		player_1 = tmp_player;
	}

	//Get Player 2's information.

	{
		std::string user_name = get_name();
		char user_icon = get_icon();
		player tmp_player(user_name, user_icon);
		player_2 = tmp_player;
	}

	system("CLS");
	game_board.board_generation(player_1, player_2);
}
//----------------------------------------------------------------------
void game::player_move()
{
	if (player_1_turn == true)
	{
		player_1.name_output();
		std::cout << ", what block would you like to select? (Please Enter a number): ";
		std::cin >> current_move; std::cout << std::endl;

		if (std::cin.fail() || current_move <= 0 || current_move >= 10 || box_check(current_move) == false)
		{
			bool tmp = true;
			while (tmp == true)
			{
				if (std::cin.fail() || current_move <= 0 || current_move >= 10 || box_check(current_move) == false)
				{
					std::cin.clear();
					std::cin.ignore(100, '\n');
					this->board_refresh();
					player_1.name_output();
					std::cout << " please re-enter your number: ";
					std::cin >> current_move; std::cout << std::endl;
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
		std::cout << " , what block would you like to select? (Please Enter a number): ";
		std::cin >> current_move; std::cout << std::endl;
		if (std::cin.fail() || current_move <= 0 || current_move >= 10 || box_check(current_move) == false)
		{
			bool tmp = true;
			while (tmp == true)
			{
				if (std::cin.fail() || current_move <= 0 || current_move >= 10 || box_check(current_move) == false)
				{
					std::cin.clear();
					std::cin.ignore(100, '\n');
					this->board_refresh();
					player_2.name_output();
					std::cout << " please re-enter your number: ";
					std::cin >> current_move; std::cout << std::endl;
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
//------------------------------------------------------------------------
void game::reset()
{
	reset_move_set(player_1_moves);
	reset_move_set(player_2_moves);
	game_complete = false;
	player_1_turn = true;
	game_board.board_reset();

}
//------------------------------------------------------------------------
void game::play()
{
	system("cls");
	board_refresh();
	bool game_close = false;
	int counter = 0;
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
			char tmp;
			system("CLS");
			std::cout << "Would you like to play again? [y/n]: ";
			std::cin >> tmp; std::cout << std::endl;

			if (tmp == 'y')
			{
				this->reset();
				this->play();

			}

			else
			{
				game_close = true;
				system("CLS");
				std::cout << "Thanks for playing!" << std::endl;
			}
		}
	}
}
//----------------------------------------------------------------------
void game::board_refresh()
{
	system("CLS");
	if (player_1_turn == false)
	{
		game_board.create_box(player_1, current_move);
		game_board.board_generation(player_1, player_2);
	}

	else if (player_1_turn == true)
	{
		game_board.create_box(player_2, current_move);
		game_board.board_generation(player_1, player_2);
	}
}
//----------------------------------------------------------------------
void game::check_game()
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
//---------------------------------------------------------------------
void game::run_game()
{
	this->new_game();
	this->play();
}
//---------------------------------------------------------------------
bool game::box_check(const int & box_selected)
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
//======================================================================
