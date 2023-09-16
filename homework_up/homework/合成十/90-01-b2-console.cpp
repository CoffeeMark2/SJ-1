/* 2153299 计拔 杨非凡 */

//放伪图形实现的函数
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include "cmd_console_tools.h"
#include "90-01-b2.h"
using namespace std;

/*
			 放伪图形界面相关的函数
										 */


										 /**************************************************************************
										 函数名称：display
										  功    能:/*根据canshu的不同对(coordinate_x, coordinate_y)处的方格进行不同的显示
										  canshu可以取:
										  1         进行前景色为白色的突出显示
										  0         进行前景色为黑色的普通显示
										  -1        进行纯白色的覆盖
										 输入参数：
										 返 回 值：无
										 说    明：不适用于选项为5的情况，因为坐标的计算会不同
										 ***************************************************************************/
void display(int canshu, struct shuzu* array, int coordinate_x, int coordinate_y)
{

	if (canshu == 1) {//进行突出显示,前景色为白色
		cct_setcolor(array->number[coordinate_x][coordinate_y], 15);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1);
		cout << "┌─┐";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x);

		if (array->number[coordinate_x][coordinate_y] < 10)
			cout << "│" << array->number[coordinate_x][coordinate_y] << " │";
		else
			cout << "│" << array->number[coordinate_x][coordinate_y] << "│";

		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1);
		cout << "└─┘";
		cct_setcolor(0, 15);
	}

	if (canshu == 0) {//进行普通显示，前景色为黑色
		cct_setcolor(array->number[coordinate_x][coordinate_y], 0);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1);
		cout << "┌─┐";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x);

		if (array->number[coordinate_x][coordinate_y] < 10)
			cout << "│" << array->number[coordinate_x][coordinate_y] << " │";
		else
			cout << "│" << array->number[coordinate_x][coordinate_y] << "│";

		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1);
		cout << "└─┘";
		cct_setcolor(0, 15);
	}

	if (canshu == -1) {//用于合并方格时让其它方格消失，用纯白色覆盖其它被合并的方格
		cct_setcolor(15, 15);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1);
		cout << "      ";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x);
		cout << "      ";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1);
		cout << "      ";
		cct_setcolor(0, 15);
	}
}


/**************************************************************************
函数名称：flash
功    能:用来模拟方块合成时，被选中的方块闪烁的效果
输入参数：
返 回 值：无
说    明：
***************************************************************************/
void flash(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y)
{//用来模拟方块合成时，被选中的方块闪烁的效果
	int i = 1;
	for (i = 1; i <= 10; i++) {
		//突出显示和普通显示交替进行来模拟闪烁的效果
		display(1, array, coordinate_x, coordinate_y);
		Sleep(50);
		display(0, array, coordinate_x, coordinate_y);
		Sleep(50);
	}
	Sleep(300);
}


/**************************************************************************
函数名称：console_output_original_array
功    能:打印初始的每个小方块
输入参数：
返 回 值：
说    明：
***************************************************************************/
void console_output_original_array(struct shuzu* array, int row, int column, char option)
{
	int i, j;
	//选项为5，没有边框的情况下要单独处理
	if (option == '5') {
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= column; j++) {
				int x, y;
				x = 6 * j - 2;
				y = 3 * i;
				cct_setcolor(array->number[i][j], 0);
				cct_gotoxy(x, y);
				cout << "┌─┐";
				cct_gotoxy(x, y + 1);
				cout << "│" << array->number[i][j] << " │";
				cct_gotoxy(x, y + 2);
				cout << "└─┘";
				cct_setcolor(0, 15);
			}
		}
	}

	else {
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= column; j++) {
				int x, y;
				x = 8 * j - 4;
				y = 4 * i - 1;

				display(0, array, i, j);
			}
		}
	}
}




