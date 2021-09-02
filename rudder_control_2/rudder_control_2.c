#include <stdio.h>
#include <Windows.h>
#define LEFT 75
#define RIGHT 77
#define UP 80
#define DOWN 72

typedef struct palyer_coord
{
	int x;
	int y;
}pc;

int background();
pc rudder_control(pc current_location);

int main()
{
	pc player;
	player.x = 2;
	player.y = 1;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	while (1)
	{
		system("cls");
		background();
		player = rudder_control(player);

		if (player.x == 1 || player.y == 0 || player.x == 33 || player.y == 18)
		{
			system("cls");
			background();
			coord.X = 15;
			coord.Y = 8;
			SetConsoleCursorPosition(handle, coord);
			printf("finish");
			coord.Y = 20;
			SetConsoleCursorPosition(handle, coord);
			exit(0);
		}
	}

	return 0;
}

int background()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	for (int i = 0; i < 18; i++)
		printf("бс");
	printf("\n");
	for (int i = 0; i < 17; i++)
		printf("бс\n");
	for (int i = 0; i < 18; i++)
		printf("бс");

	coord.X = 34;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 17; i++)
	{
		printf("бс");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}
	printf("\n\n");
}

pc rudder_control(pc current_location)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD temp_location;

	char temp, rudder;

	temp_location.X = current_location.x;
	temp_location.Y = current_location.y;
	SetConsoleCursorPosition(handle, temp_location);
	printf("б▄");

	temp = getch();
	rudder = getch();

	switch (rudder)
	{
	case LEFT:
		current_location.x--;
		break;
	case RIGHT:
		current_location.x++;
		break;
	case UP:
		current_location.y++;
		break;
	case DOWN:
		current_location.y--;
		break;
	default:
		return current_location;
	}

	return current_location;
}
