////////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_HPP
#define GAME_HPP
//---------------------------------------------------------------------------------
#include<string>
#include<iostream>
#include<vector>
#include <ctime>
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//Character Domain
//=================================================================================
//The character domain holds all of the classes
//that deal with characters (players).
//---------------------------------------------------------------------------------
//1.)Character - Base Class that holds all of the basic information for the player. 
class character
{
protected:
	std::string character_name;
	char character_icon;
	int money_won;
	int win_count;
public:
	//Constructors
	character(); 
	character(std::string, char);
	//Mutators
	void add_win() { this->win_count = win_count + 1; }
	//ACCESSORS
	void name_output();
	void icon_output();
	void win_count_output();
	char return_char_icon();
};
//---------------------------------------------------------------------------------
//2.)player_character is a subclass that deals with actual player characters. 
class player_character : character
{
public:
	int get_player_input();
};
//---------------------------------------------------------------------------------
//3.)machine_character is a subclass that deals with the machine posing as a player.
class machine_character : character
{
public:
	int get_machine_input();
};
//---------------------------------------------------------------------------------
//=================================================================================
//End of Character Domain
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//Board Domain
//=================================================================================
//The Board domain holds all of the classes that deal with the visual rep. of the
//board on the console. 
//---------------------------------------------------------------------------------
//1.)Board is the class that holds all of the functionality that draws up the board.
class board
{
private:
	char board_cells[10];
public:
	board();
	void create_cell(player_character &, const int);
	void create_cell (machine_character &, const int);
	void board_generation (player_character & player_1, player_character & player_2);
	void board_generation(player_character & player_1, machine_character & player_2);
	void board_reset();
};
//---------------------------------------------------------------------------------
//=================================================================================
//End of the Board Domain
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//Game Domain
//=================================================================================
//The game domain holds all of the classes that deal with the game functioning. 
//---------------------------------------------------------------------------------
//1.)Base_Game is the parent class that holds all of the basic game functions.
class base_game
{
protected:
	std::vector<int> player_1_moves;
	std::vector<int> player_2_moves;
	int current_move;
	std::vector<int> completed_moves;
	board game_board;
	bool game_complete;
	bool player_1_turn;
public:
	base_game();
	void run_game();
	void reset();
	void check_game(); //After every move, the game will check to see if the game has been completed. It will also assign the next player to go.
	void player_move(); //Player move will be made after every check, they will type a number in from 1 to 9 to choose their space.
	void play(); //Play run's the game each frame, and runs in the run_game file;
	void board_refresh();
	bool cell_check(const int &);
	void new_game(); //At completion of the game, the player will be asked if they want to start a new game.
};
//---------------------------------------------------------------------------------
//2.)pvp deals with the functionality between two player characters. 
class pvp : base_game
{
protected:
	player_character player_1;
	player_character player_2;
public:
	pvp();
};
//---------------------------------------------------------------------------------
//3.) pvm deals with player vs machine functionality. 
class pvm : base_game
{
protected:
	player_character player_1;
	machine_character npc;
public:
	pvm();
	void player_move();	
};
//---------------------------------------------------------------------------------
//=================================================================================
//End of Game Domain
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//Execution Domain
//=================================================================================
//The execution domain deals with the class that executes the application.
//---------------------------------------------------------------------------------
//1.)Execute deals with executing the program. 
class execute
{
private: 
	bool game_type;
public:
	execute();
};
//---------------------------------------------------------------------------------
//=================================================================================
//End of Execution Domain
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
#endif
///////////////////////////////////////////////////////////////////////////////////