/**************************************************************************
函数名称： console_output_original_form
功    能:打印初始的表格
输入参数：
返 回 值：
说    明：
***************************************************************************/
void console_output_original_form(int row, int column, char option)
{
	int cols, lines, buffer_cols, buffer_lines;
	int i, j, k;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);

	if (option == '5') {//对应的是option=5的情况没有横线的表格
		cols = column * 6 + 7;
		lines = row * 3 + 8;
		cct_setconsoleborder(cols, lines, buffer_cols, buffer_lines);
		cct_cls();
		cout << "屏幕当前设置为：" << lines << "行" << cols << "列" << endl;

		//先打印一个白色底盘的表格
		cout << " ";
		for (j = 1; j <= column; j++) {
			cout << "     " << j - 1;
		}
		cout << endl;

		//打印上边框
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "┌";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "───";
			Sleep(1);
		}
		cout << "┐";
		Sleep(1);
		cout << endl;


		//打印中间的内容
		for (i = 1; i <= row; i++) {
			for (k = 1; k <= 3; k++) {
				cct_setcolor(0, 15);
				if (k == 2)
					cout << char('A' + i - 1) << " ";
				else
					cout << "  ";

				cct_setcolor(15, 0);
				cout << "│";
				Sleep(1);
				for (j = 1; j <= column; j++) {
					cout << "      ";
					Sleep(1);
				}
				cout << "│";
				Sleep(1);
				cout << endl;
			}
		}

		//打印下边框
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "└";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "───";
			Sleep(1);
		}
		cout << "┘";
		Sleep(1);
		cout << endl;
		cct_setcolor(0, 15);
	}

	else {//对应的是option=6,7,8,9时的有横线的表格
		cols = column * 8 + 5;
		lines = row * 4 + 7;
		cct_setconsoleborder(cols, lines, buffer_cols, buffer_lines);
		cct_cls();
		cout << "屏幕当前设置为：" << lines << "行" << cols << "列" << endl;
		//先打印一个白色底盘的表格
		for (j = 1; j <= column; j++) {
			if (j == 1)
				cout << "      " << j - 1;
			else
				cout << "       " << j - 1;
		}
		cout << endl;

		//打印上边框
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "┌";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "───";
			if (j != column)
				cout << "┬";
			Sleep(1);
		}
		cout << "┐";
		Sleep(1);
		cout << endl;

		//打印中间内容
		for (i = 1; i <= row; i++) {
			for (k = 1; k <= 3; k++) {
				cct_setcolor(0, 15);
				if (k == 2)
					cout << char('A' + i - 1) << " ";
				else
					cout << "  ";

				cct_setcolor(15, 0);
				cout << "│";
				Sleep(1);
				for (j = 1; j <= column; j++) {
					cout << "      ";
					if (j != column)
						cout << "│";
					Sleep(1);
				}
				cout << "│";
				Sleep(1);
				cout << endl;
			}

			if (i != row) {
				cct_setcolor(0, 15);
				cout << "  ";
				cct_setcolor(15, 0);
				cout << "├";
				Sleep(1);
				for (j = 1; j <= column; j++) {
					cout << "───";
					if (j != column)
						cout << "┼";
					Sleep(1);
				}
				cout << "┤";
				Sleep(1);
				cout << endl;
			}
		}


		//打印下边框
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "└";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "───";
			if (j != column)
				cout << "┴";
			Sleep(1);
		}
		cout << "┘";
		Sleep(1);
		cout << endl;
		cct_setcolor(0, 15);
	}
}



/**************************************************************************
函数名称：mouse_area_judge
功    能:判断在选择小方块的时候鼠标的位置是否合法，即判断光标是否在某个小方格内部
输入参数：
返 回 值：
说    明：
***************************************************************************/
int mouse_area_judge(int row, int column, int MX, int MY, int* x, int* y)
{
	int mouse_area_X = 0, mouse_area_Y = 0;
	int i, j;
	for (i = 1; i <= row; i++) {
		if (MY >= 4 * i - 1 && MY <= 4 * i + 1) {
			mouse_area_Y = 1;
			*x = i;
		}
	}

	for (j = 1; j <= column; j++) {
		if (MX >= 8 * j - 4 && MX <= 8 * j + 1) {
			mouse_area_X = 1;
			*y = j;
		}
	}

	return (mouse_area_X * mouse_area_Y);

}



