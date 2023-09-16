/* 2153299 计拔 杨非凡 */
#include <iostream>
#include <iomanip>
#include <conio.h>

#include "cmd_console_tools.h"
#include "common_menu_and_tools.h"
#include "90-01-b2.h"
using namespace std;

/*
			 放内部数组实现的函数
										 */


/***************************************************************************
函数名称：random_number_generation
功    能：根据目前矩阵中的最大值来给0处的值进行随机赋值
输入参数：max_of_number -> 目前矩阵中的最大值.row->行数.column->列数
 返 回 值：无
***************************************************************************/
void random_number_generation(struct shuzu* array, int max_of_number, int row, int column)
{
	int a = 0, b;
	int i, j, k;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->number[i][j] == 0) {

				/*下面根据max_of_number的值来决定返回值a所对用的不同值的概率
				其中引入了b，b限制为某个区间上的随机值，之后根据对区间的划分来决定a*/
				//最大值为3
				if (max_of_number == 3)
					a = rand() % 3 + 1;
				//最大值为4
				else if (max_of_number == 4) {
					b = rand() % 10 + 1;
					for (k = 1; k <= 3; k++) {
						if (b >= 3 * k - 2 && b <= 3 * k) {
							a = k;
							break;
						}
					}
					if (b == 10)
						a = 4;
				}
				//最大值为5
				else if (max_of_number == 5) {
					b = rand() % 100 + 1;
					for (k = 1; k <= 3; k++) {
						if (b >= 1 + (k - 1) * 25 && b <= k * 25) {
							a = k;
							break;
						}
					}
					if (b >= 76 && b <= 90)
						a = 4;
					if (b >= 91 && b <= 100)
						a = 5;
				}
				//最大值为6
				else if (max_of_number == 6) {
					b = rand() % 100 + 1;
					for (k = 1; k <= 4; k++) {
						if (b >= 1 + (k - 1) * 20 && b <= k * 20) {
							a = k;
							break;
						}
					}
					if (b >= 81 && b <= 95)
						a = 5;
					if (b >= 96 && b <= 100)
						a = 6;
				}
				//最大值大于6
				else {
					b = rand() % 100 + 1;
					if (b >= 96 && b <= 100)
						a = max_of_number;

					else if (b >= 91 && b <= 95)
						a = max_of_number - 1;

					else if (b >= 81 && b <= 90)
						a = max_of_number - 2;

					else {
						for (k = 1; k <= max_of_number - 3; k++) {
							if (b >= 1 + 80 * (k - 1) / (max_of_number - 3) && b <= 80 * k / (max_of_number / 3)) {
								a = k;
								break;
							}
						}
					}
				}
				array->number[i][j] = a;
			}
		}
	}
}
/**************************************************************************
函数名称：coordinate_judge
功    能：判断一个数四周有无相同的数
输入参数：row->行数.column->列数
返 回 值：周围有相同值返回1，没有返回0
说    明：
***************************************************************************/
bool coordinate_judge(struct shuzu* array, int row, int column, int x, int y, int canshu)
{
	bool coordinate_judge = 0;
	//判断周围四个数中有没有相同的
	coordinate_judge = array->number[x][y] + canshu == array->number[x - 1][y]
		|| array->number[x][y] + canshu == array->number[x + 1][y]
		|| array->number[x][y] + canshu == array->number[x][y - 1]
		|| array->number[x][y] + canshu == array->number[x][y + 1];

	return coordinate_judge;
}


/**************************************************************************
函数名称：input_coordinate
功    能：
输入参数：row->行数.column->列数
返 回 值：无
说    明：
***************************************************************************/
void input_coordinate(struct shuzu* array, int row, int column, int* coordinate_x, int* coordinate_y)
{
	int x, y;
	char coordinate[30];
	for (;;) {
		cout << "请以字母+数字形式[例如：c2]输入矩阵坐标：";
		cct_getxy(x, y);
		cin.getline(coordinate, 30, '\n');
		tj_strupr(coordinate);

		if (!coordinate) {//排除空字符串的情况
			cout << "输入错误，请重新输入";
			cct_showch(x, y, ' ', 0, 7, 30);
			cct_gotoxy(0, y);
			continue;
		}

		//判断输入的位置周围四个数中是否有和它相同的
		if ((coordinate[0] >= 'A' && coordinate[0] <= 'A' + row - 1) && (coordinate[1] >= '0' && coordinate[1] <= '0' + column - 1)) {
			int x1, y1;
			x1 = coordinate[0] - 'A' + 1;//转换为具体的数字 几行几列
			y1 = coordinate[1] - '0' + 1;
			cout << "输入为" << coordinate[0] << "行" << coordinate[1] << "列" << endl;
			if (coordinate_judge(array, row, column, x1, y1, 0)) {
				array->sign[x1][y1] = '*';
				*coordinate_x = x1;
				*coordinate_y = y1;
				break;
			}

			//错误输入提示
			else {
				cout << "输入的矩阵坐标处无连续相同值，请重新输入" << endl;
			}
		}
		//错误输入提示
		else {
			cout << "输入错误，请重新输入";
			cct_showch(x, y, ' ', 0, 7, 30);
			cct_gotoxy(0, y);
		}
	}
}


