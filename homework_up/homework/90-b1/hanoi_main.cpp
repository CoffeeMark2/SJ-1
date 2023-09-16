/* 2152988 杨恺铭 计科 */

/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		int option = menu() - '0';
		if (option >= 1 && option <= 3) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp);
			stack_init(src, n);
			int PRT_X = 0, PRT_Y = 25;
			hanoi(n, src, tmp, dst, PRT_X, PRT_Y, option);
			cout <<endl << "按回车键继续...";

			while (_getch() != '\r')
				;

			cct_cls();
		}
		else if (option == 4) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 1);
			int PRT_X = 5, PRT_Y = 15;
			stack_init(src, n);
			cct_cls();
			prt_title(src, dst, n);
			prt_init_stack(PRT_X, PRT_Y);
			prt_stack_verticle(PRT_X, PRT_Y);
			pause();
			hanoi(n, src, tmp, dst, PRT_X, PRT_Y, option);
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 5) {
			cct_cls();
			prt_column();
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 6) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp);

			cct_cls();
			prt_column();
			prt_init_column(src, n);
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 7) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 0);
			cct_cls();
			prt_column();
			prt_init_column(src, n);
			stack_init(src, n);
			Sleep(500);
			prt_move(src, dst, 1);
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 8) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 1);
			int PRT_X = 0, PRT_Y = 25;
			stack_init(src, n);
			cct_cls();
			prt_init_stack(PRT_X, PRT_Y);
			prt_stack_verticle(PRT_X, PRT_Y);
			prt_column();
			prt_init_column(src, n);
			pause();
			hanoi(n, src, tmp, dst, PRT_X, PRT_Y, option);
			to_be_continued(NULL);
			stack_clear();

		}
		else if (option == 9) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 0);
			int PRT_X = 0, PRT_Y = 25;
			stack_init(src, n);
			cct_cls();
			prt_init_stack(PRT_X, PRT_Y);
			prt_stack_verticle(PRT_X, PRT_Y);
			prt_column();
			prt_init_column(src, n);
			Sleep(500);
			game(PRT_X, PRT_Y, src, dst, n);
			to_be_continued(NULL);
			stack_clear();

		}
		else if (option == 0) {
			break;
		}
		else {
			cct_cls();
			cout << "option error" << endl;
		}
		stack_clear();
	}

	return 0;
}
