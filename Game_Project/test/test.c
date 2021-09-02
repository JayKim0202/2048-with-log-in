#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct mem_id {
	char* id;
	int index;
	struct mem_id* next;
}MEM_ID;

int file_index();
int check_id_exist(char* ID);

int main()
{
	int index = file_index() + 1;

	printf("%d\n", index);
	printf("%d", check_id_exist("kimjunghun"));

	return 0;
}

int file_index()
{
	FILE* fp;
	fp = fopen("2048_member.txt", "a+t");

	int size = 0;
	char* buffer;
	char seps[] = " ,\t\n";
	char* token;
	int index;

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

		return index;
	}
	else
		return -1;
}

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
			return mi_tail->index;
		mi_tail = mi_tail->next;
	}

	return -1;
}