/***************************************************************************
函数名称：output_array_number
功    能：输出数字矩阵
输入参数：row->行数.column->列数
返 回 值：
说    明：canshu用于参数控制，为0时会给矩阵中为0的数进行随机赋值在输出
							  为1时直接输出数字矩阵
***************************************************************************/
void output_array_number(struct shuzu* array, int row, int column, int canshu, int max_of_number, const char* const prompt)
{
	if ((prompt == NULL) || (strlen(prompt) == 0))
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt;
	cout << endl;


	int i, j, k;//循环变量
	//只有在array.number[i][j]没有初始值的时候才执行此步
	if (canshu == 0) {
		random_number_generation(array, max_of_number, row, column);
	}

	//开始：对数组的输出
	cout << "  |";
	for (j = 1; j <= column; j++) {
		cout << "  " << j - 1;
	}
	cout << endl;
	k = 3 * column;
	cout << "--+" << setfill('-') << setw(k) << "-" << endl;//打印表格边界线
	for (i = 1; i <= row; i++) {
		cout << (char)('A' - 1 + i) << " |";//打印表格边界线
		for (j = 1; j <= column; j++) {
			if (array->sign[i][j] == '*') {
				cout << "  ";
				cct_setcolor(14, 0);
				cout << array->number[i][j];
				cct_setcolor(0, 15);
			}
			else
				cout << "  " << array->number[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//结束：对数组的输出
}


/***************************************************************************
函数名称：output_sign
功    能：输出字符矩阵
输入参数：row->行数.column->列数
返 回 值：
说    明：
***************************************************************************/
void output_array_sign(struct shuzu* array, int row, int column)
{
	int i, j, k;

	cout << "查找结果数组：" << endl;

	//开始：对数组的输出
	cout << "  |";
	for (j = 1; j <= column; j++) {
		cout << "  " << j - 1;
	}
	cout << endl;
	k = 3 * column;
	cout << "--+-" << setfill('-') << setw(k) << "-" << endl;//打印表格边界线
	for (i = 1; i <= row; i++) {
		cout << (char)('A' - 1 + i) << " |";//打印表格边界线
		for (j = 1; j <= column; j++) {
			cout << "  " << array->sign[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//结束：对数组的输出
}

/***************************************************************************
函数名称：search_no_recursion
功    能：用非递归的方式寻找和中心数一起合并的数，并将它们标记
输入参数：row->行数.column->列数
返 回 值：
说    明：
***************************************************************************/
void search_no_recursion(struct shuzu& array, int row, int column)
{
	int i, j, k;
	for (k = 20; k >= 0; k--) {//由于矩阵中任意两个数的横坐标，纵坐标的差都不会超过10，至多20次就能够search整个矩阵
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= column; j++) {
				if (array.sign[i][j] == '*') {
					//每次对有标记的数字进行四周的寻找
					//把一个数周围和它相同的四个数也都做上标记
					if (array.number[i - 1][j] == array.number[i][j])
						array.sign[i - 1][j] = '*';
					if (array.number[i + 1][j] == array.number[i][j])
						array.sign[i + 1][j] = '*';
					if (array.number[i][j - 1] == array.number[i][j])
						array.sign[i][j - 1] = '*';
					if (array.number[i][j + 1] == array.number[i][j])
						array.sign[i][j + 1] = '*';
				}
			}
		}
	}
}


/***************************************************************************
函数名称：search_recursion
功    能：用递归的方式寻找和中心数一起合并的数,并将它们标记
输入参数：row->行数.column->列数
返 回 值：
说    明：
***************************************************************************/
void search_recursion(struct shuzu* array, int row, int column, int x, int y)
{
	if (x >= 1 && x <= row && y >= 1 && y <= column) {
		//如果if的判断条件中不加入array->sign[x-1][y]=='0'条件的话，相邻的两个相同的数会陷入无限递归
		if (array->number[x - 1][y] == array->number[x][y] && array->sign[x - 1][y] == '0') {
			array->sign[x - 1][y] = '*';
			search_recursion(array, row, column, x - 1, y);
		}
		if (array->number[x + 1][y] == array->number[x][y] && array->sign[x + 1][y] == '0') {
			array->sign[x + 1][y] = '*';
			search_recursion(array, row, column, x + 1, y);
		}
		if (array->number[x][y - 1] == array->number[x][y] && array->sign[x][y - 1] == '0') {
			array->sign[x][y - 1] = '*';
			search_recursion(array, row, column, x, y - 1);
		}
		if (array->number[x][y + 1] == array->number[x][y] && array->sign[x][y + 1] == '0') {
			array->sign[x][y + 1] = '*';
			search_recursion(array, row, column, x, y + 1);
		}
	}
	else
		return;
}


/***************************************************************************
函数名称：array_change_confirm
功    能：确定是否把相邻的值合并到某位置
输入参数：
返 回 值：
说    明：Y表示确定 N表示不确定，重新选择行列坐标，Q表示直接退出
***************************************************************************/
void array_change_confirm(char* confirm, int coordinate_x, int coordinate_y)
{
	int x, y;
	cout << "请确定是否把相邻的相同值合并到" << (char)('A' - 1 + coordinate_x) << coordinate_y - 1 << "中(Y/N/Q):";
	cct_getxy(x, y);
	for (;;) {
		*confirm = _getche();
		tj_charupr(confirm);
		if (*confirm == 'Y' || *confirm == 'N' || *confirm == 'Q') {
			cout << endl;
			return;
		}
		else
			cct_gotoxy(x, y);
	}
}

/***************************************************************************
函数名称：array_change_zero_fall
功    能：完成数组在某次变化中0的下落这一过程
返 回 值：
说    明：
***************************************************************************/
void array_change_zero_fall(struct shuzu* array, int row, int column)
{
	int i, j, k;
	char t1;
	int t2;
	for (j = 1; j <= column; j++)
		for (k = 0; k <= M; k++)
			for (i = 2; i <= row; i++)
				if (array->sign[i][j] == '*') {
					//交换上下两个位置的数字和标记
					t2 = array->sign[i - 1][j];
					array->sign[i - 1][j] = array->sign[i][j];
					array->sign[i][j] = t2;

					t1 = array->number[i - 1][j];
					array->number[i - 1][j] = array->number[i][j];
					array->number[i][j] = t1;
				}
}


/***************************************************************************
函数名称：array_change
功    能：完成数组一次的整个变化，并完成各步骤中的输出，计算这一步的得分
输入参数：
返 回 值：
说    明：
***************************************************************************/
void array_change(struct shuzu* array, int row, int column, int x, int y, int* score, int* target, int* max_of_number)
{
	int one_step_score = 0;//表示这一步的分数
	int i, j;//循环变量

	//相同值归并
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->sign[i][j] == '*') {
				if (i == x && j == y)
					array->number[i][j]++;
				else
					array->number[i][j] = 0;
				one_step_score += 3 * array->number[x][y];//计算这一步所得到的扥书
			}
		}
	}
	output_array_number(array, row, column, 1, *max_of_number, "相同值归并后的数组(不同色标记)：");

	*score += one_step_score;
	cout << "本次得分：" << one_step_score << " 总得分：" << *score << " 合成目标：" << *target << endl;

	*max_of_number = search_max_of_number(array, row, column);

	wait_for_enter("按回车键进行数组下落除0操作...");

	//除0外的数字下落
	array->sign[x][y] = '0';
	array_change_zero_fall(array, row, column);
	output_array_number(array, row, column, 1, *max_of_number, "除0后的数组(不同色标记)：");


	wait_for_enter("按回车键进行新值填充...");
	//进行新值的填充
	output_array_number(array, row, column, 0, *max_of_number, "新值填充后的数组(不同色标记)：");

}



//返回值为数字矩阵中最大的数
int search_max_of_number(struct shuzu* array, int row, int column)
{
	int max_of_number = 3;
	int i, j;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->number[i][j] > max_of_number)
				max_of_number = array->number[i][j];
		}
	}
	return max_of_number;
}



