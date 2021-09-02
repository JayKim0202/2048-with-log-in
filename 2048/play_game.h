#ifndef __PLAY_GAME_H__
#define __PALY_GAME_H__

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER '\r'

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "_3X3.h"

void choose_option();
void _3X3();
void _4X4();
void _5X5();
void square(int x);

#endif // !__PLAY_GAME_H__
