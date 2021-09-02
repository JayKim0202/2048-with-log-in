#include "rudder_control.h"

char_coord rudder_control(char_coord cc)
{
	// rudder - ����Ű �޴� �Լ�
	// tmp - enter�� �޴� �Լ�
	int rudder, tmp;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tmp_cc;

	// ���� ĳ���� ��ġ�� tmp_cc�� ���� �� ���
	tmp_cc.X = cc.x;
	tmp_cc.Y = cc.y;
	SetConsoleCursorPosition(handle, tmp_cc);
	printf("*");

	tmp = _getch();
	rudder = _getch();
	-+
	switch (rudder)
	{
	// ������
	case RIGHT:
		tmp_cc.X++;
		cc.x = tmp_cc.X;
		break;
	// ����
	case LEFT:
		tmp_cc.X--;
		cc.x = tmp_cc.X;
		break;
	// �Ʒ�
	case DOWN:
		tmp_cc.Y--;
		cc.y = tmp_cc.Y;
		break;
	// ��
	case UP:
		tmp_cc.Y++;
		cc.y = tmp_cc.Y;
		break;
	// ����Ű�� �ƴϸ� ���α׷��� �����Ѵ�.
	default:
		exit(0);
	}

	// ȭ�� Ŭ����
	system("cls");

	return cc;
}