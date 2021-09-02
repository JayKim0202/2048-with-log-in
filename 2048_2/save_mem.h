#pragma once
#ifndef __SAVE_MEM_H__
#define __SAVE_MEM_H__

#include "main.h"

typedef struct mem_id {
	char* id;
	int index;
	struct mem_id* next;
}MEM_ID;

// 마지막 문자 삭제
void dele_last_char(char* buf);
// 인덱스 확인 및 리턴
int return_index();
// 아이디 겹침 확인 // 겹치면 겹치는 인덱스 리턴 // 아니면 -1
int check_id_exist(char* ID);

#endif