/**************************************************************************
函数名称：confirm
功    能:通过鼠标左键或者回车键来进行确定
输入参数：
返 回 值：
说    明：
***************************************************************************/
void console_confirm(const char* const prompt, int row)
{
	cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
	cct_gotoxy(0, 3 + 4 * row);
	cout << prompt;
	int loop = 1;
	for (; loop;) {
		int MX = 0, MY = 0, MAction = 0, keycode1 = 0, keycode2 = 0;
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);//读取鼠标和键盘上的按键
		if (MAction == 2 || keycode1 == 13)
			loop = 0;
	}
}


/**************************************************************************
函数名称：move_2
功    能:图形在移动过程中的动画展示
输入参数：
返 回 值：
说    明：
***************************************************************************/
void move_2(struct shuzu* array, int coordinate_x, int coordinate_y)
{
	//通过动画演示小方格从上到下，中间穿过横线的过程
	int i = 0;
	for (i = 1; i <= 4; i++) {//通过连续的四次擦去在打印模拟动画效果
		cct_setcolor(array->number[coordinate_x][coordinate_y], 0);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1 + i);
		cout << "┌─┐";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + i);
		cout << "│" << array->number[coordinate_x][coordinate_y] << " │";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1 + i);
		cout << "└─┘";

		cct_setcolor(15, 0);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 2 + i);
		if (i == 4)
			cout << "───";//把抹去的横线再次打印出来
		else
			cout << "      ";
		Sleep(10);
		cct_setcolor(0, 15);
	}
}


/**************************************************************************
函数名称：move_1
功    能:图形在移动过程中的动画展示
输入参数：
返 回 值：
说    明：
***************************************************************************/
void move1(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y)
{
	int i, j, k, m;
	int t1;
	char t2;


	//先从左到右，在从上到下，按照这个顺序让方块下落，能够保证图形变换看起来自然流畅
	for (j = 1; j <= column; j++)
		for (i = row - 1; i >= 1; i--) {
			k = i;
			for (m = 1; m <= row; m++) {
				if (k <= row - 1 && array->sign[k][j] != '*' && array->sign[k + 1][j] == '*') {

					//进行伪图形的变换
					move_2(array, k, j);

					//进行内部数组的变换
					t2 = array->sign[k + 1][j];
					array->sign[k + 1][j] = array->sign[k][j];
					array->sign[k][j] = t2;
					t1 = array->number[k + 1][j];
					array->number[k + 1][j] = array->number[k][j];
					array->number[k][j] = t1;
					k++;
				}
				else
					break;
			}
		}
}




