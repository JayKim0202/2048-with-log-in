#ifndef __VERTICAL_BAR_H__
#define __VERTICAL_BAR_H__

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "game_over.h"
#include "frame.h"
#include "run.h"
#include "character_location.h"

typedef struct _data_of_column {
	int col_num;
	int col_location_x;
	int col_count;
	struct _data_of_column* next;
} data_of_col;

int move_vertical_bar();
int up_vertical_bar(int loc, int num);
int down_vertical_bar(int loc, int num);
int first_up_vertical_bar();
int first_down_vertical_bar(int up_column_num);
int score(int count);
data_of_col* memory_alloc();

#endif // !__VERTICAL_BAR_H__