/*2152988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量和静态局部变量
   ----------------------------------------------------------------------------------- */

void print_line_ascending(char c);
void print_line_descending(char c);
/***************************************************************************
  函数名称：
  功    能：正序从c输出字母序列
  输入参数：c，最大字母
  返 回 值：
  说    明：大写字母
***************************************************************************/
void print_line_ascending1(char c, char max_c) {
	if (c > max_c) {
		return;
	}
	cout << c;
	print_line_ascending1(c + 1, max_c);

}
/***************************************************************************
  函数名称：
  功    能：逆序从c输出字母序列
  输入参数：c，最大字母
  返 回 值：
  说    明：大写字母
***************************************************************************/
void print_line_descending1(char c, char max_c) {
	if (c > max_c) {
		return;
	}
	print_line_descending1(c + 1, max_c);
	cout << c;

}
/***************************************************************************
  函数名称：
  功    能：打印字母塔，参数1为正序，0为逆序
  输入参数：
  返 回 值：
  说    明：字母为大写
***************************************************************************/
void print_tower(char c, char max_c, int i)
{
	if (i) {
		if (c < 'A') {
			return;
		}
		print_tower(c - 1, max_c, i);
		cout << setfill(' ') << setw(max_c - c) << "";
		print_line_descending(c);
		cout << "A";
		print_line_ascending(c);
		cout << endl;
	}
	else {
		if (c > max_c) {
			return;
		}
		cout << setfill(' ') << setw(c - 'A') << "";
		print_line_ascending1(c, max_c - 1);
		cout << max_c;
		print_line_descending1(c, max_c - 1);
		cout << endl;
		print_tower(c + 1, max_c, i);
	}
}
/***************************************************************************
  函数名称：
  功    能：正序输出字母序列
  输入参数：最大字母
  返 回 值：
  说    明：大写字母
***************************************************************************/
void print_line_ascending(char c) {
	if (c < 'B') {
		return;
	}
	print_line_ascending(c - 1);
	cout << c;
}

/***************************************************************************
  函数名称：
  功    能：逆序输出字母序列
  输入参数：最大字母
  返 回 值：
  说    明：大写字母
***************************************************************************/
void print_line_descending(char c) {
	if (c < 'B') {
		return;
	}
	cout << c;
	print_line_descending(c - 1);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1)
		<< '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1)
		<< '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, end_ch, 1);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1)
		<< '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1)
		<< '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, 0);
	cout << endl;

	return 0;
}