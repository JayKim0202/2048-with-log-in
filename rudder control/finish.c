#include "finish.h"

int finish() {
	// 화면 클리어
	system("cls");

	// 콘솔 커서 위치 설정의 위한 변수
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	// 커서 위치 설정
	coord.X = 45;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);

	printf("finish");

	for (int i = 0; i < 10; i++)
		printf("\n");

	return 0;
}