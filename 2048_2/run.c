#include "run.h"

// 프리뷰화면 작동부
void run_preview_screen()
{
	int kb_input;
	int box_location[3][2] = { {8 ,1}, {10, 0}, {12, 8} };
	int location_count = 0;

	// sign up (8, 1)
	// log in(10, 0)
	// preview (12, 8)

	preview_screen();
	preview_box(box_location[0][0], box_location[0][1]);

	while (1)
	{
		kb_input = _getch();
		if (kb_input == ESC)
			exit(0);
		else if (kb_input == ENTER)
		{
			switch (location_count)
			{
			case 0:
				run_sign_up_screen();
				system("cls");
				preview_screen();
				preview_box(box_location[location_count][0], box_location[location_count][1]);
				break;
			case 1:
				// run_log_in_screen 만들어야 함
				system("cls");
				preview_screen();
				preview_box(box_location[location_count][0], box_location[location_count][1]);
				break;
			case 2:
				run_starting_screen();
				system("cls");
				preview_screen();
				preview_box(box_location[location_count][0], box_location[location_count][1]);
				break;
			}
		}
		
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();
		if (kb_input == 224)
			kb_input = _getch();

		switch (kb_input)
		{
		case UP:
			if (location_count == 0)break;
			system("cls");
			preview_screen();
			preview_box(box_location[--location_count][0], box_location[location_count][1]);
			break;
		case DOWN:
			if (location_count == 2)break;
			system("cls");
			preview_screen();
			preview_box(box_location[++location_count][0], box_location[location_count][1]);
			break;
		}
	}
}

