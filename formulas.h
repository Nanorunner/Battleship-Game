#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define TABLES 2
#define DESTROYERLENGTH 2
#define CRUISERLENGTH 3
#define SUBMARINELENGTH 3
#define BATTLESHIPLENGTH 4
#define AIRCRAFTCARRIERLENGTH 5

typedef enum menuoptions
{
	RULES = 1, PLAY, EXIT
}Menuoptions;

typedef enum direction
{
	HOR, VER
} Dir;


typedef enum player
{
	PLAYERONE, PLAYERTWO
} Play;

typedef enum hitormiss
{
	MISS, HIT
}Hom;

typedef enum shipsunkorhit
{
	DESTROYER, CRUISER, SUBMARINE, BATTLESHIP, AIRCRAFTCARRIER, NONE
}Issunkorhit;



/* for main :
Stats p1_stats = {0, 0, 0, 0.0}*/
typedef struct stats//aggregate type, going to see other types of fields
{
	int num_hits;
	int num_misses;
	int num_shots;
	double hit_miss_ratio;
}Stats;

typedef struct shotstats
{
	int row;
	int col;
	char shiphit;

}Shstats;




//description:  displays an initial program welcome message along with the rules of Battleship
//input: N/A
//output: option
void welcome_screen();

//description: sets each cell in a game board to ~
//input: game board, display boardfor ai player
//output: modified game board
void initialize_game_board(char gb[][10][10], char aiboard[][10]);

//description: determines if Player1 or Player2 goes first in the game
//input: N/A
//output: 1 or 2
Play select_who_starts_first();

//description: allows the user to place each of the 5 types of ships on his/her game board
//input: array
//output: array
void manually_place_ships_on_board(char gb[][10][10]);

//description: allows the user to randomly place each of the 5 types of ships on his/her game board
//input: array, player
//output: array
void randomly_place_ships_on_board(char gb[][10][10], Play player);

//description: determines if the shot taken was a hit or a miss
//input: array, rowcount, columncount, player, shiphit pointer
//output: TRUE or FALSE
bool check_shot(char gb[][10][10], int row, int column, Play player, Shstats *shiphit_ptr);

//description: determines if winner exists
//input: array, player
//output: TRUE or FALSE
bool is_winner(bool checkingarray[][6], Play player);

//description: updates the board every time a shot is taken. '*' indicates a hit and 'm' indicates a miss
//input: array, rowcount, columncount, hit or miss, display ai board, player
//output: array
void update_board(char gb[][10][10], char aiboard[][10], int row, int column, Play player, Hom hit_or_miss);

//description: displays a board to the screen
//input:  array, display ai board
//output: N/A
void display_board(char gb[][10][10], char aiboard[][10]);

//description: writes the` position of the shot taken by the current player to the log file. It also writes whether or not it was a hit, miss, and if the ship was sunk.
//input: rowcount, columncount, hit or miss, playernum, sunk or not
//output: readout in log file
//void output_current_move(FILE *output, int row, int column, Hom hit_or_miss, int sunk_or_not);

//description: determines if a ship was sunk
//input: game boards, row, column, shiphit, player
//output: which ship if sunk
bool check_if_sunk_ship(char board[][10][10], int row, int col, char shiphit, Play player);

//description: random shots
//input: N/A
//output: integer from one to nine
int rand_shot();

//description: takes what ship was hit and returns an index to check by
//input: shiphit
//output: index
Issunkorhit indicies(char what_hit);

//description: actual game logic
//input: N/A
//output: N/A
void runapp();







//for copypaste


//description: 
//input: 
//output: 






//void update_stats(Stats *p_stats_ptr, Hom hits)
//{
//	if (hits)
//	{
//		(*p_stats_ptr).num_hits += 1;//one way
//	}
//	else
//	{
//		p_stats_ptr->num_misses += 1;//points at, instead of needing the asterix
//	}
//	p_stats.num_shots++;
//}

//printf ("%d", p1stats.numshots)