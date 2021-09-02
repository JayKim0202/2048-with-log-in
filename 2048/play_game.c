#include "play_game.h"

void option_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 4;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("3 X 3");

	coord.X = 14;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("4 X 4");

	coord.X = 24;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("5 X 5");

	coord.X = 40;
	coord.Y = 2;
	SetConsoleCursorPosition(handle, coord);
	printf("→ ← ↑ ↓ : MOVE");

	coord.X = 40;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("ESC : QUIT");

	coord.X = 40;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("p or P : PAUSE");

	coord.X = 40;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("ENTER : PLAY");
}


void choose_option()
{
	int box_location[3] = { 2, 12, 22 };
	int kb_input;
	int location_count = 0;

	option_screen();
	square(box_location[location_count]);


	while (1)
	{
		kb_input = _getch();
		if (kb_input == ESC)
			return;
		else if (kb_input == ENTER)
		{
			switch (location_count)
			{
			case 0:
				// 아직 구현 안함
				create_frame();
				break;
			case 1:
				// 아직 구현 안함
				//_4X4();
				break;
			case 2:
				// 아직 구현 안함
				//_5X5();
				break;
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();

		switch (kb_input)
		{
		case LEFT:
			if (location_count == 0) break;
			system("cls");
			option_screen();
			square(box_location[--location_count]);
			break;
		case RIGHT:
			if (location_count == 2) break;
			system("cls");
			option_screen();
			square(box_location[++location_count]);
			break;
		}
	}
}

void square(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("┌──────┐");

	coord.X = x;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x + 7;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("└──────┘");
}