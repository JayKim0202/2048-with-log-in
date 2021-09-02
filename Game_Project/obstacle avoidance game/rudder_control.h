#ifndef __RUDDER_CONTROL_H__
#define __RUDDER_CONTROL_H__
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
// ����Ű �ƽ�Ű�ڵ�
#define LEFT 75
#define RIGHT 77
#define UP 80
#define DOWN 72

// ĳ���� ��ǥ ����ü
typedef struct character_coordinate {
	int x;
	int y;
}char_coord;

// ��ǥ ���� �Լ� ����
char_coord rudder_control(char_coord cc);

#endif