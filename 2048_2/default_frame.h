#pragma once
#ifndef __DEFAULT_FRAME_H__
#define __DEFAULT_FRAME_H__

#include "main.h"

// 회원가입, 로그인 시작화면
void preview_screen();
// 회원가입, 로그인 시작화면에서 사용되는 네모칸
void preview_box(int y, int x_size);
// 회원가입
void sign_up_screen();
// 회원가입 ID, PW, name, age 네모칸
// log in에서도 사용
void sign_up_box(int x, int y, int x_size);
// 로그인
void log_in_screen();
// 아이디 찾기
void find_ID();
// 비밀번호 찾기
void find_PW();
// 글씨 써지는 함수
void text_output(char c, int x, int y);
// 커서 고정
void fix_cursor(int x, int y);
// 네모 삭제
void dele_box(int x, int y, int x_size);
// 빈칸 안내 표시
void print_empty(char id, char pw, char name, char age);
// 문장 쓰는 함수
void string_output(char s[], int x, int y);
// 나이가 숫자가 아닐 경우
void is_no_digit();
// 아이디가 겹칠 경우
void id_overlap_screen();
// 회원가입 완료 창
void done_sign_up();




// 시작화면
void starting_screen();
// 3x3, 4x4, 5x5 중 선택하는 화면
void mode_screen();
// 게임의 기본 틀
// x, y : 가장 끝상자의 좌표
// other : 조작키의  x좌표
void play_screen(int x, int y, int other, int score);
// starting_screen에서 사용되는 네모칸
void vertical_selection_box(int y);
// starting_screen에서 사용되는 네모칸
void horizon_selection_box(int x);
// 게임 설명
void rule();
// 게임안에서 ESC를 눌렀을 때 뜨는 화면
void done_game_screen();
// done_game_screen에서 사용되는 네모칸
void yes_no_box(int x);
// 's' or 'S'를 눌렀을 때 뜨는 화면
// 원래는 'p' or 'P'였는 데, 아랫방향키와 'P' 가 같은 아스키코드를 가지고 있어서 바꿈(아스키코드 : 80)
void pause_screen();
// pause_screen에서 사용되는 네모칸
void pause_box(int y);
// 9칸, 16칸, 25칸이 다 찼을 때 뜨는 화면
void game_over_screen(int score);
// 2048을 만들었을 때 뜨는 화면
void win_screen(int score);
// game_over_box에서 사용되는 네모칸
void game_over_box(int x);

#endif // !__DEFAULT_FRAME_H__
