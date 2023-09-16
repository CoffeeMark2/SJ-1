/* 2153299 计拔 杨非凡 */

//放数组和伪图形界面共用的工具函数
#include <iostream>
#include <iomanip>
#include <conio.h>

#include "cmd_console_tools.h"
#include "common_menu_and_tools.h"
#include "90-01-b2.h"
using namespace std;


//新写的函数，tj_str类中没有的
/***************************************************************************
函数名称：tj_charupr
功    能：将小写字母转成大写字母
输入参数：
返 回 值：
说    明：
***************************************************************************/
void tj_charupr(char* a)
{
	if (*a >= 'a' && *a <= 'z')
		*a = *a - 32;
}


/***************************************************************************
函数名称：wait_for_enter
功    能：输出给定的字符串，并要求按回车键才能继续
输入参数：
返 回 值：
说    明：
***************************************************************************/
void wait_for_enter(const char* const prompt)
{
	if ((prompt == NULL) || (strlen(prompt) == 0))
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt;

	while (_getch() != '\r')
		;
}

/***************************************************************************
函数名称：input_row_and_column
功    能：根据选项来输入行，列，并判断是否输入合成目标
输入参数：
返 回 值：
说    明：
***************************************************************************/
void input_row_and_column(int* row, int* column, int* target, char option)
{
	//输入行数
	for (;;) {
		cout << "请输入行数(5-8)：" << endl;
		cin >> *row;
		if (cin.good()) {
			if (*row >= 5 && *row <= 8) {
				cin.ignore(0xffffffff, '\n');
				break;
			}
			else {
				cin.ignore(0xffffffff, '\n');
			}
		}
		else {
			cin.clear();
			cin.ignore(0xffffffff, '\n');
		}
	}

	//输入列
	for (;;) {
		cout << "请输入列数(5-10)：" << endl;
		cin >> *column;
		if (cin.good()) {
			if (*column >= 5 && *column <= 10) {
				cin.ignore(0xffffffff, '\n');
				break;
			}
			else {
				cin.ignore(0xffffffff, '\n');
			}
		}
		else {
			cin.clear();
			cin.ignore(0xffffffff, '\n');
		}
	}

	//只有部分选项需要输入合成目标
	if (option == '3' || option == '4' || option == '9') {
		for (;;) {
			cout << "请输入合成目标(5-20)：" << endl;
			cin >> *target;
			if (cin.good()) {
				if (*target >= 5 && *target <= 20) {
					cin.ignore(0xffffffff, '\n');
					break;
				}
				else {
					cin.ignore(0xffffffff, '\n');
				}
			}
			else {
				cin.clear();
				cin.ignore(0xffffffff, '\n');
			}
		}
	}
}