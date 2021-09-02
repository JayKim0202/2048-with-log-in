#include "save_mem.h"

// 마지막 문자 삭제
void dele_last_char(char* buf)
{
	int i = 0;
	while (buf[i])
	{
		i++;
	}
	buf[i - 1] = '\0';
}

// 인덱스 확인 및 리턴
int return_index()
{
	FILE* fp;
	fp = fopen("2048_member.txt", "a+t");

	int size = 0;
	char* buffer;
	char seps[] = " ,\t\n";
	char* token;
	int index = 0;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	buffer = malloc(15);
	memset(buffer, 0, 15);

	if (size > 0)
	{
		fseek(fp, -15, SEEK_CUR);
		fread(buffer, 15, 1, fp);

		token = strtok(buffer, seps);

		while (token != NULL)
		{
			token = strtok(NULL, seps);
			if (token != NULL && isdigit(token[0]))
				index = atoi(token);
		}

		fclose(fp);
		return index;
	}
	else
	{
		fclose(fp);
		return -1;
	}
}

// 아이디 겹침 확인 // 겹치면 겹치는 인덱스 리턴 // 아니면 -1
int check_id_exist(char* ID)
{
	FILE* fp = fopen("2048_member.txt", "a+t");

	int size;
	char* buffer;
	char* token;
	int i = 0;
	char seps[] = " ,\t\n";
	MEM_ID* mi_head = malloc(sizeof(MEM_ID));
	memset(mi_head, NULL, sizeof(MEM_ID));
	MEM_ID* mi_tail = mi_head;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	buffer = malloc(size + 1);
	memset(buffer, 0, size + 1);

	if (size > 0)
	{
		fseek(fp, 0, SEEK_SET);
		fread(buffer, size, 1, fp);

		token = strtok(buffer, seps);
		mi_tail->id = malloc(sizeof(token) + 1);
		memset(mi_tail->id, NULL, sizeof(token) + 1);
		strcpy(mi_tail->id, token);
		i++;

		while (token != NULL)
		{
			token = strtok(NULL, seps);
			if (token != NULL && i == 0)
			{
				mi_tail->next = malloc(sizeof(MEM_ID));
				mi_tail = mi_tail->next;
				mi_tail->id = malloc(sizeof(token) + 1);
				memset(mi_tail->id, NULL, sizeof(token) + 1);
				strcpy(mi_tail->id, token);
				mi_tail->next = NULL;
			}
			else if (token != NULL && i == 4)
			{
				mi_tail->index = atoi(token);
			}
			i++;
			if (i > 4)
				i = 0;
		}
	}

	mi_tail = mi_head;

	char* ptr = NULL;
	int index;


	while (ptr == NULL && mi_tail != NULL)
	{
		ptr = strstr(mi_tail->id, ID);
		if (ptr != NULL)
		{
			fclose(fp);
			return mi_tail->index;
		}
		mi_tail = mi_tail->next;
	}

	fclose(fp);
	return -1;
}

// 이거 삭제하고 다시 만들기
// 아이디 생성
void create_id(MEM* ID)
{
	FILE* fp = fopen("2048_member.txt", "a+t");

	
}