/* 2152988 杨恺铭 计科 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;


int menu(void)
{
	const char* menu[OPTION_NUM] =
	{
		"1.内部数组，随机生成初始5个球",
		"2.内部数组，随机生成60 % 的球，寻找移动路径",
		"3.内部数组，完整版",
		"4.画出n * n的框架（无分隔线），随机显示5个球",
		"5.画出n * n的框架（有分隔线），随机显示5个球",
		"6.n * n的框架，60 % 的球，支持鼠标，完成一次移动",
		"7.cmd图形界面完整版",
		"0.退出",
	};
	cct_setcolor();
	cout << "---------------------------------" << endl;
	for (int i = 0; i < OPTION_NUM; i++) {
		cout << menu[i] << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "[请选择:] ";

	int i;
	while (1) {
		i = _getche();
		if (i >= '0' && i <= OPTION_NUM + '0') {
			break;
		}
		else {
			cout << "\b \b";
		}
	}
	return i;
}

int main()
{
	cct_setfontsize("Terminal", 16, 8);
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {

		game G = { {0}, {0} };
		int option = menu() - '0';
		if (option == 1) {
			cct_cls();
			cct_gotoxy(0, 0);
			input_rl(G.row, G.line);
			gen_ball_init(G, 5);
			cout << endl;
			cout << "初始数组:" << endl;
			prt_G(G);
			to_be_continued();
		}
		else if (option == 2) {
			cct_cls();
			cct_gotoxy(0, 0);
			input_rl(G.row, G.line);

			//初始化
			gen_ball_init(G, G.row * G.line * 3 / 5);
			cout << endl;

			option2(G);

			to_be_continued();
		}
		else if (option == 3) {
			cct_cls();
			cct_gotoxy(0, 0);
			input_rl(G.row, G.line);

			//初始化
			gen_ball_init(G, 5);
			cout << endl;

			//进入游戏循环
			option3(G);

			//记录得分
			to_be_continued();
		}
		else if (option == 4|| option==5) {
			cct_cls();
			cct_gotoxy(0, 0);
			input_rl(G.row, G.line);

			//初始化
			gen_ball_init(G, 5);
			cout << endl;


			cout << "当前数组:" << endl;
			prt_G(G);
			cout << endl;

			const char* str = "按回车键显示图形...";
			to_be_continued_endl(str);
			int line, row, buff_r, buff_l;
			change_boarder(G, option, line, row,
				buff_r, buff_l);
			if (option == 4) {
				prt_boarder_opt4(G);
				cct_gotoxy(0, BOARDER_Y + 1 + G.row);
			}
			else {
				prt_boarder(G);
				cct_gotoxy(0 , BOARDER_Y + G.row * 2 );
			}


			//调整回窗口
			to_be_continued();
			cct_setfontsize("Terminal", 16, 8);
			cct_setconsoleborder(120, 40, 120, 9000);

		}
		else if (option == 6) {
			cct_cls();
			cct_gotoxy(0, 0);
			input_rl(G.row, G.line);

			//初始化
			gen_ball_init(G, G.row * G.line * 3 / 5);
			cout << endl;

			int line, row, buff_r, buff_l;
			change_boarder(G, option, line, row,
				buff_r, buff_l);
			prt_boarder(G);

			opt6(G);

			cct_gotoxy(0, BOARDER_Y + G.row * 2);
			to_be_continued();
			cct_setfontsize("Terminal", 16, 8);
			cct_setconsoleborder(120, 40, 120, 9000);

		}
		else if (option == 7) {
			cct_cls();
			cct_gotoxy(0, 0);
			input_rl(G.row, G.line);

			//初始化
			gen_ball_init(G, 5);
			cout << endl;

			int line, row, buff_r, buff_l;
			change_boarder(G, option, line, row,
				buff_r, buff_l);
			prt_boarder(G);
			prt_other_init(G);

			game_gui(G);

			cct_gotoxy(0, BOARDER_Y + G.row * 2);
			to_be_continued();
			cct_setfontsize("Terminal", 16, 8);
			cct_setconsoleborder(120, 40, 120, 9000);

		}
		else if (option == 0) {
			break;
		}

		cct_cls();

	}

	return 0;
}