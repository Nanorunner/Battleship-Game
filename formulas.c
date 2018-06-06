#include "formulas.h"





//description:  displays an initial program welcome message along with the rules of Battleship
//input: N/A
//output: option
void welcome_screen()
{
	printf("Welcome to Battleship");
	printf("1. This is a two player game.\n");
	printf("2. Player 1 is you and Player 2 is the computer.\n");
	printf("3. Players take turns firing a shot to attack enemy ships.\n");
	printf("4. On your turn, type in row and column to hit on your opponent's grid.\n");
	printf("5. The objective of the game is to hit and sink all of your opponent's ships.\n");
	printf("6. First player to do so wins.\n");
}

//description: sets each cell in a game board to ~
//input: game board, display boardfor ai player
//output: modified game board
void initialize_game_board(char gb[][10][10], char aiboard[][10])
{
	int row_index = 0, col_index = 0, tab_index = 0;
	for (tab_index = 0; tab_index < TABLES ; tab_index++)
	{
		for (row_index = 0; row_index < ROWS; ++row_index) // controls which row
		{
			for (col_index = 0; col_index < COLS; ++col_index) // controls which column
			{
				gb[tab_index][row_index][col_index] = '~';
			}
		}
	}
	for (row_index = 0; row_index < ROWS; ++row_index) // controls which row
	{
		for (col_index = 0; col_index < COLS; ++col_index) // controls which column
		{
			aiboard[row_index][col_index] = '~';
		}
	}
	
}

//description: determines if Player1 or Player2 goes first in the game
//input: N/A
//output: 0 or 1
Play select_who_starts_first()
{
	Play choice = PLAYERONE;
	choice = (Play)(rand() % 2);
	return choice;
}

