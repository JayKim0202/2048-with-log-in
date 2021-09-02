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

// 커서 깜빡임
void cursor_view_f();
void cursor_view_t();

// 프리뷰화면 작동부
void run_preview_screen();

// 회원가입 작동부
void run_sign_up_screen();

// 시작화면 작동부
void run_starting_screen();

// 모드화면 작동부
void run_mode_screen();

// 3x3 게임 작동부
void run_real_game3();

// 4x4 게임 작동부
void run_real_game4();
 
// 5x5 게임 작동부
void run_real_game5();

// 커서 숨김
void cursor_view_f();

// 커서 보임
void cursor_view_t();

#endif // !__RUN_H__
