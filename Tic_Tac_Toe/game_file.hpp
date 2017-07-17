#ifndef  GAME_FILE_HPP
#define GAME_FILE_HPP

#include <iostream>
#include<string>
#include<vector>

class player
{
private:
	std::string player_name;
	char player_icon;
	int win_count;
public:
	//Constructors
	player();
	player(std::string, char);
	//Mutators
	void add_win() { this->win_count = win_count + 1; }
	//ACCESSORS
	void name_output();
	void icon_output();
	void win_count_output();
	char return_user_icon();
	//OPERATOR OVERLOADING
	void swap(player &);
	void operator=(player);
};

class board
{
private:
	char board_boxes[10];
public:
	board();
	void create_box(player &, const int);
	void board_generation(player & player_1, player & player_2);
	void board_reset();
};

class game
{
private:
	player player_1;
	player player_2;
	std::vector<int> player_1_moves;
	std::vector<int> player_2_moves;
	int current_move;
	std::vector<int> completed_moves;
	board game_board;
	bool game_complete;
	bool player_1_turn;
public:
	game();
	void run_game();
	void reset();
	void check_game(); //After every move, the game will check to see if the game has been completed. It will also assign the next player to go.
	void player_move(); //Player move will be made after every check, they will type a number in from 1 to 9 to choose their space.
	void play(); //Play run's the game each frame, and runs in the run_game file;
	void board_refresh();
	bool box_check(const int &);
	void new_game(); //At completion of the game, the player will be asked if they want to start a new game.
};

const int winning_combos[8][3] =
{
	{ 1,2,3 }, //0
	{ 4,5,6 }, //1
	{ 7,8,9 }, //2
	{ 1,4,7 }, //3
	{ 2,5,8 }, //4
	{ 3,6,9 }, //5
	{ 1,5,9 }, //6
	{ 7,5,3 } //7
};

#endif