//description: allows the user to place each of the 5 types of ships on his/her game board
//input: array
//output: array
void manually_place_ships_on_board(char gb[][10][10])
{
	bool placement_okay = false;
	int placement_row = 0, placement_col = 0;
	char placement_dir = '\0';


	//destroyer placement
	while (placement_okay != true)
	{
		printf("Please enter a row where you would like to place your destroyer from 0 to 9:\n");
		scanf(" %d", &placement_row);
		printf("Please enter a column where you would like to place your destroyer from 0 to 9:\n");
		scanf(" %d", &placement_col);
		printf("Would you like to have it positioned horizonatally or vertically (H/V)?\n");
		scanf(" %c", &placement_dir);
		if ((placement_dir == 'H') || (placement_dir == 'h'))
		{
			if (placement_col == 9)
			{
				printf("The piece will not fit on the game board. Please try again");
				placement_okay = false;
			}
			else
			{
				gb[0][placement_row][placement_col] = 'D';
				gb[0][placement_row][placement_col + 1] = 'D';
				placement_okay = true;
			}
		}
		if ((placement_dir == 'V') || (placement_dir == 'v'))
		{
			if (placement_row == 9)
			{
				printf("The piece will not fit on the game board. Please try again");
				placement_okay = false;
			}
			else
			{
				gb[0][placement_row][placement_col] = 'D';
				gb[0][placement_row + 1][placement_col] = 'D';
				placement_okay = true;
			}
		}
	}
	placement_okay = false;//need to rest the flag, applies for all others below this
	system("cls");

	//cruiser placement
	while (placement_okay != true)
	{
		printf("Please enter a row where you would like to place your cruiser from 0 to 9:\n");
		scanf(" %d", &placement_row);
		printf("Please enter a column where you would like to place your cruiser from 0 to 9:\n");
		scanf(" %d", &placement_col);
		printf("Would you like to have it positioned horizonatally or vertically (H/V)?\n");
		scanf(" %c", &placement_dir);
		if ((placement_dir == 'H') || (placement_dir == 'h'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row][placement_col + 1] == '~') && (gb[0][placement_row][placement_col + 2] == '~'))
			{
				if (placement_col > 7)
				{
					printf("The piece will not fit on the game board. Please try again.\n");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'C';
					gb[0][placement_row][placement_col + 1] = 'C';
					gb[0][placement_row][placement_col + 2] = 'C';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}

		if ((placement_dir == 'V') || (placement_dir == 'v'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row + 1][placement_col] == '~') && (gb[0][placement_row + 2][placement_col] == '~'))
			{
				if (placement_row > 7)
				{
					printf("The piece will not fit on the game board. Please try again");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'C';
					gb[0][placement_row + 1][placement_col] = 'C';
					gb[0][placement_row + 2][placement_col] = 'C';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}
	}
	placement_okay = false;
	system("cls");


	//submarine placement
	while (placement_okay != true)
	{
		printf("Please enter a row where you would like to place your submarine from 0 to 9:\n");
		scanf(" %d", &placement_row);
		printf("Please enter a column where you would like to place your submarine from 0 to 9:\n");
		scanf(" %d", &placement_col);
		printf("Would you like to have it positioned horizonatally or vertically (H/V)?\n");
		scanf(" %c", &placement_dir);
		if ((placement_dir == 'H') || (placement_dir == 'h'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row][placement_col + 1] == '~') && (gb[0][placement_row][placement_col + 2] == '~'))
			{
				if (placement_col > 7)
				{
					printf("The piece will not fit on the game board. Please try again.\n");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'S';
					gb[0][placement_row][placement_col + 1] = 'S';
					gb[0][placement_row][placement_col + 2] = 'S';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}

		if ((placement_dir == 'V') || (placement_dir == 'v'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row + 1][placement_col] == '~') && (gb[0][placement_row + 2][placement_col] == '~'))
			{
				if (placement_row > 7)
				{
					printf("The piece will not fit on the game board. Please try again");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'S';
					gb[0][placement_row + 1][placement_col] = 'S';
					gb[0][placement_row + 2][placement_col] = 'S';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}
	}
	placement_okay = false;
	system("cls");


	//battelship placement
	while (placement_okay != true)
	{
		printf("Please enter a row where you would like to place your battleship from 0 to 9:\n");
		scanf(" %d", &placement_row);
		printf("Please enter a column where you would like to place your battleship from 0 to 9:\n");
		scanf(" %d", &placement_col);
		printf("Would you like to have it positioned horizonatally or vertically (H/V)?\n");
		scanf(" %c", &placement_dir);
		if ((placement_dir == 'H') || (placement_dir == 'h'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row][placement_col + 1] == '~') && (gb[0][placement_row][placement_col + 2] == '~') && (gb[0][placement_row][placement_col + 3] == '~'))
			{
				if (placement_col > 6)
				{
					printf("The piece will not fit on the game board. Please try again.\n");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'B';
					gb[0][placement_row][placement_col + 1] = 'B';
					gb[0][placement_row][placement_col + 2] = 'B';
					gb[0][placement_row][placement_col + 3] = 'B';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}

		if ((placement_dir == 'V') || (placement_dir == 'v'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row + 1][placement_col] == '~') && (gb[0][placement_row + 2][placement_col] == '~') && (gb[0][placement_row + 3][placement_col] == '~'))
			{
				if (placement_row > 6)
				{
					printf("The piece will not fit on the game board. Please try again");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'B';
					gb[0][placement_row + 1][placement_col] = 'B';
					gb[0][placement_row + 2][placement_col] = 'B';
					gb[0][placement_row + 3][placement_col] = 'B';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}
	}
	placement_okay = false;
	system("cls");



	//aircraft carrier placement
	while (placement_okay != true)
	{
		printf("Please enter a row where you would like to place your aircraft carrier from 0 to 9:\n");
		scanf(" %d", &placement_row);
		printf("Please enter a column where you would like to place your aircraft carrier from 0 to 9:\n");
		scanf(" %d", &placement_col);
		printf("Would you like to have it positioned horizonatally or vertically (H/V)?\n");
		scanf(" %c", &placement_dir);
		if ((placement_dir == 'H') || (placement_dir == 'h'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row][placement_col + 1] == '~') && (gb[0][placement_row][placement_col + 2] == '~') && (gb[0][placement_row][placement_col + 3] == '~') && (gb[0][placement_row][placement_col + 4] == '~'))
			{
				if (placement_col > 5)
				{
					printf("The piece will not fit on the game board. Please try again.\n");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'A';
					gb[0][placement_row][placement_col + 1] = 'A';
					gb[0][placement_row][placement_col + 2] = 'A';
					gb[0][placement_row][placement_col + 3] = 'A';
					gb[0][placement_row][placement_col + 4] = 'A';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}

		if ((placement_dir == 'V') || (placement_dir == 'v'))
		{
			if ((gb[0][placement_row][placement_col] == '~') && (gb[0][placement_row + 1][placement_col] == '~') && (gb[0][placement_row + 2][placement_col] == '~') && (gb[0][placement_row + 3][placement_col] == '~') && (gb[0][placement_row + 4][placement_col] == '~'))
			{
				if (placement_row > 5)
				{
					printf("The piece will not fit on the game board. Please try again");
					placement_okay = false;
				}
				else
				{
					gb[0][placement_row][placement_col] = 'A';
					gb[0][placement_row + 1][placement_col] = 'A';
					gb[0][placement_row + 2][placement_col] = 'A';
					gb[0][placement_row + 3][placement_col] = 'A';
					gb[0][placement_row + 4][placement_col] = 'A';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}
	}
	system("cls");
}

//description: allows the user to randomly place each of the 5 types of ships on his/her game board
//input: array, player
//output: array
void randomly_place_ships_on_board(char gb[][10][10], Play player)
{
	Dir placement_dir = HOR;

	bool placement_okay = false;
	int placement_row = 0, placement_col = 0;


	//destroyer placement
	while (placement_okay != true)
	{
		placement_row = rand() % ROWS;
		placement_col = rand() % COLS;
		placement_dir = (Dir)(rand() % 2);
		if (placement_dir == HOR)
		{
			if (placement_col == 9)
			{
				placement_okay = false;
			}
			else
			{
				gb[player][placement_row][placement_col] = 'D';
				gb[player][placement_row][placement_col + 1] = 'D';
				placement_okay = true;
			}
		}
		else
		{
			if (placement_row == 9)
			{
				placement_okay = false;
			}
			else
			{
				gb[player][placement_row][placement_col] = 'D';
				gb[player][placement_row + 1][placement_col] = 'D';
				placement_okay = true;
			}
		}
	}
	placement_okay = false;//need to rest the flag, applies for all others below this
	system("cls");

	//cruiser placement
	while (placement_okay != true)
	{
		placement_row = rand() % ROWS;
		placement_col = rand() % COLS;
		placement_dir = (Dir)(rand() % 2);
		if (placement_dir == HOR)
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row][placement_col + 1] == '~') && (gb[player][placement_row][placement_col + 2] == '~'))
			{
				if (placement_col > 7)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'C';
					gb[player][placement_row][placement_col + 1] = 'C';
					gb[player][placement_row][placement_col + 2] = 'C';
					placement_okay = true;
				}
			}
			else
			{
				printf("There is already a ship there. Please try again.");
				placement_okay = false;
			}
		}

		else
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row + 1][placement_col] == '~') && (gb[player][placement_row + 2][placement_col] == '~'))
			{
				if (placement_row > 7)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'C';
					gb[player][placement_row + 1][placement_col] = 'C';
					gb[player][placement_row + 2][placement_col] = 'C';
					placement_okay = true;
				}
			}
			else
			{
				placement_okay = false;
			}
		}
	}
	placement_okay = false;
	system("cls");


	//submarine placement
	while (placement_okay != true)
	{
		placement_row = rand() % ROWS;
		placement_col = rand() % COLS;
		placement_dir = (Dir)(rand() % 2);
		if (placement_dir == HOR)
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row][placement_col + 1] == '~') && (gb[player][placement_row][placement_col + 2] == '~'))
			{
				if (placement_col > 7)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'S';
					gb[player][placement_row][placement_col + 1] = 'S';
					gb[player][placement_row][placement_col + 2] = 'S';
					placement_okay = true;
				}
			}
			else
			{
				placement_okay = false;
			}
		}

		else
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row + 1][placement_col] == '~') && (gb[player][placement_row + 2][placement_col] == '~'))
			{
				if (placement_row > 7)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'S';
					gb[player][placement_row + 1][placement_col] = 'S';
					gb[player][placement_row + 2][placement_col] = 'S';
					placement_okay = true;
				}
			}
			else
			{
				placement_okay = false;
			}
		}
	}
	placement_okay = false;
	system("cls");


	//battelship placement
	while (placement_okay != true)
	{
		placement_row = rand() % ROWS;
		placement_col = rand() % COLS;
		placement_dir = (Dir)(rand() % 2);
		if (placement_dir == HOR)
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row][placement_col + 1] == '~') && (gb[player][placement_row][placement_col + 2] == '~') && (gb[player][placement_row][placement_col + 3] == '~'))
			{
				if (placement_col > 6)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'B';
					gb[player][placement_row][placement_col + 1] = 'B';
					gb[player][placement_row][placement_col + 2] = 'B';
					gb[player][placement_row][placement_col + 3] = 'B';
					placement_okay = true;
				}
			}
			else
			{
				placement_okay = false;
			}
		}

		else
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row + 1][placement_col] == '~') && (gb[player][placement_row + 2][placement_col] == '~') && (gb[player][placement_row + 3][placement_col] == '~'))
			{
				if (placement_row > 6)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'B';
					gb[player][placement_row + 1][placement_col] = 'B';
					gb[player][placement_row + 2][placement_col] = 'B';
					gb[player][placement_row + 3][placement_col] = 'B';
					placement_okay = true;
				}
			}
			else
			{
				placement_okay = false;
			}
		}
	}
	placement_okay = false;
	system("cls");



	//aircraft carrier placement
	while (placement_okay != true)
	{
		placement_row = rand() % ROWS;
		placement_col = rand() % COLS;
		placement_dir = (Dir)(rand() % 2);
		if (placement_dir == HOR)
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row][placement_col + 1] == '~') && (gb[player][placement_row][placement_col + 2] == '~') && (gb[player][placement_row][placement_col + 3] == '~') && (gb[player][placement_row][placement_col + 4] == '~'))
			{
				if (placement_col > 5)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'A';
					gb[player][placement_row][placement_col + 1] = 'A';
					gb[player][placement_row][placement_col + 2] = 'A';
					gb[player][placement_row][placement_col + 3] = 'A';
					gb[player][placement_row][placement_col + 4] = 'A';
					placement_okay = true;
				}
			}
			else
			{
				placement_okay = false;
			}
		}

		else
		{
			if ((gb[player][placement_row][placement_col] == '~') && (gb[player][placement_row + 1][placement_col] == '~') && (gb[player][placement_row + 2][placement_col] == '~') && (gb[player][placement_row + 3][placement_col] == '~') && (gb[player][placement_row + 4][placement_col] == '~'))
			{
				if (placement_row > 5)
				{
					placement_okay = false;
				}
				else
				{
					gb[player][placement_row][placement_col] = 'A';
					gb[player][placement_row + 1][placement_col] = 'A';
					gb[player][placement_row + 2][placement_col] = 'A';
					gb[player][placement_row + 3][placement_col] = 'A';
					gb[player][placement_row + 4][placement_col] = 'A';
					placement_okay = true;
				}
			}
			else
			{
				placement_okay = false;
			}
		}
	}
	system("cls");
}

