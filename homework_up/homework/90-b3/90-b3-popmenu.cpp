/* 2152988 杨恺铭 计科 */
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;

//打印菜单位置
const int PRT_PARA = 20,
MENU_X = BOARD_COL - PRT_PARA, MENU_Y = 3;
const int BG = 7, FG = 0;//高亮菜单颜色

enum popmenu_opt { up, down, enter, esc };

//键盘读入操作指令
popmenu_opt get_act(void)
{
	popmenu_opt pop_opt;
	while (1) {
		int opt = _getch();
		if (opt == 224) {
			int move = _getch();
			if (move == 'H') {
				pop_opt = up;
				break;
			}
			else if (move == 'P') {
				pop_opt = down;
				break;
			}
		}
		else if (opt == 27) {
			pop_opt = esc;
			break;
		}
		else if (opt == 13) {
			pop_opt = enter;
			break;
		}
	}
	return pop_opt;
}
char* tj_strlwr(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (!str) {
		return str;
	}
	char* p = str;
	while (*p) {
		if (*p >= 'A' && *p <= 'Z') {
			(*p) += 'a' - 'A';
		}
		p++;
	}
	return str;
}
void to_be_continued(const int X, const int Y)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);
	cout << "关卡显示完成，按C/c继续...";
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
	}
	cct_cls();

	return;
}


void to_be_continued_end(void)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(0, BOARD_ROW - 3);
	cout << "本小题结束，请输入End继续...";
	int x1, y1;
	cct_getxy(x1, y1);
	const int m = 30;

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	char str[m];
	while (1) {
		cin.getline(str, m);
		tj_strlwr(str);
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		if (strcmp(str, "end") == 0) {
			break;
		}
		else {
			cout << "输入错误，请重新输入";
			cct_showch(x1, y1, ' ', 0, 7, m);
			cct_gotoxy(x1, y1);
		}
	}

	cct_cls();

	return;
}
//初始化打印菜单
void prt_menu_init(const file_list& L)
{
	if (L.top == 0) {
		return;
	}

	cct_gotoxy(MENU_X, MENU_Y);
	cct_setcolor();
	cout << "请选择关卡";
	cct_showstr(MENU_X - 1, MENU_Y + 1, "╔════╗");
	for (int i = 0; i < L.menu_num; i++) {
		cct_gotoxy(MENU_X - 1, MENU_Y + 2 + i);
		cout << "║";
		//可单独分离函数
		if (i == L.cur_list) {
			cct_setcolor(BG, FG);
		}
		cout << "关卡" << L.list[i] << ' ';
		if (i == L.cur_list) {
			cct_setcolor();
		}
		cout << "║";
	}
	cct_showstr(MENU_X - 1, MENU_Y + 2 + L.menu_num, "╚════╝");
}

//打印菜单内容，菜单更新
void prt_menu(const file_list& L)
{
	for (int i = 0; i < L.menu_num; i++) {
		cct_gotoxy(MENU_X + 1, MENU_Y + 2 + i);
		if (i+ L.cur_popmenu_first == L.cur_list) {
			cct_setcolor(BG, FG);
		}
		cout << "关卡" << L.list[i+ L.cur_popmenu_first] << ' ';
		if (i + L.cur_popmenu_first == L.cur_list) {
			cct_setcolor();
		}
	}
}

//正常的改变菜单，附属于operate_menu()
void operate_menu_one_prt(file_list& L, const int move)
{
	cct_gotoxy(MENU_X + 1, MENU_Y + 2 + L.cur_popmenu);
	cout << "关卡" << L.list[L.cur_list] << ' ';

	L.cur_list += move;
	L.cur_popmenu += move;

	cct_gotoxy(MENU_X + 1, MENU_Y + 2 + L.cur_popmenu);
	cct_setcolor(BG, FG);
	cout << "关卡" << L.list[L.cur_list] << ' ';
	cct_setcolor();
}
//菜单变化
void operate_menu(const popmenu_opt act, file_list& L)
{
	//考虑0的特殊情况
	if (L.top == 0) {
		return;
	}
	int move = act == down ? 1 : -1;
	if ((L.cur_list == 0 && act == up)
		|| (L.cur_list == L.top - 1 && act == down)) {
		return;
	}
	else if (L.top > MENU_NUM_MAX) {
		if ((L.cur_popmenu == L.menu_num - 1 && act == down)
			|| (L.cur_popmenu == 0 && act == up)) {
			L.cur_list += move;
			L.cur_popmenu_first += move;
			prt_menu(L);
		}
		else {
			operate_menu_one_prt(L, move);
		}
	}
	else if (L.top <= MENU_NUM_MAX) {
		operate_menu_one_prt(L, move);
	}
}

//滚动菜单
void popmenu(file_list& L)
{
	//prtmenu
	prt_menu_init(L);
	while (1) {
		if (L.top == 0) {
			cct_gotoxy(0, 0);
			cout<<"stage目录下没有符合要求的关卡文件";
			return;
		}
		//获取指令
		popmenu_opt act = get_act();
		if (act == up || act == down) {
			operate_menu(act, L);
		}
		else if (act == enter) {
			//if (L.top == 0) {
			//	continue;
			//}
			prt_game(L);
			int x, y;
			cct_getxy(x, y);
			to_be_continued(0, y+3);
			prt_menu_init(L);
			prt_menu(L);
		}
		else if (act == esc) {
			break;
		}
	}

}