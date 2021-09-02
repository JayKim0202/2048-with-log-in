#include "rule.h"

void rule()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
	}

	coord.X = 0;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 38;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 0;
	coord.Y = 21;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
	}

	coord.X = 3;
	coord.Y = 2;
	SetConsoleCursorPosition(handle, coord);
	printf("시작 시 2개의 2(또는 4)가 나타난다.");

	coord.X = 3;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("키보드의 방향키를 누르면 블록이");

	coord.X = 3;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("전부 그 방향으로 이동하면서 같은");

	coord.X = 3;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("숫자가 있을 경우 합쳐지며, 빈자리");

	coord.X = 3;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("중 한 칸에 램덤하게 2 또는 4가 나");

	coord.X = 3;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("온다. 이를 반복해서 2로부터 2048을");

	coord.X = 3;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("만들면 게임 CLEAR");

	coord.X = 3;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("2048을 만들기 전 16칸이 꽉 차있");

	coord.X = 3;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("으면서 인접한 두 칸이 같이 않을 때,");

	coord.X = 3;
	coord.Y = 12;
	SetConsoleCursorPosition(handle, coord);
	printf("GAME OVER");

	// 출처 위키피디아

	_getch();
}