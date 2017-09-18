////////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_FILE_HPP
#define GAME_FILE_HPP
//---------------------------------------------------------------------------------
#include<string>
#include<iostream>
#include<vector>
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
	void add_win();
	//ACCESSORS
	void name_output();
	void icon_output();
	void win_count_output();
	char return_char_icon();
	void return_money_won() { std::cout << "You won " << this->money_won << ", congrats!"; }
};
//---------------------------------------------------------------------------------
//2.)player_character is a subclass that deals with actual player characters. 
class player_character :  character
{
public:
	//Constructors
	player_character() { character::character(); }
	player_character(std::string user_name, char icon) { character::character(user_name, icon); }
	//Getters
	int get_player_input();
	//Mutators
	void add_win() { character::add_win(); }
	//ACCESSORS
	void name_output() { character::name_output(); }
	void icon_output() { character::icon_output(); }
	void win_count_output() { character::win_count_output(); }
	char return_char_icon() { return character_icon; }
	void operator=(player_character right_hand_side);
	void set_name(std::string user_name) { character_name = user_name; }
	void set_icon(char user_icon) { character_icon = user_icon; }
	int return_win_count() { return this->win_count; }
	void return_money_won() { character::return_money_won(); }
};
//---------------------------------------------------------------------------------
//3.)machine_character is a subclass that deals with the machine posing as a player.
class machine_character : character
{
public:
	//Constructors
	machine_character() { character::character(); }
	machine_character(std::string user_name, char icon) { character::character(user_name, icon); }
	//Getters
	int get_machine_input();
	//Mutators
	void add_win() { character::add_win(); }
	//ACCESSORS
	void name_output() { character::name_output(); }
	void icon_output() { character::icon_output(); }
	void win_count_output() { character::win_count_output(); }
	char return_char_icon() { return character_icon; }
	void operator=(machine_character right_hand_side);
	void set_name(std::string user_name) { character_name = user_name; }
	void set_icon(char user_icon) { character_icon = user_icon; }
	int return_win_count() { return this->win_count; }
	void return_money_won() { character::return_money_won(); }
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
	void create_cell(machine_character &, const int);
	void board_generation(player_character & player_1, player_character & player_2);
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
	std::string get_user_name();
	void reset_move_set(std::vector<int> &);
	bool array_check(std::vector<int>);
	const int winning_combos[8][3] =
	{
		{ 1, 2, 3 }, //0
		{ 4, 5, 6 }, //1
		{ 7, 8, 9 }, //2
		{ 1, 4, 7 }, //3
		{ 2, 5, 8 }, //4
		{ 3, 6, 9 }, //5
		{ 1, 5, 9 }, //6
		{ 7, 5, 3 } //7
	};
public:
	base_game();
	void reset();
	bool cell_check(const int &);
};
//---------------------------------------------------------------------------------
//2.)pvp deals with the functionality between two player characters. 
class pvp : base_game
{
protected:
	player_character player_1;
	player_character player_2;
public:
	pvp() { this->run_game(); }
	void run_game();
	void check_game(); //After every move, the game will check to see if the game has been completed. It will also assign the next player to go.
	void player_move(); //Player move will be made after every check, they will type a number in from 1 to 9 to choose their space.
	void play(); //Play run's the game each frame, and runs in the run_game file;
	void board_refresh();
	void new_game(); //At completion of the game, the player will be asked if they want to start a new game.
};
//---------------------------------------------------------------------------------
//3.) pvm deals with player vs machine functionality. 
class pvm : base_game
{
protected:
	player_character player_1;
	machine_character player_2;
public:
	pvm() { this->run_game(); }
	void run_game();
	void check_game(); //After every move, the game will check to see if the game has been completed. It will also assign the next player to go.
	void player_move(); //Player move will be made after every check, they will type a number in from 1 to 9 to choose their space.
	void play(); //Play run's the game each frame, and runs in the run_game file;
	void board_refresh();
	void new_game(); //At completion of the game, the player will be asked if they want to start a new game.
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
	int game_type;
	int return_game_type();
public:
	execute();
};
//---------------------------------------------------------------------------------
//=================================================================================
//End of Execution Domain
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
//=================================================================================
//Free Functions
//=================================================================================
void system_exe(); //executes the game
void refresh_screen();
//---------------------------------------------------------------------------------
//=================================================================================
//End of Free Functions
//=================================================================================
///////////////////////////////////////////////////////////////////////////////////
#endif
///////////////////////////////////////////////////////////////////////////////////
