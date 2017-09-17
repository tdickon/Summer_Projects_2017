#include "game_file.h"
//***********************************************************************************
//--BOARD DOMAIN--
//***********************************************************************************
/////////////////////////////////////////////////////////////////////////////////////
//!!CLASSES IN DOMAIN ARE LOCATED BELOW!!
/////////////////////////////////////////////////////////////////////////////////////
//===================================================================================
//**BOARD_CLASS**
//===================================================================================
//-----------------------------------------------------------------------------------
//++CONSTRUCTORS++
//-----------------------------------------------------------------------------------
//1.)Default Constructor 
board::board()
{
	for (int cell_index = 0; cell_index < 10; ++cell_index)
	{
		board_cells[cell_index] = cell_index + '0';
	}
}
//-----------------------------------------------------------------------------------
//++GENERATING THE BOARD++
//-----------------------------------------------------------------------------------
//1.)The first generation deals with two players (PvP situation)
void board::board_generation(player_character & player_1, player_character & player_2)
{
	std::cout << "\n\n\tTIC-TAC-TOE\n" << std::endl;
	player_1.name_output(); std::cout << "("; player_1.icon_output(); std::cout << "): "; player_1.win_count_output();
	std::cout << " to "; player_2.win_count_output(); std::cout << ":("; player_2.icon_output(); std::cout << ")";
	player_2.name_output(); std::cout << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_cells[1] << "  |  " << board_cells[2]
		<< "  |  " << board_cells[3] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_cells[4] << "  |  " << board_cells[5]
		<< "  |  " << board_cells[6] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_cells[7] << "  |  " << board_cells[8]
		<< "  |  " << board_cells[9] << std::endl;
	std::cout << "     |     |     " << std::endl;
}
//-----------------------------------------------------------------------------------
//2.)
void board::board_generation(player_character & player_1, machine_character & player_2)
{
	std::cout << "\n\n\tTIC-TAC-TOE\n" << std::endl;
	player_1.name_output(); std::cout << "("; player_1.icon_output(); std::cout << "): "; player_1.win_count_output();
	std::cout << " to "; player_2.win_count_output(); std::cout << ":("; player_2.icon_output(); std::cout << ")";
	player_2.name_output(); std::cout << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_cells[1] << "  |  " << board_cells[2]
		<< "  |  " << board_cells[3] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_cells[4] << "  |  " << board_cells[5]
		<< "  |  " << board_cells[6] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board_cells[7] << "  |  " << board_cells[8]
		<< "  |  " << board_cells[9] << std::endl;
	std::cout << "     |     |     " << std::endl;
}
//-----------------------------------------------------------------------------------
//===================================================================================
//++CREATING THE INDIVIDUAL CELL++
//===================================================================================
//1.)Generating the cell if a player chooses it. 
void board::create_cell(player_character & player, const int cell_selected)
{
	char user_icon = player.return_char_icon();
	int index = 0;
	while (index < 10)
	{
		if (index == cell_selected)
		{
			board_cells[index] = user_icon;
			return;
		}
		else
		{
			++index;
		}
	}
}
//-----------------------------------------------------------------------------------
//2.)Generating a cell if the machine chooses it. 
void board::create_cell(machine_character & machine, const int cell_selected)
{
	char user_icon = machine.return_char_icon();
	int index = 0;
	while (index < 10)
	{
		if (index == cell_selected)
		{
			board_cells[index] = user_icon;
			return;
		}
		else
		{
			++index;
		}
	}
}
//-----------------------------------------------------------------------------------
//===================================================================================
//++BOARD RESET++
//===================================================================================
//1.)reset_board - wipes all of the cells clean, so the game can be played again
void board::board_reset()
{
	for (int cell_index = 0; cell_index < 11; ++cell_index)
	{
		board_cells[cell_index] = cell_index + '0';
	}
}
//-----------------------------------------------------------------------------------
//===================================================================================
//**END OF BOARD_CLASS**
//===================================================================================
//////////////////////////////////////////////////////////////////////////////////////
//************************************************************************************
//--END OF BOARD DOMAIN--
//************************************************************************************