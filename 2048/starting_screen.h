#ifndef __STARTING_SCREEN_H__
#define __STARTING_SCREEN_H__

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER '\r'

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "rule.h"

void option_screen();
void starting_screen();
void point_thing(int y);
void starting_screen_rudder();

#endif // !__STARTING_SCREEN_H__