// 회원가입 작동부
void run_sign_up_screen()
{
	MEM temp_mem = { 0 };
	MEM member = { 0 };
	int kb_input;
	char alpha[2] = { 0 };
	// 0 = ID / 1 = PW / 2 = name / 3 = age / 4 = create
	int struct_index = 0;
	Grid point[4] = { {.x = 12, .y = 3}, {.x = 12, .y = 6}, {.x = 12, .y = 9}, {.x = 12, .y = 12} };
	int is_enter = 0;
	int member_index;

	sign_up_screen();
	cursor_view_t();
	fix_cursor(point[struct_index].x, point[struct_index].y);
	
	while (1)
	{
		is_enter = 0;
		kb_input = _getch();
		if (kb_input == BACK_SPACE)
		{
			if (point[struct_index].x > 12)
			{
				switch (struct_index)
				{
				case 0:
					dele_last_char(temp_mem.ID);
					break;
				case 1:
					dele_last_char(temp_mem.PW);
					break;
				case 2:
					dele_last_char(temp_mem.name);
					break;
				case 3:
					dele_last_char(temp_mem.age);
					break;
				}
				text_output('\b', point[struct_index].x, point[struct_index].y);
				printf(" \b");
				point[struct_index].x--;
			}
			else
				continue;
		}
		else if (kb_input == 224)
		{
			kb_input = _getch();
			continue;
			// 나중에 left, right 구현 (확실 X)
		}
		else if (kb_input == TAB)
		{
			if (struct_index < 3)
			{
				struct_index++;
				fix_cursor(point[struct_index].x, point[struct_index].y);
			}
			else if (struct_index == 3)
			{
				cursor_view_f();
				sign_up_box(5, 14, 7);
				struct_index++;
			}
			else if (struct_index > 3)
			{
				cursor_view_t();
				dele_box(5, 14, 7);
				struct_index = 0;
				fix_cursor(point[struct_index].x, point[struct_index].y);
			}
		}
		else if (kb_input == SPACE_BAR)
			continue;
		else if (kb_input == ESC)
			return;
		else if (isalpha((char)kb_input) || isdigit((char)kb_input))
		{
			alpha[0] = (char)kb_input;
			text_output(alpha[0], point[struct_index].x, point[struct_index].y);
			point[struct_index].x++;

			switch (struct_index)
			{
			case 0:
				strcat(temp_mem.ID, alpha);
				break;
			case 1:
				strcat(temp_mem.PW, alpha);
				break;
			case 2:
				strcat(temp_mem.name, alpha);
				break;
			case 3:
				strcat(temp_mem.age, alpha);
				break;
			}
		}
		else if (kb_input == ENTER)
		{
			if (struct_index < 3)
			{
				struct_index++;
				fix_cursor(point[struct_index].x, point[struct_index].y);
			}
			else if (struct_index == 3)
			{
				cursor_view_f();
				sign_up_box(5, 14, 7);
				struct_index++;
			}
			else if (struct_index == 4)
			{
				if (point[3].x - 12)
				{
					int is_num = 0;
					for (int i = 0; i < point[3].x - 12; i++)
					{
						if (isdigit(temp_mem.age[i]) == 0)
							is_num++;
					}

					if (is_num > 0)
					{
						system("cls");
						is_no_digit();
						_getch();
						struct_index = 0;
						sign_up_screen();
						cursor_view_t();
						string_output(temp_mem.ID, 12, point[0].y);
						string_output(temp_mem.PW, 12, point[1].y);
						string_output(temp_mem.name, 12, point[2].y);
						string_output(temp_mem.age, 12, point[3].y);
						fix_cursor(point[struct_index].x, point[struct_index].y);
					}
					else if (temp_mem.ID[0] == '\0' || temp_mem.PW[0] == '\0' || temp_mem.name[0] == '\0' || temp_mem.age[0] == '\0')
					{
						system("cls");
						print_empty(temp_mem.ID[0], temp_mem.PW[0], temp_mem.name[0], temp_mem.age[0]);
						_getch();
						struct_index = 0;
						sign_up_screen();
						cursor_view_t();
						string_output(temp_mem.ID, 12, point[0].y);
						string_output(temp_mem.PW, 12, point[1].y);
						string_output(temp_mem.name, 12, point[2].y);
						string_output(temp_mem.age, 12, point[3].y);
						fix_cursor(point[struct_index].x, point[struct_index].y);
					}
					else
						is_enter = 1;
				}
				else if (temp_mem.ID[0] == '\0' || temp_mem.PW[0] == '\0' || temp_mem.name[0] == '\0' || temp_mem.age[0] == '\0')
				{
					system("cls");
					print_empty(temp_mem.ID[0], temp_mem.PW[0], temp_mem.name[0], temp_mem.age[0]);
					_getch();
					struct_index = 0;
					sign_up_screen();
					cursor_view_t();
					string_output(temp_mem.ID, 12, point[0].y);
					string_output(temp_mem.PW, 12, point[1].y);
					string_output(temp_mem.name, 12, point[2].y);
					string_output(temp_mem.age, 12, point[3].y);
					fix_cursor(point[struct_index].x, point[struct_index].y);
				}
				else
					is_enter = 1;

				if (is_enter)
				{
					temp_mem.index = return_index();

					if (temp_mem.index != 0)
					{
						member_index = check_id_exist(member.ID);
						// 아이디가 겹치는게 있을 때
						if (member_index > -1)
						{
							system("cls");
							id_overlap_screen();
							_getch();
							for (int i = 0; i < 25; i++)
							{
								temp_mem.ID[i] = '\0';
								temp_mem.PW[i] = '\0';
								if (i < 4)
									point[i].x = 12;
								if (i < 5)
									temp_mem.age[i] = '\0';
								if (i < 20)
									temp_mem.name[i] = '\0';
							}
							temp_mem.index = 0;
							struct_index = 0;
							sign_up_screen();
							cursor_view_t();
							fix_cursor(point[struct_index].x, point[struct_index].y);
							continue;
						}
						// 아이디가 겹치지 않을 때
						else
						{
							system("cls");
							strcpy(member.ID, temp_mem.ID);
							strcpy(member.PW, temp_mem.PW);
							strcpy(member.name, temp_mem.name);
							strcpy(member.age, temp_mem.age);
							member.index = temp_mem.index;
							// 생성 칸













							done_sign_up();
							_getch();
							return;
						}
					}
				}
			}
		}
	}

	

	// 2. 파일이 없을 경우 파일 생성 후 5번으로 넘어감
	// 3. 기존 파일에서 member랑 겹치는게 있는지 확인
	// 4. 겹치면 "이미 있는 아이디 입니다." 출력 -> 다시 회원가입창으로 이동, 아이디만 빈칸으로 생성 기존에 입력했던 것들은 모두 화면에 띄우기
	// 5. 안 겹치면 "회원가입이 완료되었습니다."출력



	// 저장 시 방법
	// ID, PW, name, age, score, index \n
	// 게임 오버 시 스코어 바꿔서 다시 저장 -> 아직 구현 안함
	// index는 파일이 처음 생성 됬을 때는 0으로 저장
	// 파일이 이미 있는 경우 파일의 가장 마지막 세자리 문자를 숫자로 읽어 ++해준다.








	
}







