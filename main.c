#include "formulas.h"

int main(void)
{
	
	char gamerino_boarderino[2][10][10] = { '\0' };
	bool checkerino_sinkerino[2][5] = { false };
	Menuoptions option = 0;
	srand((unsigned int)time(NULL));
	//system("START https://niceme.me/"); low quality memes
	/*system("START https://niceme.me/");
	system("START https://niceme.me/");
	system("START https://niceme.me/");
	system("START https://niceme.me/");
	system("START https://niceme.me/");
	system("START https://niceme.me/");
	system("START https://niceme.me/");
	system("START https://niceme.me/");*/
	do
	{
		printf("Welcome to Battleship\n");
		printf("1. Print game rules\n");
		printf("2. Play game\n");
		printf("3. Exit game\n");
		scanf("%d", &option);
		system("cls");
		if (option == RULES)
		{
			welcome_screen();
			system("pause");
			system("cls");
		}
		else if (option == PLAY)
		{
			welcome_screen();
			system("pause");
			system("cls");
			runapp();
		}
		else if (option == EXIT)
		{
			printf("Exiting. Please press return again.\n");
			exit(0);
		}
		else if ((option < 1) || (option > 3))
		{
			printf("Not a valid option. Try again.\n");
			system("pause");
			system("cls");
		}
	} while (option < 1 || option > 3);

	option = 0;
	system("cls");
}






