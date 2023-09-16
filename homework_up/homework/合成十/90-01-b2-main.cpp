/* 2153299 计拔 杨非凡 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include "cmd_console_tools.h"
#include "90-01-b2.h"
#include "common_menu_and_tools.h"
using namespace std;

/*
			 放main函数和menu函数和输入有关的函数
													   */


int main()
{
	srand((unsigned int)(time(0)));
	int row, column, target, score = 0;
	int i, j;
	char option = '\0';
	struct shuzu array;
	const int number_of_option = 10;
	const char possible_option[number_of_option] = { '1','2','3','4','5','6','7','8','9','0' };
	const char* content[number_of_option] =
	{ "命令行找出可合成的项并标记（非递归）",
		"命令行找出可合成的项并标记（递归）",
		"命令行完成一次合成（分步骤显示）",
		"命令行完整版（分步骤显示）",
		"伪图形界面显示初始数组（无分割线）",
		"伪图形界面显示初始数组（有分割线）",
		"伪图形界面下用箭头键/鼠标选择当前色块",
		"伪图形界面完成一次合成（分步骤）",
		"伪图形界面完整版（支持鼠标）",
		"退出" };

	for (;;) {
		//每次循环对数组以及变量进行相应初始化
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				array.number[i][j] = 0;
				array.sign[i][j] = '0';
			}
		}
		score = 0;

		cct_cls();
		option = common_menu(number_of_option, possible_option, content);
		//之后就是根据选项的不同来选择调用的函数
		if (option == '1') {
			int coordinate_x, coordinate_y;
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			output_array_number(&array, row, column, 0, 3, "当前数组：");//输出起始数组
			input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//输入指定合成的行和列
			search_no_recursion(array, row, column);//寻找相邻位置相同数
			output_array_sign(&array, row, column);//输出内部标记数组
			output_array_number(&array, row, column, 1, 3, "当前数组(不同色标识)：");//输出数组并突出显示被标记的数
			common_pause_end();
		}
		if (option == '2') {
			int coordinate_x, coordinate_y;
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			output_array_number(&array, row, column, 0, 3, "当前数组：");//输出起始数组
			input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//输入指定合成的行和列
			search_recursion(&array, row, column, coordinate_x, coordinate_y);//寻找相邻位置相同数
			output_array_sign(&array, row, column);//输出内部标记数组
			output_array_number(&array, row, column, 1, 3, "当前数组(不同色标识)：");//输出数组并突出显示被标记的数
			common_pause_end();
		}
		if (option == '3') {
			int coordinate_x, coordinate_y;//用来表示每次选择的位置的坐标
			int max_of_number = 3;//表示整个矩阵中的最大值
			char confirm;//决定确认合成，取消合成以及退出的变量
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			output_array_number(&array, row, column, 0, max_of_number, "当前数组：");//输出起始数组
			input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//输入指定合成的行和列
			search_recursion(&array, row, column, coordinate_x, coordinate_y);//寻找相邻位置相同数
			output_array_sign(&array, row, column);//输出内部标记数组
			output_array_number(&array, row, column, 1, max_of_number, "当前数组(不同色标识)：");//输出数组并突出显示被标记的数
			array_change_confirm(&confirm, coordinate_x, coordinate_y);//确认是否进行合成以及是否退出
			if (confirm == 'Y')
				array_change(&array, row, column, coordinate_x, coordinate_y, &score, &target, &max_of_number);//完成一次数组的变化

			common_pause_end();
		}
		if (option == '4') {
			int coordinate_x, coordinate_y;//用来表示每次选择的位置的坐标
			int max_of_number = 3;//表示整个矩阵中的最大值
			char confirm;//表示整个矩阵中的最大值
			int judge_of_end = 1;//表示游戏是否能继续进行的变量，为1则不能进行
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			for (;;) {
				initialization_array_sign(&array);//对字符数组进行初始化
				initial_judge(option, &array, row, column, max_of_number, &target, &judge_of_end);//判断游戏是否能继续进行
				if (judge_of_end)
					break;
				output_array_number(&array, row, column, 0, max_of_number, "当前数组：");//输出当前数组
				input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//输入指定合成的行和列
				search_recursion(&array, row, column, coordinate_x, coordinate_y);//寻找相邻位置相同数
				output_array_sign(&array, row, column);//输出内部标记数组
				output_array_number(&array, row, column, 1, max_of_number, "当前数组(不同色标识)：");//输出数组并突出显示被标记的数
				array_change_confirm(&confirm, coordinate_x, coordinate_y);//确认是否进行合成以及是否退出
				if (confirm == 'Y')//进行确认是否要进行合成
					;
				else if (confirm == 'N')
					continue;
				else
					break;
				array_change(&array, row, column, coordinate_x, coordinate_y, &score, &target, &max_of_number);//完成一次数组的变化
				wait_for_enter("本次合成结束，按回车键进行新一轮的合成...");
			}
			common_pause_end();
		}

		if (option == '5') {
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, 3, row, column);//给数字数组随机赋初值
			console_output_original_form(row, column, option);//打印初始的表格（无边框）
			console_output_original_array(&array, row, column, option);//打印初始的每个小方块
			cct_gotoxy(0, 4 + 3 * row);
			common_pause_end();
		}
		if (option == '6') {
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, 3, row, column);//给数字数组随机赋初值
			console_output_original_form(row, column, option);//打印初始的表格（有边框）
			console_output_original_array(&array, row, column, option);//打印初始的每个小方块
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}
		if (option == '7') {
			int max_of_number = 3;
			target = 3;
			int loop_q = 1;//来控制输入q的时候可以退出
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, 3, row, column);//给数字数组随机赋初值
			console_output_original_form(row, column, option);//打印初始的表格（有边框）
			console_output_original_array(&array, row, column, option);//打印初始的每个小方块
			choose_ketboard_and_mouse(option, &array, row, column, &max_of_number, &score, &target, &loop_q);//读入鼠标键盘的状态
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}
		if (option == '8') {
			int max_of_number = 3;
			target = 3;
			int loop_q = 1;//来控制输入q的时候可以退出
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, max_of_number, row, column);//给数字数组随机赋初值
			console_output_original_form(row, column, option);//打印初始的表格（有边框）
			console_output_original_array(&array, row, column, option);//打印初始的每个小方块
			choose_ketboard_and_mouse(option, &array, row, column, &max_of_number, &score, &target, &loop_q);//读入鼠标键盘的状态
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}
		if (option == '9') {
			int max_of_number = 3;
			int judge_of_end = 1;
			int loop_q = 1;//来控制输入q的时候可以直退出本选项
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, max_of_number, row, column);//给数字数组随机赋初值
			console_output_original_form(row, column, option);//打印初始的表格（有边框）
			console_output_original_array(&array, row, column, option);//打印初始的每个小方块
			//不断循坏读取鼠标的状态，当需要停止的时候自动退出
			for (; loop_q;) {
				initial_judge(option, &array, row, column, max_of_number, &target, &judge_of_end);
				if (judge_of_end)//如果判断没有可以合成的值了，就结束游戏
					break;

				initialization_array_sign(&array);//对字符型数组进行初始化
				choose_ketboard_and_mouse(option, &array, row, column, &max_of_number, &score, &target, &loop_q);//读入鼠标键盘的状态
			}
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}

		//option为0则退出
		if (option == '0') {
			int x, y;
			char pause;
			cct_getxy(x, y);
			cct_showstr(0, y + 4, "请按任意键继续...");
			pause = _getch();
			break;
		}
	}
	return 0;
}