// 시작화면 작동부
void run_starting_screen()
{
	int kb_input;	// 키받는 변수
	int box_location[3] = { 8, 10, 12 };	// 네모 칸들의 생성 위치 좌표
	int location_count = 0;	// 네모 칸들의 생성 위치 좌표의 인덱스

	cursor_view_f();
	starting_screen();	// 시작화면 출력용
	vertical_selection_box(box_location[location_count]);	// 시작화면에 네모칸 출력용

	// 네모칸을 방향키로 움직이기 위해 무한으로 키를 받음
	while (1)
	{
		kb_input = _getch();	// 키받음
		if (kb_input == ESC)	// ESC는 1bit이기 때문에 한번 입력받고 확인 해줌
		{
			// 로그아웃되었습니다.
			return;


			//여
			//기
			//만
			//들
			//어
			//야
			//함






		}
		else if (kb_input == ENTER)	// ENTER도 1bit이기 때문에 한번 입력바도 확인 해줘야함
		{
			// 엔터를 누르면 그 칸에 맞는 함수들이 실행된다.
			switch (location_count)
			{
			case 0:		// START
				run_mode_screen();	// 3x3 4x4 5x5 선택지로 넘어감
				system("cls");	// 위의 함수가 끝나면 다시 시작화면을 출력하기 위해 화면은 클리어 해줘야함
				// 시작화면 출력
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			case 1:		// RULE
				rule();		// 룰 설명으로 넘어감
				system("cls");	// 위의 함수가 끝나면 다시 시작화면을 출력하기 위해 화면은 클리어 해줘야함
				// 시작화면 출력
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			case 2:		// RANK
				// 랭크 함수를 넣음 (아직 안만듬..ㅋ)
				// 데이터 세이빙 소스파일 생성해야함 (물론 아직 안만듬..ㅋ)
				break;
			}
		}
		// 위의 메뉴가 실행되고 나면 kb_input에는 여전히 ENTER가 입력되어있음
		// continue를 안넣으면 엔터나 ESC를 눌러도 작동되지 않는 오류가 생길 수 있음
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();
		if (kb_input == 224)	// 방향키를 뜻하는 224가 눌리지 않았다면 ESC나 ENTER임으로 키를 받지 않고 다시 처음으로 돌아가 다시 반복한다.
			kb_input = _getch();	// 방향키가 맞을 경우 입력된 값을 받아옴
		
		// 네모칸을 위아래로 움직이기 위한 것들
		switch (kb_input)
		{
		case UP:
			if (location_count == 0)break;		// 가장 위에 네모가 위치해있을 때 더 이상 이동을 하지 못해게 막음
			// 네모박스가 이동한 것 처럼 보이기 위한 트릭
			system("cls");
			starting_screen();
			vertical_selection_box(box_location[--location_count]);
			break;
		case DOWN:
			if (location_count == 2)break;		// 가장 아래에 네모가 위치해있을 때 더 이상 이동을 하지 못하게 막음
			// 네모박스가 이동한 것 처럼 보이기 위한 트릭
			system("cls");
			starting_screen();
			vertical_selection_box(box_location[++location_count]);
			break;
		}
	}
}

