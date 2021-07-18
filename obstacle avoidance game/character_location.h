#ifndef __CHARACTER_LOCATION_H__
#define __CHARACTER_LOCATION_H__

#include <stdio.h>
#include <Windows.h>
#include "frame.h"
#include "vertical_bar.h"


#define RIGHT 77
#define UP 80
#define DOWN 72

int char_location();
int rudder_control(int rudder_loc, int player_loc);
int current_palyer_location(int player_loc);

#endif // !__CHARACTER_LOCATION_H__