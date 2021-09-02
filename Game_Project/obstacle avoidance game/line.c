#include "line.h"

// 시작 라인을 그리는 함수
int start_line()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 1;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 15; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	return 0;
}

// 끝 라인을 그리는 함수
int finish_line()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 80;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 15; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	return 0;
}