#include "vertical_bar.h"

int move_vertical_bar()
{
	data_of_col* doc_head;
	data_of_col* doc_tail;
	data_of_col* doc_temp;
	doc_head = memory_alloc();
	doc_tail = doc_head;
	doc_temp = doc_head;
	int count = 0;
	int player_loc = 6, temp;

	while (1)
	{
		doc_tail->next = memory_alloc();
		doc_tail->col_num = first_up_vertical_bar();
		doc_tail->col_location_x = 58;
		doc_tail->col_count = count;	// count가 20이면 win
		doc_tail = doc_tail->next;
		for (int i = 0; i < 14; i++)
		{
			temp = input();
			Sleep(30);
			system("cls");
			if (temp < 14)
				player_loc = temp;
			current_palyer_location(player_loc);
			frame();
			score(doc_temp->col_count);
			// 여기에 스코어 함수 넣어줌

			doc_temp->col_location_x--;
			up_vertical_bar(doc_temp->col_location_x, doc_temp->col_num);
			down_vertical_bar(doc_temp->col_location_x, 8 - doc_temp->col_num);

			// 기둥에 부딪치면 죽음
			if ((player_loc <= doc_temp->col_num || player_loc >= doc_temp->col_num + 4) && doc_temp->col_location_x == 1)
				game_over(doc_temp->col_count);

			if (doc_temp->next->col_location_x != 0)
			{
				doc_temp->next->col_location_x--;
				up_vertical_bar(doc_temp->next->col_location_x, doc_temp->next->col_num);
				down_vertical_bar(doc_temp->next->col_location_x, 8 - doc_temp->next->col_num);
				if (doc_temp->next->next->col_location_x != 0)
				{
					doc_temp->next->next->col_location_x--;
					up_vertical_bar(doc_temp->next->next->col_location_x, doc_temp->next->next->col_num);
					down_vertical_bar(doc_temp->next->next->col_location_x, 8 - doc_temp->next->next->col_num);
					if (doc_temp->next->next->next->col_location_x != 0)
					{
						doc_temp->next->next->next->col_location_x--;
						up_vertical_bar(doc_temp->next->next->next->col_location_x, doc_temp->next->next->next->col_num);
						down_vertical_bar(doc_temp->next->next->next->col_location_x, 8 - doc_temp->next->next->next->col_num);
						if (doc_temp->next->next->next->next->col_location_x != 0)
						{
							doc_temp->next->next->next->next->col_location_x--;
							up_vertical_bar(doc_temp->next->next->next->next->col_location_x, doc_temp->next->next->next->next->col_num);
							down_vertical_bar(doc_temp->next->next->next->next->col_location_x, 8 - doc_temp->next->next->next->next->col_num);
						}
					}
				}
			}
			if (doc_temp->col_location_x <= 0)
				doc_temp = doc_temp->next;
		}
		count++;
		if (doc_temp->col_count> 19)
		{
			win(doc_temp->col_count);
			exit(0);
		}
	}
}

int score(int count)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	
	pos.X = 0;
	pos.Y = 16;
	SetConsoleCursorPosition(handle, pos);
	printf("socre : %d", count);


}

// 가장 뒤에 오는 기둥 생성
int first_up_vertical_bar()
{
	int column_num;

	srand((unsigned)time(NULL));

	column_num = rand() % 5 + 1;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD col_loc;

	col_loc.X = 58;
	col_loc.Y = 1;
	SetConsoleCursorPosition(handle, col_loc);
	for (int i = 0; i < column_num; i++)
	{
		printf("■");
		col_loc.Y++;
		SetConsoleCursorPosition(handle, col_loc);
	}

	first_down_vertical_bar(column_num);

	return column_num;
}

int up_vertical_bar(int loc, int num)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD col_loc;

	col_loc.X = loc;
	col_loc.Y = 1;
	SetConsoleCursorPosition(handle, col_loc);
	for (int i = 0; i < num; i++)
	{
		printf("■");
		col_loc.Y++;
		SetConsoleCursorPosition(handle, col_loc);
	}
}

// 가장 뒤에 오는 기둥 생성
int first_down_vertical_bar(int up_column_num)
{
	int column_num = 8 - up_column_num;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD col_loc;

	col_loc.X = 58;
	col_loc.Y = 11;
	SetConsoleCursorPosition(handle, col_loc);
	for (int i = 0; i < column_num; i++)
	{
		printf("■");
		col_loc.Y--;
		SetConsoleCursorPosition(handle, col_loc);
	}
}

int down_vertical_bar(int loc, int num)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD col_loc;

	col_loc.X = loc;
	col_loc.Y = 11;
	SetConsoleCursorPosition(handle, col_loc);
	for (int i = 0; i < num; i++)
	{
		printf("■");
		col_loc.Y--;
		SetConsoleCursorPosition(handle, col_loc);
	}
}

data_of_col* memory_alloc()
{
	data_of_col* temp;
	temp = malloc(sizeof(data_of_col));

	temp->col_location_x = 0;
	temp->col_num = 0;
	temp->col_count = 0;
	temp->next = NULL;
	return temp;
}