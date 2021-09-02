#pragma once
#ifndef __RUN_H__
#define __RUN_H__

#include "main.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER '\r'
#define BACK_SPACE 8
#define TAB 9
#define SPACE_BAR 32

typedef struct member {
	char ID[25];
	char PW[25];
	char name[20];
	char age[5];
	int score;
	int index;
}MEM;

// Ŀ�� ������
void cursor_view_f();
void cursor_view_t();

// ������ȭ�� �۵���
void run_preview_screen();

// ȸ������ �۵���
void run_sign_up_screen();

// ����ȭ�� �۵���
void run_starting_screen();

// ���ȭ�� �۵���
void run_mode_screen();

// 3x3 ���� �۵���
void run_real_game3();

// 4x4 ���� �۵���
void run_real_game4();
 
// 5x5 ���� �۵���
void run_real_game5();

// Ŀ�� ����
void cursor_view_f();

// Ŀ�� ����
void cursor_view_t();

#endif // !__RUN_H__
