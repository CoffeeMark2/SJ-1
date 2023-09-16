/* 2152988 杨恺铭 计科 */


/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;




int cnt = 0;
int prt_speed;
int stack[N_STACK][N]; //记录塔的栈
int top[N_STACK];//栈顶指针（指向最后元素的下一个）

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：static 有什么好处?
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	cct_cls();

	return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void prt_title(char src, char dst, int n)
{
	cct_gotoxy(0, 0);
	cout << "从 " << src << " 移动到 " << dst
		<< "，共 " << n << " 层，延时设置为 " << prt_speed;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

void input(int* pn, char* psrc, char* pdst, char* ptmp, int flag_speed)
{
	cct_gotoxy(INITX, INITY);
	int n;
	char src, dst;
	while (1) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (n >= 1 && n <= N) {
			break;
		}
	}
	*pn = n;
	cin.clear();
	cin.ignore(65536, '\n');
	while (1) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if (src >= 'a' && src <= 'c')
			src -= 32;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if ((src >= 'A' && src <= 'C')) {
			break;
		}
	}
	*psrc = src;
	cin.clear();
	cin.ignore(65536, '\n');
	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		dst = (dst >= 'a' && dst <= 'c') ? dst - 32 : dst;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if ((dst >= 'A' && dst <= 'C')) {
			if (dst == src)
				cout << "目标柱(" << dst
				<< ")不能与起始柱(" << src << ")相同\n";
			else
				break;
		}
	}
	*pdst = dst;
	cin.clear();
	cin.ignore(65536, '\n');
	*ptmp = 'B' * 3 - src - dst;
	if (flag_speed) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> prt_speed;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void prt_column(int color, int SETX, int SETY)
{
	//const int LENGTH = 23, HEIGHT = 12,GAP=9;
	int	set = SETX + LENGTH / 2;

	for (int i = 0; i < N_STACK; i++) {
		cct_showch(SETX + i * (LENGTH + GAP), SETY, CH, color, color, LENGTH);
	}
	for (int j = 0; j < HEIGHT; j++) {
		for (int i = 0; i < N_STACK; i++) {
			cct_showch(set + i * (LENGTH + GAP), SETY - j, CH, color, color, 1);
			Sleep(SLEEP/50);
		}
	}

	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(0, 0);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void prt_init_column(char src, int n, int SETX, int SETY)
{
	const int SET_COL = SET_COL_A + (src - 'A') * (LENGTH + GAP);
	for (int i = 0; i < n; i++) {
		int lenth = (n - i) * 2 + 1;
		cct_showch(SET_COL - n + i, SETY - i - 1, CH, n - i, n - i, lenth);
		Sleep(SLEEP / 20);
	}
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(0, 0);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
void prt_stack_verticle(int PRT_X, int PRT_Y)
{
	//恢复默认颜色
	int xa = PRT_X + 2, xb = xa + (PRT_LEN - 5) / 2,
		xc = xa + (PRT_LEN - 5);
	cct_gotoxy(PRT_X, PRT_Y);
	for (int i = 0; i < PRT_LEN; i++) {
		cout << '=';
	}
	cct_gotoxy(xa, PRT_Y + 1);
	cout << "A" << setw((PRT_LEN - 5) / 2)
		<< "B" << setw((PRT_LEN - 5) / 2) << "C";

	for (int set = 0; set < N_STACK; set++) {
		for (int i = 0; i < N; i++) {
			cct_gotoxy(xa + set * (PRT_LEN - 5) / 2 - 1, PRT_Y - 1 - i);
			if (i < top[set]) {
				cout << setw(2) << stack[set][i];
			}
			else {
				cout << setw(2) << "";
			}
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void prt_init_stack(int PRT_X, int PRT_Y)
{
	cct_gotoxy(PRT_X, PRT_Y + 4);
	cout << "初始:" << setw(14) << "";
	prt_stack();

}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void stack_init(char src, int n)
{
	for (int i = 0; i < n; i++) {
		stack[src - 'A'][i] = n - i;
	}
	top[src - 'A'] = n;

}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void stack_clear(void)
{
	for (int i = 0; i < N_STACK; i++) {
		top[i] = 0;
	}
	cnt = 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：n盘的序号
  返 回 值：
  说    明：
***************************************************************************/
void prt_move(const char src, const char dst, const int n, int SETX, int SETY, int flag_game)
{
	const int SRC_X = SET_COL_A + (src - 'A') * (LENGTH + GAP),
		SRC_Y = SETY - top[src - 'A'];
	const int DST_X = SET_COL_A + (dst - 'A') * (LENGTH + GAP),
		DST_Y = SETY - top[dst - 'A'];
	//上升
	for (int i = 0; i < HEIGHT - top[src - 'A']; i++) {
		cct_showch(SRC_X - n, SRC_Y - i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		cct_showch(SRC_X, SRC_Y - i, ' ', COLOR_WHITE, COLOR_WHITE, 1);
		cct_showch(SRC_X - n, SRC_Y - i - 1, ' ', n, n, 2 * n + 1);
		if (prt_speed)
			Sleep(SLEEP/prt_speed / 20);
		else
			Sleep(SLEEP / 20);
	}

	if (src < dst) {
		//右移（左移能否用相同的地方）
		for (int i = 0; i < DST_X - SRC_X; i++) {
			cct_showch(SRC_X - n + i, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);

			cct_showch(SRC_X - n + i + 1, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', n, n, 2 * n + 1);
			if (prt_speed)
				Sleep(SLEEP / prt_speed/3 / 20);
			else
				Sleep(SLEEP/3 / 20);
		}
	}
	else {
		//左移
		for (int i = 0; i < SRC_X - DST_X; i++) {
			cct_showch(SRC_X - n - i, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);

			cct_showch(SRC_X - n - i - 1, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', n, n, 2 * n + 1);
			if (prt_speed)
				Sleep(SLEEP / prt_speed/3 / 20);
			else
				Sleep(SLEEP/3 / 20);
		}
	}


	//下降
	for (int i = HEIGHT - top[dst - 'A']; i > 1; i--) {
		cct_showch(DST_X - n, DST_Y - i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		if (i != HEIGHT - top[dst - 'A']) {
			cct_showch(DST_X, DST_Y - i, ' ', COLOR_WHITE, COLOR_WHITE, 1);
		}
		cct_showch(DST_X - n, DST_Y - i + 1, ' ', n, n, 2 * n + 1);
		if (prt_speed)
			Sleep(SLEEP / prt_speed/20);
		else
			Sleep(SLEEP/20);
	}
	cct_setcolor();
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
void prt_stack_horizontal(int PRT_X, int PRT_Y, char src, char dst, int n)
{
	cct_gotoxy(PRT_X, PRT_Y + 4);
	cout << "第" << setw(4) << cnt
		<< "步(" << n << "#: "
		<< src << "-->" << dst << ")";
	prt_stack();
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
void prt_stack(void)
{
	//恢复默认颜色
	for (int j = 0; j < N_STACK; j++) {
		cout << char(j + 'A') << ":";
		for (int i = 0; i < top[j]; i++) {
			cout << setw(2) << stack[j][i];
		}
		cout << setw(2 * (N - top[j])) << "";
		cout << ' ';
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
void operate(char src, char dst)
{
	int pop = src - 'A';
	int push = dst - 'A';
	stack[push][top[push]++] = stack[pop][--top[pop]];
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：是否需要加参数？
  ***************************************************************************/
void pause(void)
{
	if (prt_speed == 0) {
		while (_getch() != '\r')
			;
	}
	else {
		Sleep(SLEEP / prt_speed);
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
void prt_option(int n, char src, char tmp, char dst, int PRT_X, int PRT_Y, int option)
{
	if (option == 1) {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	if (option == 2) {
		cout << "第" << setw(4) << cnt
			<< "步(" << n << "#: "
			<< src << "-->" << dst << ")"<<endl;
		
	}
	if (option == 3) {
		cout << "第" << setw(4) << cnt
			<< "步(" << n << "#: "
			<< src << "-->" << dst << ")";
		prt_stack();
		cout << endl;
	}
	if (option == 4 || option == 8) {
		prt_stack_horizontal(PRT_X, PRT_Y, src, dst, n);
		prt_stack_verticle(PRT_X, PRT_Y);
		operate(dst, src);
		if (option == 8)
			prt_move(src, dst, n);
		operate(src, dst);
		pause();
	}
}
  /***************************************************************************
	函数名称：
	功    能：汉诺塔递归函数
	输入参数：
	返 回 值：
	说    明：
	***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int PRT_X, int PRT_Y, int option)
{
	if (n == 0)
		return;
	hanoi(n - 1, src, dst, tmp, PRT_X, PRT_Y, option);
	cnt++;
	operate(src, dst);
	prt_option(n, src, tmp, dst, PRT_X, PRT_Y, option);
	hanoi(n - 1, tmp, src, dst, PRT_X, PRT_Y, option);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
void game(int PRT_X, int PRT_Y, char src, char dst, int n)
{
	cct_gotoxy(0, 0);
	cout << "从 "<<src<<" 移动到 "<<dst<<"，共 "<<n<<" 层";
	cct_gotoxy(0, PRT_Y + 6);
	cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
	int cnt = 0;
	while (1) {
		if (top[dst - 'A'] == n) {
			cct_gotoxy(0, PRT_Y + 7);
			cout << "游戏结束！！！";
			break;
		}
		char src, dst;
		while (1) {
			cct_gotoxy(61, PRT_Y + 6);
			char tmp[3];
			cin.getline(tmp, 3, '\n');
			src = tmp[0];
			dst = tmp[1];
			
			if (src >= 'a' && src <= 'c')
				src -= 32;
			if (dst >= 'a' && dst <= 'c')
				dst -= 32;
			if (src == 'Q'||src == 'q') {
				return;
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			
			else if ((src >= 'A' && src <= 'C')
				&& (dst >= 'A' && dst <= 'C') && (src != dst)) {
				if (0 == top[src - 'A']) {
					cout << endl << "源柱为空!";
					Sleep(500);
				}
				else if (0 != top[dst - 'A']
					&& stack[src - 'A'][top[src - 'A']-1] 
					> stack[dst - 'A'][top[dst - 'A'] - 1]) {
					cout << endl << "大盘压小盘，非法移动!";
					Sleep(500);

				}
				else {
					cct_showch(61, PRT_Y + 6, ' ', 0, 7, 100);
					cnt++;
					break;
				}
			}
			Sleep(SLEEP/5);
			cct_showch(61, PRT_Y + 6,' ',0,7,100);
			cct_showch(0, PRT_Y + 8, ' ', 0, 7, 50);
		}
		operate(src, dst);
		prt_stack_horizontal(PRT_X, PRT_Y, src, dst, cnt);
		prt_stack_verticle(PRT_X, PRT_Y);
		operate(dst, src);
		prt_move(src, dst, stack[src - 'A'][top[src - 'A'] - 1]);
		operate(src, dst);

	}
}