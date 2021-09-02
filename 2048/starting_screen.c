#include "starting_screen.h"

void starting_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);

	// ■ □ → ← ↑ ↓
	// ─ │ ┌ ┐ ┘ └

	for (int i = 0; i < 24; i++)
		printf("□");
	printf("\n");
	printf("□□■■■□□□■■□□■□□□□□■■■□□□\n");
	printf("□□□□□■□■□□■□■□□□□■□□□■□□\n");
	printf("□□□□■□□■□□■□■□■□□□■■■□□□\n");
	printf("□□□■□□□■□□■□■■■■□■□□□■□□\n");
	printf("□□■■■■□□■■□□□□■□□□■■■□□□\n");
	for (int i = 0; i < 24; i++)
		printf("□");

	coord.X = 2;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("→ ← ↑ ↓ : MOVE");

	coord.X = 10;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("ESC : QUIT");

	coord.X = 6;
	coord.Y = 12;
	SetConsoleCursorPosition(handle, coord);
	printf("p or P : PAUSE");

	coord.X = 9;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("ENTER : RUN");

	coord.X = 37;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("START");

	coord.X = 37;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("RULES");

	coord.X = 37;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("RANK");
}

void starting_screen_rudder()
{
	int kb_input;
	int box_location[3] = { 8, 10, 12 };
	int location_count = 0;

	starting_screen();
	point_thing(box_location[location_count]);

	while (1)
	{
		kb_input = _getch();
		if (kb_input == ESC)
			exit(0);
		else if (kb_input == ENTER)
		{
			switch (location_count)
			{
			case 0:
				choose_option();
				system("cls");
				starting_screen();
				point_thing(box_location[location_count]);
				break;
			case 1:
				rule();
				system("cls");
				starting_screen();
				point_thing(box_location[location_count]);
				break;
			case 2:
				// 랭크 함수를 넣음
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
		case UP:
			if (location_count == 0)break;
			system("cls");
			starting_screen();
			point_thing(box_location[--location_count]); 
			break;
		case DOWN:
			if (location_count == 2)break;
			system("cls");
			starting_screen();
			point_thing(box_location[++location_count]);
			break;
		}
	}
}

void point_thing(int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 34;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
	printf("┌────────┐");
	coord.X = 34;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = 43;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = 34;
	coord.Y = y + 2;
	SetConsoleCursorPosition(handle, coord);
	printf("└────────┘");
}