//description: determines if the shot taken was a hit or a miss
//input: array, rowcount, columncount, player, shiphit pointer
//output: TRUE or FALSE
bool check_shot(char gb[][10][10], int row, int column, Play player, Shstats *shiphit_ptr)
{
	bool check = false;
	if (gb[player][row][column] != '~')
	{
		shiphit_ptr->shiphit = gb[player][row][column];
		check = true;
	}
	else
	{
		check = false;
	}
	return check;
}

//description: determines if winner exists
//input: array, player
//output: TRUE or FALSE
bool is_winner(bool checkingarray[][6], Play player)
{
	bool is_winner = false;
	if ((checkingarray[player][DESTROYER] == true) && (checkingarray[player][CRUISER] == true) && (checkingarray[player][SUBMARINE] == true)
		&& (checkingarray[player][BATTLESHIP] == true) && (checkingarray[player][AIRCRAFTCARRIER] == true))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//description: updates the board every time a shot is taken. '*' indicates a hit and 'm' indicates a miss
//input: array, rowcount, columncount, hit or miss, display ai board, player
//output: array
void update_board(char gb[][10][10], char aiboard[][10], int row, int column, Play player, Hom hit_or_miss)
{
	if (hit_or_miss == HIT)
	{
		gb[player][row][column] = '*';
		if (player == PLAYERTWO)
		{
			aiboard[row][column] = '*';
		}
	}
	else
	{
		gb[player][row][column] = 'm';
		if (player == PLAYERTWO)
		{
			aiboard[row][column] = 'm';
		}
	}
	
}

//description: displays a board to the screen
//input:  array, display ai board
//output: N/A
void display_board(char gb[][10][10], char aiboard[][10])
{
	int row = 0, col = 0, table = 0;
	printf("Player 1:\n");

	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			printf(" %c", gb[table][row][col]);
		}
		printf("\n");
	}




	printf("Player 2:\n");
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			printf(" %c", aiboard[row][col]);
		}
		printf("\n");
	}

}

