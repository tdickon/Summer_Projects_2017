#include "game_file.h"
//*********************************************************************************
//--EXECUTE DOMAIN--
//*********************************************************************************
///////////////////////////////////////////////////////////////////////////////////
//!!CLASSES IN DOMAIN ARE LOCATED BELOW!!
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//**EXECUTE CLASS**
//=================================================================================
//---------------------------------------------------------------------------------
//++PROTECTED MEMBER FUNCTIONS++
//---------------------------------------------------------------------------------
//1.)return_game_type - returns an int that will signal which game type to choose.
int execute::return_game_type()
{
	int tmp_return;
	std::cout << "Please Choose a Game Type: [0 for Player vs Player / 1 for Player vs Machine]: ";
	std::cin >>tmp_return; std::cout << std::endl;

	if (std::cin.fail() == true || tmp_return < 0 || tmp_return > 1)
	{
		bool pass_check = false;
		while (pass_check == false)
		{
			if (std::cin.fail() == true || tmp_return < 0 || tmp_return > 1)
			{
				refresh_screen();
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Please Choose a Game Type: [0 for Player vs Player / 1 for Player vs Machine]: " << std::endl;
				std::cout << " please re-enter your selection: ";
				std::cin >> tmp_return; std::cout << std::endl;
			}

			else
			{
				pass_check = true;
			}
		}
	}

	else
	{
		return tmp_return;
	}
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//++CONSTRUCTORS++
//---------------------------------------------------------------------------------
execute::execute()
{
	game_type = return_game_type();

	if (game_type == 0)
	{
		pvp game;
	}

	else if (game_type == 1)
	{
		pvm game;
	}
}
//---------------------------------------------------------------------------------
//=================================================================================
//**END OF EXECUTE CLASS**
//=================================================================================

//Free Function that will execute the game.
void system_exe()
{
	execute application_exe;
}