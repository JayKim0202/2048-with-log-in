#include "finish.h"

int finish() {
	// ȭ�� Ŭ����
	system("cls");

	// �ܼ� Ŀ�� ��ġ ������ ���� ����
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	// Ŀ�� ��ġ ����
	coord.X = 45;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);

	printf("finish");

	for (int i = 0; i < 10; i++)
		printf("\n");

	return 0;
}