/**************************************************************************
函数名称：choose_ketboard_and_mouse
功    能:读取鼠标和键盘上的按键
输入参数：
返 回 值：
说    明：
***************************************************************************/
void choose_ketboard_and_mouse(char option, struct shuzu* array, int row, int column, int* max_of_number, int* score, int* target, int* loop_q)
{
	int MX, MY, MAction, keycode1, keycode2;
	int coordinate_x = 1, coordinate_y = 1;
	int loop = 1;//loop用来控制循环是否终止
	cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
	cct_gotoxy(0, 3 + 4 * row);
	cout << "箭头键/鼠标移动，回车键/鼠标左键选择并结束";

	display(1, array, coordinate_x, coordinate_y);//先将左上角的方格突出显示

	cct_enable_mouse();
	cct_setcursor(3);
	for (; loop == 1;) {
		MX = 0, MY = 0, MAction = 0, keycode1 = 0, keycode2 = 0;
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);//读取鼠标和键盘上的按键
		display_of_choose(option, &loop, array, &coordinate_x, &coordinate_y, row, column, MX, MY, MAction, keycode1, keycode2);
		if (keycode1 == 'q' || keycode1 == 'Q') {
			loop = -1;
			*loop_q = 0;
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		}
	}

	if ((option == '8' || option == '9') && loop != -1) {
		int one_step_score = 0;
		int i, j;
		int a = array->number[coordinate_x][coordinate_y];

		//进行数值的合成，并计算每一步的得分和总得分
		for (i = 1; i <= row; i++)
			for (j = 1; j <= column; j++)
				if (array->sign[i][j] == '*') {
					if (i == coordinate_x && j == coordinate_y) {
						array->number[i][j]++;
						display(1, array, i, j);
					}
					else {
						array->number[i][j] = 0;
						display(-1, array, i, j);
						Sleep(10);
					}
					one_step_score += 3 * a;
				}
		*score += one_step_score;
		*max_of_number = search_max_of_number(array, row, column);//找数字数组中的最大值
		cct_gotoxy(0, 0);
		cout << "本次得分: " << one_step_score << " 总分: " << *score << " 合成目标: " << *target;
		cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		cct_gotoxy(0, 3 + 4 * row);

		flash(array, row, column, coordinate_x, coordinate_y);//合成的效果展示


		//选项为8的时候要分步骤进行，中间要有多次暂停
		if (option == '8')
			console_confirm("合成完成，回车键/单击左键下落0", row);

		array->sign[coordinate_x][coordinate_y] = '0';
		move1(array, row, column, coordinate_x, coordinate_y);//进行非0下落的内部数组变化以及伪图形变化
		display(0, array, coordinate_x, coordinate_y);
		if (option == '8')
			console_confirm("下落0完成，回车键/单击左键填充新值", row);

		random_number_generation(array, *max_of_number, row, column);

		for (i = 1; i <= row; i++)
			for (j = 1; j <= column; j++)
				if (array->sign[i][j] == '*') {
					Sleep(20);
					display(0, array, i, j);
				}
		if (option == '8') {
			console_confirm("本次合成结束，按c/单击左键进行新一次的合成", row);
			cct_gotoxy(0, 3 + 4 * row);
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		}
	}
	cct_disable_mouse();
	cct_setcursor(2);
}