// 모드화면 작동부
void run_mode_screen()
{
	int box_location[3] = { 2, 12, 22 };	// 네모 칸들의 생성 위치 좌표
	int kb_input;	// 키받는 변수
	int location_count = 0;		// 네모 칸들의 생성 위치 좌표의 인덱스

	mode_screen();	// 모드 화면 출력용
	horizon_selection_box(box_location[location_count]);	// 네모칸 생성

	while (1)
	{
		kb_input = _getch();
		if (kb_input == ESC)
			return;
		else if (kb_input == ENTER)
		{
			// 3x3 (17, 13)
			// 4x4 (24, 17)
			// 5x5 (31, 21)
			switch (location_count)
			{
			case 0:
				system("cls");
				run_real_game3();
				system("cls");
				mode_screen();
				horizon_selection_box(box_location[location_count]);
				break;
			case 1:
				system("cls");
				run_real_game4();
				system("cls");
				mode_screen();
				horizon_selection_box(box_location[location_count]);
				break;
			case 2:
				system("cls");
				run_real_game5();
				system("cls");
				mode_screen();
				horizon_selection_box(box_location[location_count]);
				break;
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();

		switch (kb_input)
		{
		case LEFT:
			if (location_count == 0) break;
			system("cls");
			mode_screen();
			horizon_selection_box(box_location[--location_count]);
			break;
		case RIGHT:
			if (location_count == 2) break;
			system("cls");
			mode_screen();
			horizon_selection_box(box_location[++location_count]);
			break;
		}
	}
}

// 3x3 게임 작동부
void run_real_game3()
{
	int number_table[3][3] = { 0 };
	int rand_x = 0;
	int rand_y = 0;
	int is_x_empty[3] = { 0 };
	int is_y_empty[3] = { 0 };
	int score = 0;
	int is_2048 = 0;

	int kb_input = 0;

	while (1)
	{
		play_screen(21, 13, 34, score);

		while (1)
		{
			rand_x = rand() % 3;
			while (is_x_empty[rand_x] == 1)
			{
				rand_x = rand() % 3;
				if (is_full3(number_table) == 9) break;
			}
			is_x_empty[rand_x] = 1;
			rand_y = rand() % 3;
			while (is_y_empty[rand_y] == 1 && number_table[rand_x][rand_y] != 0)
			{
				rand_y = rand() % 3;
				if (is_full3(number_table) == 9) break;
			}
			is_y_empty[rand_y] = 1;

			for (int i = 0; i < 3; i++)
			{
				is_x_empty[i] = 0;
				is_y_empty[i] = 0;
			}

			if (is_full3(number_table) == 9 || number_table[rand_x][rand_y] == 0) break;
		}

		// 2048이 만들어졌나 확인
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (number_table[i][j] == 2048)
				{
					is_2048 = 1;
					break;
				}
			}
			if (is_2048 == 1) break;
		}

		if (is_full3(number_table) != 9)
		{
			number_table[rand_x][rand_y] = (rand() % 2 + 1) * 2;
			print_number(rand_x, rand_y, number_table[rand_x][rand_y]);
			score += number_table[rand_x][rand_y];
		}
		else if (is_full3(number_table) == 9 && is_same3(number_table) == 0)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			game_over_screen(score);
			game_over_box(box_location[location_count]);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					game_over_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					game_over_screen(score);
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(21, 13, 34, score);
		}
		// 여기서 else if로 9칸중에 2048이 된 칸이 있으면 win 화면 띄어줌
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					win_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					win_screen(score);
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(21, 13, 34, score);
		}

		if ((kb_input != 's' && kb_input != 'S') && kb_input != ESC)
			kb_input = _getch();

		if (kb_input == ESC)
		{
			int location_count = 0;
			int box_location[2] = { 15, 24 };
			system("cls");
			done_game_screen();
			yes_no_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ESC || (kb_input == ENTER && location_count == 0))
					return;
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					kb_input = 0;
					break;
				}
				kb_input = _getch();
				switch (kb_input)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					done_game_screen();
					yes_no_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					done_game_screen();
					// ++location_count로 하면 경고 뜸..? 왠지 모르겠음
					yes_no_box(box_location[location_count =+ 1]);
					break;
				}
			}
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
					print_number(i, j, number_table[i][j]);
				}
			}
		}
		else if (kb_input == 's' || kb_input == 'S')
		{
			int location_count = 0;
			int box_location[3] = { 4, 7, 10};
			system("cls");
			pause_screen();
			pause_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ENTER && location_count == 0)
				{
					system("cls");
					play_screen(21, 13, 34, score);
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							if (number_table[i][j] != 0)
								print_number(i, j, number_table[i][j]);
						}
					}
					kb_input = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 2)
				{
					return;
				}
				if (kb_input == 224)
					kb_input = _getch();
				switch (kb_input)
				{
				case UP:
					if (location_count == 0) break;
					system("cls");
					pause_screen();
					pause_box(box_location[--location_count]);
					break;
				case DOWN:
					if (location_count == 2) break;
					system("cls");
					pause_screen();
					pause_box(box_location[++location_count]);
					break;
				}
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();
		else if ((kb_input == 's' || kb_input == 'S') || kb_input == ESC)
			continue;

		switch (kb_input)
		{
		case UP:
			up3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case DOWN:
			down3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case LEFT:
			left3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case RIGHT:
			right3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		}
	}
}

