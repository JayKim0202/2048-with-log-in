#ifndef __RUDDER_CONTROL_H__
#define __RUDDER_CONTROL_H__
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
// 방향키 아스키코드
#define LEFT 75
#define RIGHT 77
#define UP 80
#define DOWN 72

// 캐릭터 좌표 구조체
typedef struct character_coordinate {
	int x;
	int y;
}char_coord;

// 좌표 변경 함수 선언
char_coord rudder_control(char_coord cc);

#endif