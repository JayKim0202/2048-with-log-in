#pragma once
#ifndef __SAVE_MEM_H__
#define __SAVE_MEM_H__

#include "main.h"

typedef struct mem_id {
	char* id;
	int index;
	struct mem_id* next;
}MEM_ID;

// ������ ���� ����
void dele_last_char(char* buf);
// �ε��� Ȯ�� �� ����
int return_index();
// ���̵� ��ħ Ȯ�� // ��ġ�� ��ġ�� �ε��� ���� // �ƴϸ� -1
int check_id_exist(char* ID);

#endif