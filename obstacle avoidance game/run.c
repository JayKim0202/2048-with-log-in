#include "run.h"

int run()
{

	cursor_view();
	frame();
	char_location();

	move_vertical_bar();
	//input();
}

int input()
{
	int rudder_input;	// ����Ű �޴� ����
	int r_temp;	// �ʿ���� ����Ű �޴� ����
	static int player_loc = 6;


	

/*
	r_temp = _getch();
	rudder_input = _getch();

	if (rudder_input == 80 || rudder_input == 72 || rudder_input == 77)
		player_loc = rudder_control(rudder_input, player_loc);
	else
		return;*/
 
	clock_t new_time, old_time;
	old_time = clock();
	do {
		new_time = clock();
		if (difftime(new_time, old_time) > 100) return;
	} while (!_kbhit());

	if ((rudder_input = _getch()) == 80 || rudder_input == 72)
	{
		player_loc = rudder_control(rudder_input, player_loc);
		return player_loc;
	}
	else
		return;


	/*while (1)
	{
		r_temp = _getch();
		rudder_input = _getch();

		if (rudder_input == 80 || rudder_input == 72)
			player_loc = rudder_control(rudder_input, player_loc);
		else
			continue;
	}*/
}

int cursor_view()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}