/*2152988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "5-b7.h"
using namespace std;

const int N = 10;//汉诺塔最大层数
const int N_STACK = 3;
//垂直打印汉诺塔位置（从分割线开始）
const int PRT_X = 10, PRT_Y = 12, PRT_LEN = 25;
const int SLEEP = 1000;

int cnt = 0; 
static int prt_speed;
static int prt_array;
int stack[N_STACK][N];
int top[N_STACK];

int stack_a[N], stack_b[N], stack_c[N];//记录塔的栈
int top_a, top_b, top_c;//栈顶指针（指向最后元素的下一个）
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
		while (_getch() != 13)
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
  说    明：如何始终打印title
  ***************************************************************************/
void prt_title(char src, char dst, int n)
{
	cct_gotoxy(0, 0);
	cout << "从 " << src << " 移动到 " << dst
		<< "，共 " << n << " 层，延时设置为 " << prt_speed
		<< "，" << (!prt_array ? "不" : "") << "显示内部数组值";
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
void prt_stack_verticle()
{
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
			cct_gotoxy(xa+set*(PRT_LEN - 5) / 2 - 1, PRT_Y - 1 - i);
			if (i < top[set]) {
				cout << setw(2) << stack[set][i];
			}
			else {
				cout << setw(2) << "";
			}
		}
	}
	
	/*for (int i = 0; i < N; i++) {
		cct_gotoxy(xb - 1, PRT_Y - 1 - i);
		if (i < top_b) {
			cout << setw(2) << stack_b[i];
		}
		else {
			cout << setw(2) << "";
		}
	}
	for (int i = 0; i < N; i++) {
		cct_gotoxy(xc - 1, PRT_Y - 1 - i);
		if (i < top_c) {
			cout << setw(2) << stack_c[i];
		}
		else {
			cout << setw(2) << "";
		}
	}*/
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
  说    明：
  ***************************************************************************/
void prt_stack(void) {
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
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 0)
		return;
	hanoi(n - 1, src, dst, tmp);

	cct_gotoxy(0, PRT_Y + 5);
	cout << "第" << setw(4) << ++cnt
		<< "步(" << n << "#: "
		<< src << "-->" << dst << ")";

	operate(src, dst);
	if (prt_array) {
		prt_stack();
		if (prt_speed == 0) {
			while (_getch() != 13)
				;
		}
	}

	prt_stack_verticle();
	pause();

	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp;
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
	cin.clear();
	cin.ignore(65536, '\n');

	for (int i = 0; i < n; i++) {
		stack[src - 'A'][i] = n - i;
	}
	top[src - 'A'] = n;


	cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
	cin >> prt_speed;
	cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
	cin >> prt_array;

	cin.clear();
	cin.ignore(65536, '\n');

	cct_cls();

	prt_title(src, dst, n);
	if (prt_array) {
		cct_gotoxy(0, PRT_Y + 5);
		cout << "初始:" << setw(16) << "";
		prt_stack();
		if (prt_speed == 0) {
			while (_getch() != 13)
				;
		}
	}
	prt_stack_verticle();
	pause();

	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);

	cct_gotoxy(0, PRT_Y + 15);
	system("pause");
	return 0;
}

/*
为什么只使用一次清屏？
*/