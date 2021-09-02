#include "main.h"
#include "rudder_control.h"
#include "line.h"
#include "finish.h"


int main()
{
	// ĳ���� ��ǥ ����
	char_coord cc;

	// ĳ������ ��ǥ�� 0,0���� �ʱ�ȭ
	cc.x = 0;
	cc.y = 0;

	while (1)
	{
		start_line();
		finish_line();

		// ĳ���� ��ǥ ���� �Լ�
		cc = rudder_control(cc);

		// finish line�� ������ finish�� ����ϰ� �����Ѵ�.
		if (cc.x >= 80)
		{
			finish();
			return 0;
		}
	}

	return 0;
}