// 4x4 게임 작동부
void run_real_game4()
{
	int number_table[4][4] = { 0 };
	int rand_x = 0;
	int rand_y = 0;
	int is_x_empty[4] = { 0 };
	int is_y_empty[4] = { 0 };
	int score = 0;
	int is_2048 = 0;

	int kb_input = 0;

	while (1)
	{
		play_screen(30, 21, 43, score);

		while (1)
		{
			rand_x = rand() % 4;
			while (is_x_empty[rand_x] == 1)
			{
				rand_x = rand() % 4;
				if (is_full4(number_table) == 16) break;
			}
			is_x_empty[rand_x] = 1;
			rand_y = rand() % 4;
			while (is_y_empty[rand_y] == 1 && number_table[rand_x][rand_y] != 0)
			{
				rand_y = rand() % 4;
				if (is_full4(number_table) == 16) break;
			}
			is_y_empty[rand_y] = 1;

			for (int i = 0; i < 4; i++)
			{
				is_x_empty[i] = 0;
				is_y_empty[i] = 0;
			}

			if (is_full4(number_table) == 16 || number_table[rand_x][rand_y] == 0) break;
		}

		// 2048이 만들어졌나 확인
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (number_table[i][j] == 2048)
				{
					is_2048 = 1;
					break;
				}
			}
			if (is_2048 == 1) break;
		}

		if (is_full4(number_table) != 16)
		{
			number_table[rand_x][rand_y] = (rand() % 2 + 1) * 2;
			print_number(rand_x, rand_y, number_table[rand_x][rand_y]);
			score += number_table[rand_x][rand_y];
		}
		else if (is_full4(number_table) == 16 && is_same4(number_table) == 0)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			game_over_screen(score);
			game_over_box(box_location[location_count]);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					game_over_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					game_over_screen(score);
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(30, 21, 43, score);
		}
		// 여기서 else if로 9칸중에 2048이 된 칸이 있으면 win 화면 띄어줌
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					win_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					win_screen(score);
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(30, 21, 43, score);
		}

		if ((kb_input != 's' && kb_input != 'S') && kb_input != ESC)
			kb_input = _getch();

		if (kb_input == ESC)
		{
			int location_count = 0;
			int box_location[2] = { 15, 24 };
			system("cls");
			done_game_screen();
			yes_no_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ESC || (kb_input == ENTER && location_count == 0))
					return;
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					kb_input = 0;
					break;
				}
				kb_input = _getch();
				switch (kb_input)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					done_game_screen();
					yes_no_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					done_game_screen();
					// ++location_count로 하면 경고 뜸..? 왠지 모르겠음
					yes_no_box(box_location[location_count = +1]);
					break;
				}
			}
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
		}
		else if (kb_input == 's' || kb_input == 'S')
		{
			int location_count = 0;
			int box_location[3] = { 4, 7, 10 };
			system("cls");
			pause_screen();
			pause_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ENTER && location_count == 0)
				{
					system("cls");
					play_screen(30, 21, 43, score);
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (number_table[i][j] != 0)
								print_number(i, j, number_table[i][j]);
						}
					}
					kb_input = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 2)
				{
					return;
				}
				if (kb_input == 224)
					kb_input = _getch();
				switch (kb_input)
				{
				case UP:
					if (location_count == 0) break;
					system("cls");
					pause_screen();
					pause_box(box_location[--location_count]);
					break;
				case DOWN:
					if (location_count == 2) break;
					system("cls");
					pause_screen();
					pause_box(box_location[++location_count]);
					break;
				}
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();
		else if ((kb_input == 's' || kb_input == 'S') || kb_input == ESC)
			continue;

		switch (kb_input)
		{
		case UP:
			up4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case DOWN:
			down4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case LEFT:
			left4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case RIGHT:
			right4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		}
	}
}

