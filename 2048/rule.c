#include "rule.h"

void rule()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
	}

	coord.X = 0;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 38;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 0;
	coord.Y = 21;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
	}

	coord.X = 3;
	coord.Y = 2;
	SetConsoleCursorPosition(handle, coord);
	printf("���� �� 2���� 2(�Ǵ� 4)�� ��Ÿ����.");

	coord.X = 3;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("Ű������ ����Ű�� ������ �����");

	coord.X = 3;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("���� �� �������� �̵��ϸ鼭 ����");

	coord.X = 3;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("���ڰ� ���� ��� ��������, ���ڸ�");

	coord.X = 3;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("�� �� ĭ�� �����ϰ� 2 �Ǵ� 4�� ��");

	coord.X = 3;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("�´�. �̸� �ݺ��ؼ� 2�κ��� 2048��");

	coord.X = 3;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("����� ���� CLEAR");

	coord.X = 3;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("2048�� ����� �� 16ĭ�� �� ����");

	coord.X = 3;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("���鼭 ������ �� ĭ�� ���� ���� ��,");

	coord.X = 3;
	coord.Y = 12;
	SetConsoleCursorPosition(handle, coord);
	printf("GAME OVER");

	// ��ó ��Ű�ǵ��

	_getch();
}