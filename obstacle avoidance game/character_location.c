#include "character_location.h"

// 처음 플레이어의 위치
int char_location()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD player_location;

	player_location.X = 0;
	player_location.Y = 6;
	SetConsoleCursorPosition(handle, player_location);

	printf("●");
}

int rudder_control(int rudder_loc, int player_loc)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD player_location;

	int temp = player_loc;

	// system("cls");
	// frame();

	switch (rudder_loc)
	{
	// up
	case 80:
		temp++;
		break;
	// down
	case 72:
		temp--;
		break;
	// right
	case 77:
		break;
	}
	
	if (temp < 1 || temp > 11)
	{
		// player_location.X = 0;
		// player_location.Y = player_loc;
		// SetConsoleCursorPosition(handle, player_location);
		// printf("●");
		return player_loc;
	}+

	player_location.X = 0;
	player_location.Y = player_loc;
	SetConsoleCursorPosition(handle, player_location);
	printf("  ");
	player_location.X = 0;
	player_location.Y = temp;
	SetConsoleCursorPosition(handle, player_location);
	printf("●");

	return temp;
}

int current_palyer_location(int player_loc)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD player_location;

	player_location.X = 0;
	player_location.Y = player_loc;
	SetConsoleCursorPosition(handle, player_location);
	printf("●");
}