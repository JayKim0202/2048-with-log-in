#include "main.h"
#include "rudder_control.h"
#include "line.h"
#include "finish.h"


int main()
{
	// 캐릭터 좌표 변수
	char_coord cc;
	
	// 캐릭터의 좌표를 0,0으로 초기화
	cc.x = 0;
	cc.y = 0;

	while (1)
	{
		start_line();
		finish_line();

		// 캐릭터 좌표 변경 함수
		cc = rudder_control(cc);

		// finish line에 닿으면 finish를 출력하고 종료한다.
		if (cc.x >= 80)
		{
			finish();
			return 0;
		}
	}
	
	return 0;
}