/**************************************************************************
函数名称：display_of_choose
功    能: 用来突出显示鼠标和键盘所选中的方块
***************************************************************************/
void display_of_choose(char option, int* loop, struct shuzu* array, int* coordinate_x, int* coordinate_y,
	int row, int column, int MX, int MY, int MAction, int keycode1, int keycode2)
{
	int x = *coordinate_x, y = *coordinate_y;
	int mouse_area = 0;
	if (keycode1 == 224) {//对应键盘输入上下左右箭头的情况
		//其中分支结构用来处理边界环绕
		if (keycode2 == 72) {
			if (x == 1)
				x = row;
			else
				x--;
		}
		if (keycode2 == 80)
			x = x % column + 1;
		if (keycode2 == 75) {
			if (y == 1)
				y = column;
			else
				y--;
		}
		if (keycode2 == 77)
			y = y % row + 1;

		display(0, array, *coordinate_x, *coordinate_y);

		display(1, array, x, y);

		*coordinate_x = x;
		*coordinate_y = y;
		cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		cct_gotoxy(0, 3 + 4 * row);
		cout << "[当前键盘] " << char('A' + *coordinate_x - 1) << "行" << *coordinate_y - 1 << "列                          ";
	}


	else if (MAction == 1) {//对应鼠标移动
		mouse_area = mouse_area_judge(row, column, MX, MY, &x, &y);
		if (mouse_area) {//判断鼠标是否在合理区域内
			display(0, array, *coordinate_x, *coordinate_y);

			display(1, array, x, y);

			*coordinate_x = x;
			*coordinate_y = y;
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
			cct_gotoxy(0, 3 + 4 * row);
			cout << "[当前鼠标] " << char('A' + *coordinate_x - 1) << "行" << *coordinate_y - 1 << "列                          ";
		}
		else {
			display(0, array, *coordinate_x, *coordinate_y);
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
			cct_gotoxy(0, 3 + 4 * row);
			cout << "[当前鼠标] 位置非法                             ";
		}
	}

	else if (keycode1 == 13) {
		//停止读入鼠标键盘的循环并跳出
		if (option == '7') {
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
			cct_gotoxy(0, 3 + 4 * row);
			cout << "选中了" << char('A' + *coordinate_x - 1) << "行" << *coordinate_y - 1 << "列                              ";
			*loop = 0;
			return;
		}
		else {//选项为8,9的时候要进行错误判断以及选择的确认
			if (!coordinate_judge(array, row, column, *coordinate_x, *coordinate_y, 0)) {
				cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
				cct_gotoxy(0, 3 + 4 * row);
				cout << "周围无相同值，箭头键/鼠标左键移动";
			}
			else {
				cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
				cct_gotoxy(0, 3 + 4 * row);
				cout << "箭头键/鼠标键移动取消当前选择,回车键/单击左键合成";
				display_of_choose2(array, row, column, *coordinate_x, *coordinate_y);
				int MX_ = 0, MY_ = 0, MAction_ = 0, keycode1_ = 0, keycode2_ = 0;
				cct_read_keyboard_and_mouse(MX_, MY_, MAction_, keycode1_, keycode2_);//读取鼠标和键盘上的按键
				//只有鼠标左键和回车键才能进行确认
				if (keycode1_ == 13 || (MAction_ == 2 && mouse_area_judge(row, column, MX, MY, &x, &y))) {
					*loop = 0;
				}
				else {//取消对选中的方块的突出显示
					int u, v;
					for (u = 1; u <= row; u++)
						for (v = 1; v <= column; v++)
							if (array->sign[u][v] == '*')
								display(0, array, u, v);
					initialization_array_sign(array);
					display_of_choose(option, loop, array, coordinate_x, coordinate_y, row, column, MX_, MY_, MAction, keycode1_, keycode2_);
				}
			}
		}
	}
	else if (MAction == 2) {//对应鼠标左键
		mouse_area = mouse_area_judge(row, column, MX, MY, &x, &y);//要判断鼠标的区域
		if (mouse_area == 1) {
			if (option == '7') {
				cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
				cct_gotoxy(0, 3 + 4 * row);
				cout << "选中了" << char('A' + *coordinate_x - 1) << "行" << *coordinate_y - 1 << "列                               ";
				*loop = 0;
				return;
			}
			else {//选项为8,9的时候要进行错误判断以及选择的确认
				if (!coordinate_judge(array, row, column, *coordinate_x, *coordinate_y, 0)) {
					cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
					cct_gotoxy(0, 3 + 4 * row);
					cout << "周围无相同值，箭头键/鼠标左键移动";
				}
				else {
					cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
					cct_gotoxy(0, 3 + 4 * row);
					cout << "箭头键/鼠标键移动取消当前选择,回车键/单击左键合成";
					display_of_choose2(array, row, column, *coordinate_x, *coordinate_y);
					int MX_ = 0, MY_ = 0, MAction_ = 0, keycode1_ = 0, keycode2_ = 0;
					cct_read_keyboard_and_mouse(MX_, MY_, MAction_, keycode1_, keycode2_);//读取鼠标和键盘上的按键
					//只有鼠标左键和回车键才能进行确认
					if (keycode1_ == 13 || (MAction_ == 2 && mouse_area_judge(row, column, MX, MY, &x, &y))) {
						*loop = 0;
					}
					else {//取消对选中的方块的突出显示
						int u, v;
						for (u = 1; u <= row; u++)
							for (v = 1; v <= column; v++)
								if (array->sign[u][v] == '*')
									display(0, array, u, v);
						initialization_array_sign(array);
						display_of_choose(option, loop, array, coordinate_x, coordinate_y, row, column, MX_, MY_, MAction, keycode1_, keycode2_);
					}
				}
			}
		}
	}
}


//用于突出显示和所选中的方块一起合成的方块
void display_of_choose2(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y)
{
	int i, j;
	search_recursion(array, row, column, coordinate_x, coordinate_y);
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->sign[i][j] == '*') {
				display(1, array, i, j);
			}
		}
	}
}
