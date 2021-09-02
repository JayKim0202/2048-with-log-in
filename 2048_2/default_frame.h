#pragma once
#ifndef __DEFAULT_FRAME_H__
#define __DEFAULT_FRAME_H__

#include "main.h"

// ȸ������, �α��� ����ȭ��
void preview_screen();
// ȸ������, �α��� ����ȭ�鿡�� ���Ǵ� �׸�ĭ
void preview_box(int y, int x_size);
// ȸ������
void sign_up_screen();
// ȸ������ ID, PW, name, age �׸�ĭ
// log in������ ���
void sign_up_box(int x, int y, int x_size);
// �α���
void log_in_screen();
// ���̵� ã��
void find_ID();
// ��й�ȣ ã��
void find_PW();
// �۾� ������ �Լ�
void text_output(char c, int x, int y);
// Ŀ�� ����
void fix_cursor(int x, int y);
// �׸� ����
void dele_box(int x, int y, int x_size);
// ��ĭ �ȳ� ǥ��
void print_empty(char id, char pw, char name, char age);
// ���� ���� �Լ�
void string_output(char s[], int x, int y);
// ���̰� ���ڰ� �ƴ� ���
void is_no_digit();
// ���̵� ��ĥ ���
void id_overlap_screen();
// ȸ������ �Ϸ� â
void done_sign_up();




// ����ȭ��
void starting_screen();
// 3x3, 4x4, 5x5 �� �����ϴ� ȭ��
void mode_screen();
// ������ �⺻ Ʋ
// x, y : ���� �������� ��ǥ
// other : ����Ű��  x��ǥ
void play_screen(int x, int y, int other, int score);
// starting_screen���� ���Ǵ� �׸�ĭ
void vertical_selection_box(int y);
// starting_screen���� ���Ǵ� �׸�ĭ
void horizon_selection_box(int x);
// ���� ����
void rule();
// ���Ӿȿ��� ESC�� ������ �� �ߴ� ȭ��
void done_game_screen();
// done_game_screen���� ���Ǵ� �׸�ĭ
void yes_no_box(int x);
// 's' or 'S'�� ������ �� �ߴ� ȭ��
// ������ 'p' or 'P'���� ��, �Ʒ�����Ű�� 'P' �� ���� �ƽ�Ű�ڵ带 ������ �־ �ٲ�(�ƽ�Ű�ڵ� : 80)
void pause_screen();
// pause_screen���� ���Ǵ� �׸�ĭ
void pause_box(int y);
// 9ĭ, 16ĭ, 25ĭ�� �� á�� �� �ߴ� ȭ��
void game_over_screen(int score);
// 2048�� ������� �� �ߴ� ȭ��
void win_screen(int score);
// game_over_box���� ���Ǵ� �׸�ĭ
void game_over_box(int x);

#endif // !__DEFAULT_FRAME_H__
