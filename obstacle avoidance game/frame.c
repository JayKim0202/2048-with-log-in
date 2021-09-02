#include "frame.h"

// 기본 게임 틀
int frame()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 30; i++)
		printf("■");
	for (int i = 0; i < 12; i++)
		printf("\n");
	for (int i = 0; i < 30; i++)
		printf("■");
}