#include "game_over.h"

int win(int score)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	system("cls");

	pos.X = 22;
	pos.Y = 6;
	SetConsoleCursorPosition(handle, pos);
	printf("your win!!");
	pos.Y++;
	SetConsoleCursorPosition(handle, pos);
	printf("score : %d", score);

	pos.Y = 10;
	SetConsoleCursorPosition(handle, pos);
}

int game_over(int score)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	system("cls");

	pos.X = 22;
	pos.Y = 6;
	SetConsoleCursorPosition(handle, pos);
	printf("your lose!!");
	pos.Y++;
	SetConsoleCursorPosition(handle, pos);
	printf("score : %d", score);

	pos.Y = 10;
	SetConsoleCursorPosition(handle, pos);

	exit(0);
}