//对符号数组进行初始化，使每个元素都为'0'
void initialization_array_sign(struct shuzu* array)
{
	int i, j;
	for (i = 1; i < M; i++) {
		for (j = 1; j < N; j++) {
			array->sign[i][j] = '0';
		}
	}
}


/***************************************************************************
函数名称：initial_judge
功    能：在一次合成完成之后，下一次合成开始之前，判断游戏是否能继续进行，以及判断是否达到了合成目标
***************************************************************************/
void initial_judge(char option, struct shuzu* array, int row, int column, int max_of_number, int* target, int* judge_of_end)
{
	int i, j;
	*judge_of_end = 1;//*judge_of_end为1表示游戏要被迫结束，为0表示游戏能继续进行
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (!((array->number[i][j] - array->number[i - 1][j]) * (array->number[i][j] - array->number[i + 1][j])
				* (array->number[i][j] - array->number[i][j - 1]) * (array->number[i][j] - array->number[i][j + 1]))) {
				*judge_of_end = 0;//只要有一个人数可以进行合成，那么*judge_if_end就为0
			}
		}
	}

	if (max_of_number == *target) {//判断是否达到合成目标
		if (option == '4') {
			cout << endl;
			cct_setcolor(14, 4);
			cout << "已经合成到" << *target << endl;
			cct_setcolor(0, 15);
			wait_for_enter("按回车键继续向更高的目标进发...");
		}
		(*target)++;
	}

	if (*judge_of_end) {
		cout << endl;
		cct_setcolor(14, 4);
		if (option == '9')
			cct_gotoxy(0, 4 + 4 * row);
		cout << "无可合并的项，游戏结束！" << endl;
		cct_setcolor(0, 15);
		return;
	}
}