//description: writes the` position of the shot taken by the current player to the log file. It also writes whether or not it was a hit, miss, and if the ship was sunk.
//input: rowcount, columncount, hit or miss, playernum, sunk or not
//output: readout in log file
//void output_current_move(FILE *output, int row, int column, Hom hit_or_miss, int sunk_or_not)


//description: determines if a ship was sunk
//input: game boards, row, column, shiphit, player
//output: which ship if sunk
bool check_if_sunk_ship(char board[][10][10], int row, int col, char shiphit, Play player)
{
	int flag = 0;
	bool check = false;
		for (row = 0; row < ROWS; row++)
		{
			for (col = 0; col < COLS; col++)
			{
				if (board[player][row][col] == shiphit)
				{
					flag++;
				}
			}
		
	}
	if (flag == 0)
	{
		check = true;
	}
	return check;

}

//description: random shots
//input: N/A
//output: integer from one to nine
int rand_shot()
{
	int roc = 0;
	roc = rand() % 10;
	return roc;
}

//description: takes what ship was hit and returns an index to check by
//input: shiphit
//output: index
Issunkorhit indicies(char what_hit) 
{
	Issunkorhit shot = NONE;
	if (what_hit == '~')
	{
		shot = NONE;
	}
	else if (what_hit == 'D')
	{
		shot = DESTROYER;
	}
	else if (what_hit == 'C')
	{
		shot = CRUISER;
	}
	else if (what_hit == 'S')
	{
		shot = SUBMARINE;
	}
	else if (what_hit == 'B')
	{
		shot = BATTLESHIP;
	}
	else if (what_hit == 'A')
	{
		shot = AIRCRAFTCARRIER;
	}
	return shot;

}

