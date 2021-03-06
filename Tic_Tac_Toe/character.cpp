#include "game_file.h"
#include <ctime>
//*********************************************************************************
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
void character::add_win()
{ 
	this->win_count = win_count + 1;
	if (win_count == 3)
	{
		this->money_won = 300000;
	}

	if (win_count == 6)
	{
		this->money_won = 600000;
	}

	if (win_count == 9)
	{
		this->money_won = 900000;
	}

	if (win_count == 10)
	{
		this->money_won = 1000000;
	}
}
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

	if (std::cin.fail() == true)
	{	
		bool pass_check = false;
		while (pass_check == false)
		{
			if (std::cin.fail() == true)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << " please re-enter your selection: ";
				std::cin >> user_cell_selection; std::cout << std::endl;
			}

			else
			{
				pass_check = true;
			}
		}
	}

	else
	{
		return user_cell_selection;
	}

	return user_cell_selection;
}
//------------------------------------------------------------------------------------//------------------------------------------------------------------------------------
//++OPERATOR OVERLOADING++
//------------------------------------------------------------------------------------
void player_character::operator=(player_character right_hand_side)
{
	this->character_name = right_hand_side.character_name;
	this->character_icon = right_hand_side.character_icon;
	this->win_count = right_hand_side.win_count;
	this->money_won = right_hand_side.money_won;
}
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
	return ((rand() % 9) + 1);
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//++OPERATOR OVERLOADING++
//------------------------------------------------------------------------------------
void machine_character::operator=(machine_character right_hand_side)
{
	this->character_name = right_hand_side.character_name;
	this->character_icon = right_hand_side.character_icon;
	this->win_count = right_hand_side.win_count;
	this->money_won = right_hand_side.money_won;
}
//====================================================================================
//**END MACHINE_CHARACTER CLASS**
//====================================================================================
//////////////////////////////////////////////////////////////////////////////////////
//************************************************************************************
//--END OF CHARACTER DOMAIN--
//************************************************************************************