// 5x5 게임 작동부
void run_real_game5()
{
	int number_table[5][5] = { 0 };
	int rand_x = 0;
	int rand_y = 0;
	int is_x_empty[5] = { 0 };
	int is_y_empty[5] = { 0 };
	int score = 0;
	int is_2048 = 0;

	int kb_input = 0;

	while (1)
	{
		play_screen(39, 26, 52, score);

		while (1)
		{
			rand_x = rand() % 5;
			while (is_x_empty[rand_x] == 1)
			{
				rand_x = rand() % 5;
				if (is_full5(number_table) == 25) break;
			}
			is_x_empty[rand_x] = 1;
			rand_y = rand() % 5;
			while (is_y_empty[rand_y] == 1 && number_table[rand_x][rand_y] != 0)
			{
				rand_y = rand() % 5;
				if (is_full5(number_table) == 25) break;
			}
			is_y_empty[rand_y] = 1;

			for (int i = 0; i < 5; i++)
			{
				is_x_empty[i] = 0;
				is_y_empty[i] = 0;
			}

			if (is_full5(number_table) == 25 || number_table[rand_x][rand_y] == 0) break;
		}

		// 2048이 만들어졌나 확인
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (number_table[i][j] == 2048)
				{
					is_2048 = 1;
					break;
				}
			}
			if (is_2048 == 1) break;
		}

		if (is_full5(number_table) != 25)
		{
			number_table[rand_x][rand_y] = (rand() % 2 + 1) * 2;
			print_number(rand_x, rand_y, number_table[rand_x][rand_y]);
			score += number_table[rand_x][rand_y];
		}
		else if (is_full5(number_table) == 25 && is_same5(number_table) == 0)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			game_over_screen(score);
			game_over_box(box_location[location_count]);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					game_over_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					game_over_screen(score);
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(39, 26, 52, score);
		}
		// 여기서 else if로 9칸중에 2048이 된 칸이 있으면 win 화면 띄어줌
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					win_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					win_screen(score);
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(39, 26, 52, score);
		}

		if ((kb_input != 's' && kb_input != 'S') && kb_input != ESC)
			kb_input = _getch();

		if (kb_input == ESC)
		{
			int location_count = 0;
			int box_location[2] = { 15, 24 };
			system("cls");
			done_game_screen();
			yes_no_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ESC || (kb_input == ENTER && location_count == 0))
					return;
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					kb_input = 0;
					break;
				}
				kb_input = _getch();
				switch (kb_input)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					done_game_screen();
					yes_no_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					done_game_screen();
					// ++location_count로 하면 경고 뜸..? 왠지 모르겠음
					yes_no_box(box_location[location_count = +1]);
					break;
				}
			}
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
		}
		else if (kb_input == 's' || kb_input == 'S')
		{
			int location_count = 0;
			int box_location[3] = { 4, 7, 10 };
			system("cls");
			pause_screen();
			pause_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ENTER && location_count == 0)
				{
					system("cls");
					play_screen(39, 26, 52, score);
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 5; j++)
						{
							if (number_table[i][j] != 0)
								print_number(i, j, number_table[i][j]);
						}
					}
					kb_input = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 2)
				{
					return;
				}
				if (kb_input == 224)
					kb_input = _getch();
				switch (kb_input)
				{
				case UP:
					if (location_count == 0) break;
					system("cls");
					pause_screen();
					pause_box(box_location[--location_count]);
					break;
				case DOWN:
					if (location_count == 2) break;
					system("cls");
					pause_screen();
					pause_box(box_location[++location_count]);
					break;
				}
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();
		else if ((kb_input == 's' || kb_input == 'S') || kb_input == ESC)
			continue;

		switch (kb_input)
		{
		case UP:
			up5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case DOWN:
			down5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case LEFT:
			left5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case RIGHT:
			right5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		}
	}
}

// 커서 숨김
void cursor_view_f()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 커서 보임
void cursor_view_t()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = TRUE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 플레이어 아이디, 스코어 저장
// 게임 오버시 플레이어 아이디 생성
// 만약 같은 아이디가 같을 시
// 같은 아이디가 이미 등록되어 있습니다.
// 덮어쓰기, 새로운 아이디