//description: actual game logic
//input: N/A
//output: N/A
void runapp()
{
	srand((unsigned int)time(NULL));
	int which_player_is_going_first = 0, test = 0;
	char gamerino_boarderino[2][10][10] = { '\0' }, disp_ai_board[10][10] = { '\0' }, random_or_manual_placement = '\0', shiphit = '\0';
	bool checkerino_sinkerino[2][6] = { { false, false, false, false , false , false } , { false, false, false, false , false , false } }, win_decide = false;
	Play init_player = PLAYERONE, secon_player = PLAYERTWO;
	bool init_player_hom = false, secon_player_hom = false, check = false;
	Stats init_player_stats = { 0, 0, 0, 0.0 }, secon_player_stats = { 0, 0, 0, 0.0 };
	Shstats init_player_shot = { 0, 0 }, secon_player_shot = { 0, 0 };
	Issunkorhit init_shot = NONE, secon_shot = NONE;
	Hom init_shot_res = MISS, secon_shot_res = MISS;
	FILE *outfile = NULL;




	init_player = select_who_starts_first();
	if (init_player == PLAYERONE)
	{
		printf("You go first!\n");
		which_player_is_going_first = 1;//may or may not need
		secon_player = PLAYERTWO;
	}
	else if (init_player == PLAYERTWO)
	{
		printf("The computer goes first!\n");
		which_player_is_going_first = 2;//may or may not need
		secon_player = PLAYERONE;
	}

	initialize_game_board(gamerino_boarderino, disp_ai_board);
	//display_board(gamerino_boarderino);
	printf("Would you like to have your ships randomly placed (Y/N)?\n");
	scanf(" %c", &random_or_manual_placement);
	if ((random_or_manual_placement == 'Y') || (random_or_manual_placement == 'y'))
	{
		randomly_place_ships_on_board(gamerino_boarderino, PLAYERONE);
	}
	else if((random_or_manual_placement == 'N') || (random_or_manual_placement == 'n'))
	{
		manually_place_ships_on_board(gamerino_boarderino);
	}
	randomly_place_ships_on_board(gamerino_boarderino, PLAYERTWO);
	display_board(gamerino_boarderino, disp_ai_board);
	system("pause");
	system("cls");

	outfile = fopen("battleship.log", "w");
	while (win_decide != true)
	{
		//initial player
		if (win_decide != true)
		{
			if (init_player == PLAYERONE)
			{
				do
				{
					printf("Please enter a row that you would like to target:\n");
					scanf(" %d", &init_player_shot.row);
					printf("Please enter a column that you would like to target:\n");
					scanf(" %d", &init_player_shot.col);
					shiphit = gamerino_boarderino[secon_player][init_player_shot.row][init_player_shot.col];
					if ((shiphit != '*') && (shiphit != 'm'))
					{
						check = true;
					}
					else
					{
						printf("You already went there! Try again.\n");
						check = false;
					}
				} while (check != true);
			}
			else if (init_player == PLAYERTWO)
			{
				do
				{
					for (test = 0; test < 99999; test++);//yes this is nessecary
					init_player_shot.row = rand() % 10;
					init_player_shot.col = rand() % 10;
					shiphit = gamerino_boarderino[secon_player][init_player_shot.row][init_player_shot.col];
					if ((shiphit != '*') && (shiphit != 'm'))
					{
						check = true;
					}
					else
					{
						check = false;
					}
				} while (check != true);
			}
			check = false;
			init_shot = indicies(shiphit);


			if (init_shot == NONE)
			{
				init_shot_res = MISS;
				update_board(gamerino_boarderino, disp_ai_board, init_player_shot.row, init_player_shot.col, secon_player, init_shot_res);
				fprintf(outfile, "%d, %d was not a hit!\n", init_player_shot.row, init_player_shot.col);
				if (init_player == PLAYERTWO)
				{
					printf("%d, %d was not a hit!\n", init_player_shot.row, init_player_shot.col);
				}
				init_player_stats.num_misses++;
				init_player_stats.num_shots++;
				display_board(gamerino_boarderino, disp_ai_board);
			}
			//init_player_hom = check_shot(init_player_hom, init_player_shot.row, init_player_shot.col,secon_player, &init_player_shot.shiphit);
			else
			{
				init_shot_res = HIT;
				system("START https://niceme.me/");
				system("pause");
				system("START http://nicememe.website/");
				system("pause");
				system("START http://nicememewebsite.website/");
				system("pause");
				system("START http://nicememewebsitewebsite.website/");//low quality and low effort
				update_board(gamerino_boarderino, disp_ai_board, init_player_shot.row, init_player_shot.col, secon_player, init_shot_res);
				checkerino_sinkerino[init_player][init_shot] = check_if_sunk_ship(gamerino_boarderino, init_player_shot.row, init_player_shot.col, shiphit, secon_player);
				fprintf(outfile, "%d, %d is a hit!\n", init_player_shot.row, init_player_shot.col);
				if (init_player == PLAYERONE)
				{
					printf("%d, %d is a hit!\n", init_player_shot.row, init_player_shot.col);
				}
				init_player_stats.num_hits++;
				init_player_stats.num_shots++;
				display_board(gamerino_boarderino, disp_ai_board);
				if (checkerino_sinkerino[init_player][init_shot] == true)
				{
					if (shiphit == 'D')
					{
						if (init_player == PLAYERONE)
						{
							printf("Destroyer was sunk!\n");
						}
						fprintf(outfile, "Destroyer was sunk!\n");
					}
					else if (shiphit == 'C')
					{
						if (init_player == PLAYERONE)
						{
							printf("Cruiser was sunk!\n");
						}
						fprintf(outfile, "Cruiser was sunk!\n");
					}
					else if (shiphit == 'S')
					{
						if (init_player == PLAYERONE)
						{
							printf("Submarine was sunk!\n");
						}
						fprintf(outfile, "Submarine was sunk!\n");
					}
					else if (shiphit == 'B')
					{
						if (init_player == PLAYERONE)
						{
							printf("Battleship was sunk!\n");
						}
						fprintf(outfile, "Battleship was sunk!\n");
					}
					else if (shiphit == 'A')
					{
						if (init_player == PLAYERONE)
						{
							printf("Aircraft carrier was sunk!\n");
						}
						fprintf(outfile, "Aircraft carrier was sunk!\n");
					}
					system("pause");
					///////////////////////////////////
					win_decide = is_winner(checkerino_sinkerino, init_player);
					if (win_decide == true)
					{
						if (init_player == PLAYERONE)
						{
							printf("Player one has won!\n");
							fprintf(outfile, "Player one has won!\n");
						}
						else
						{
							printf("Player two has won!\n");
							fprintf(outfile, "Player two has won!\n");
						}
						system("pause");
					}
				}
			}
		}
		system("pause");
		system("cls");

		//system("cls");
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////hi////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//init_player_hom
		//second player
		if (win_decide != true)
		{
			if (secon_player == PLAYERONE)
			{
				do
				{
					printf("Please enter a row that you would like to target:\n");
					scanf("%d", &secon_player_shot.row);
					printf("Please enter a column that you would like to target:\n");
					scanf("%d", &secon_player_shot.col);
					shiphit = gamerino_boarderino[init_player][secon_player_shot.row][secon_player_shot.col];
					if ((shiphit != '*') && (shiphit != 'm'))
					{
						check = true;
					}
					else if (secon_player == PLAYERTWO)
					{
						printf("You already went there! Try again.\n");
						check = false;
					}
				} while (check != true);
			}
			else if (secon_player == PLAYERTWO)
			{
				do
				{
					for (test = 0; test< 99999; test++)//yes this is nessecary
					init_player_shot.row = rand() % 10;
					init_player_shot.col = rand() % 10;
					shiphit = gamerino_boarderino[init_player][secon_player_shot.row][secon_player_shot.col];//something wrong, keeps looping, something to do with the random function
					if ((shiphit != '*') && (shiphit != 'm'))
					{
						check = true;
					}
					else
					{
						check = false;
					}
				} while (check != true);
			}
				check = false;
				
				secon_shot = indicies(shiphit);

				if (secon_shot == NONE)
				{
					secon_shot_res = MISS;
					update_board(gamerino_boarderino, disp_ai_board, secon_player_shot.row, secon_player_shot.col, init_player, secon_shot_res);
					fprintf(outfile, "%d, %d was not a hit!\n", secon_player_shot.row, secon_player_shot.col);
					if (secon_player == PLAYERONE)
					{
						printf("%d, %d was not a hit!\n", secon_player_shot.row, secon_player_shot.col);
					}
					secon_player_stats.num_misses++;
					secon_player_stats.num_shots++;
					display_board(gamerino_boarderino, disp_ai_board);
				}
				//init_player_hom = check_shot(init_player_hom, init_player_shot.row, init_player_shot.col,secon_player, &init_player_shot.shiphit);
				else
				{
					system("START https://niceme.me/");
					system("pause");
					system("START http://nicememe.website/");
					system("pause");
					system("START http://nicememewebsite.website/");
					system("pause");
					system("START http://nicememewebsitewebsite.website/");//low quality and low effort
					secon_shot_res = HIT;
					update_board(gamerino_boarderino, disp_ai_board, secon_player_shot.row, secon_player_shot.col, init_player, secon_shot_res);
					checkerino_sinkerino[secon_player][secon_shot] = check_if_sunk_ship(gamerino_boarderino, secon_player_shot.row, secon_player_shot.col, shiphit, init_player);
					fprintf(outfile, "%d, %d is a hit!\n", secon_player_shot.row, secon_player_shot.col);
					if (secon_player == PLAYERONE)
					{
						printf("%d, %d was a hit!\n", secon_player_shot.row, secon_player_shot.col);
					}
					secon_player_stats.num_misses++;
					secon_player_stats.num_shots++;
					display_board(gamerino_boarderino, disp_ai_board);
					if (checkerino_sinkerino[secon_player][secon_shot] == true)
					{
						if (shiphit == 'D')
						{
							if (secon_player == PLAYERONE)
							{
								printf("Destroyer was sunk!\n");
							}
							fprintf(outfile, "Destroyer was sunk!\n");
						}
						else if (shiphit == 'C')
						{
							if (secon_player == PLAYERONE)
							{
								printf("Cruiser was sunk!\n");
							}
							fprintf(outfile, "Cruiser was sunk!\n");
						}
						else if (shiphit == 'S')
						{
							if (secon_player == PLAYERONE)
							{
								printf("Submarine was sunk!\n");
							}
							fprintf(outfile, "Submarine was sunk!\n");
						}
						else if (shiphit == 'B')
						{
							if (secon_player == PLAYERONE)
							{
								printf("Battleship was sunk!\n");
							}
							fprintf(outfile, "Battleship was sunk!\n");
						}
						else if (shiphit == 'A')
						{
							if (secon_player == PLAYERONE)
							{
								printf("Aircraft carrier was sunk!\n");
							}
							fprintf(outfile, "Aircraft carrier was sunk!\n");
						}

						///////////////////////////////////
						win_decide = is_winner(checkerino_sinkerino, secon_player);
						if (win_decide == true)
						{
							if (secon_player == PLAYERONE)
							{
								printf("Player one has won!\n");
								fprintf(outfile, "Player one has won!\n");
							}
							else
							{
								printf("Player two has won!\n");
								fprintf(outfile, "Player two has won!\n");
							}
							system("pause");
						}
					}
				}
			}
			system("pause");
			system("cls");
		}
		init_player_stats.hit_miss_ratio = (double)((init_player_stats.num_hits / init_player_stats.num_misses));
		secon_player_stats.hit_miss_ratio = (double)((secon_player_stats.num_hits / secon_player_stats.num_misses));
		if (init_player == PLAYERONE)
		{
			fprintf(outfile, "Player one had a hit/miss ratio of %.2lf, and player two had a hit/miss ratio of %.2lf.\n", init_player_stats.hit_miss_ratio, secon_player_stats.hit_miss_ratio);
		}
		else
		{
			fprintf(outfile, "Player two had a hit/miss ratio of %.2lf, and player one had a hit/miss ratio of %.2lf.\n", init_player_stats.hit_miss_ratio, secon_player_stats.hit_miss_ratio);
		}
		fclose(outfile);
	}
	
