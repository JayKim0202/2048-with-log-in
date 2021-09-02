#include "_3X3.h"

void _3X3_play()
{

}
void create_num()
{

}
void check_num_location()
{

}
void is_same_num()
{

}
void create_frame()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 5;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	printf("2048");

	for (int i = 3; i <= 13; i += 4)
	{
		for (int j = 3; j <= 17; j += 7)
		{
			coord.X = j;
			coord.Y = i;
			SetConsoleCursorPosition(handle, coord);
			printf("忙式式式忖");
			coord.X = j;
			coord.Y = i + 1;
			SetConsoleCursorPosition(handle, coord);
			printf("弛");
			coord.X = j + 4;
			coord.Y = i + 1;
			SetConsoleCursorPosition(handle, coord);
			printf("弛");
			coord.X = j;
			coord.Y = i + 2;
			SetConsoleCursorPosition(handle, coord);
			printf("戌式式式戎");
		}
	}

	coord.X = 26;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("⊥ ∠ ∟ ⊿ : MOVE");

	coord.X = 26;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("ESC : QUIT");

	coord.X = 26;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("p or P : PAUSE"); 

	coord.X = 26;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("ENTER : PLAY");
}