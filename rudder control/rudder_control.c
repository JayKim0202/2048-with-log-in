#include "rudder_control.h"

char_coord rudder_control(char_coord cc)
{
	// rudder - 방향키 받는 함수
	// tmp - enter를 받는 함수
	int rudder, tmp;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tmp_cc;

	// 기존 캐릭터 위치를 tmp_cc에 저장 후 출력
	tmp_cc.X = cc.x;
	tmp_cc.Y = cc.y;
	SetConsoleCursorPosition(handle, tmp_cc);
	printf("*");

	tmp = _getch();
	rudder = _getch();
	-+
	switch (rudder)
	{
	// 오른쪽
	case RIGHT:
		tmp_cc.X++;
		cc.x = tmp_cc.X;
		break;
	// 왼쪽
	case LEFT:
		tmp_cc.X--;
		cc.x = tmp_cc.X;
		break;
	// 아래
	case DOWN:
		tmp_cc.Y--;
		cc.y = tmp_cc.Y;
		break;
	// 위
	case UP:
		tmp_cc.Y++;
		cc.y = tmp_cc.Y;
		break;
	// 방향키가 아니면 프로그램을 종료한다.
	default:
		exit(0);
	}

	// 화면 클리어
	system("cls");

	return cc;
}