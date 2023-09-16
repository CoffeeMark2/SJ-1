/* 2153299 计拔 杨非凡 */
#pragma once

//M，N表示开的二维数组的行列，我们使数组“大一圈”便于后续处理
const int M = 10;
const int N = 12;


//结构体的定义
//number[M][N]用来表示数字，sign[M][N]用来进行标记
struct shuzu {
	int number[M][N] = { 0 };
	char sign[M][N];
};


/*************************

			  90-b2-base中的内部数组有关的函数

									 *************************/

 //根据矩阵中的最大值来产生新的随机值
void random_number_generation(struct shuzu* array, int max_of_number, int row, int column);


//用来输入选择的行列
bool coordinate_judge(struct shuzu* array, int row, int column, int x, int y, int canshu);
void input_coordinate(struct shuzu* array, int row, int column, int* cooddinate_x, int* coordinate_y);

//两个函数对应了递归和非递归形式下，每一步寻找相邻的相同值
void search_recursion(struct shuzu* array, int row, int column, int x, int y);
void search_no_recursion(struct shuzu& array, int row, int column);

//两个函数分别用于输出数字矩阵和符号矩阵
void output_array_number(struct shuzu* array, int row, int column, int canshu, int max, const char* const prompt);
void output_array_sign(struct shuzu* array, int row, int column);

//调用其他函数完成矩阵的一次完整的变化演示
void array_change_zero_fall(struct shuzu* array, int row, int column);
void array_change(struct shuzu* array, int row, int column, int x, int y, int* score, int* target, int* max_of_number);

//确认是否把相邻的相同值进行合成
void array_change_confirm(char* confirm, int x, int y);

//寻找数字矩阵中的最大值
int search_max_of_number(struct shuzu* array, int row, int column);

//将字符数组初始化
void initialization_array_sign(struct shuzu* array);

//每一次变化后检查是否达到合成目标，以及是否还能操作
void initial_judge(char option, struct shuzu* array, int row, int column, int max_of_number, int* target, int* judge_of_end);



/*************************

			  90-b2-console中的伪图形有关的函数

									 *************************/
									 //这两个函数用来打印初始的表格和每个小方块
void console_output_original_array(struct shuzu* array, int row, int column, char option);
void console_output_original_form(int row, int column, char option);

//读入鼠标和键盘的状态
void choose_ketboard_and_mouse(char option, struct shuzu* array, int row, int column, int* max_of_number, int* score, int* target, int* loop_q);

//判断光标的位置是否在某个小方格内部
int mouse_area_judge(int row, int column, int MX, int MY, int* x, int* y);

//这两个函数用来对读入的鼠标和键盘的状态转换到图形界面上
void display_of_choose(char option, int* loop, struct shuzu* array, int* coordinate_x,
	int* coordinate_y, int row, int column, int MX, int MY, int MAction, int keycode1, int keycode2);
void display_of_choose2(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y);


//其它的一些比较短小的功能函数

//确认是否选择当前的闪烁的方块
void console_confirm(const char* const prompt, int row);

//控制每一个小方块突出显示还是普通显示
void display(int canshu, struct shuzu* array, int coordinate_x, int coordinate_y);

//方块在合成时的闪烁动画
void flash(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y);

//对应伪图形中非零值下落时的动画显示
void move1(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y);
void move_2(struct shuzu* array, int coordinate_x, int coordinate_y);



/*************************

			  90-b2-tools中的共用的功能型函数

									 *************************/

									 //输入行 列 以及合成目标
void input_row_and_column(int* row, int* column, int* target, char option);


void tj_charupr(char* a);


//输出指定的字符串，并要求按回车键才能继续
void wait_for_enter(const char* const prompt);
