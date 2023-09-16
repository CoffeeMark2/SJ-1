/* 2152988 杨恺铭 计科 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
#define COLOR_BLACK		0	//黑
#define COLOR_BLUE		1	//蓝
#define COLOR_GREEN		2	//绿
#define COLOR_CYAN		3	//青
#define COLOR_RED		4	//红
#define COLOR_PINK		5	//粉
#define COLOR_YELLOW	6	//黄
#define COLOR_WHITE		7	//白
#define COLOR_HBLACK	8	//亮黑
#define COLOR_HBLUE		9	//亮蓝
#define COLOR_HGREEN	10	//亮绿
#define COLOR_HCYAN		11	//亮青
#define COLOR_HRED		12	//亮红
#define COLOR_HPINK		13	//亮粉
#define COLOR_HYELLOW	14	//亮黄
#define COLOR_HWHITE	15	//亮白

const int N = 10;//汉诺塔最大层数
const int N_STACK = 3;//汉诺塔柱子三个
const int INITX = 0, INITY = 15;
//垂直打印汉诺塔位置（从分割线开始）
const int PRT_X = 10, PRT_Y = 12, PRT_LEN = 25;//纵向字符打印汉诺塔位置（柱底）
const int SLEEP = 1000;//延时
const int SETX = 1, SETY = 13;//伪图形汉诺塔打印位置（柱底）
const int LENGTH = 23, HEIGHT = 12, GAP = 9;//伪图形汉诺塔柱座宽，高，间距
const char CH = '*';        //字符为*(注意：如果是空格，则前景色无法显示)

const int SET_COL_A = SETX + LENGTH / 2;//柱子A的x坐标


void to_be_continued(const char* prompt, const int X = 0, const int Y = 38);
void input(int* pn, char* psrc, char* pdst, char* ptmp, int flag_speed=0);
int menu(void);
void prt_column(int color = COLOR_HWHITE, int SETX = 1, int SETY = 13);
void prt_init_column(char src, int n, int SETX = 1, int SETY = 13);
void stack_init(char src, int n);
void stack_clear(void);
void prt_move(const char src, const char dst, const int n, int SETX = 1, int SETY = 13,int flag_game=0);
void prt_init_stack(int PRT_X, int PRT_Y);
void prt_stack_verticle(int PRT_X, int PRT_Y);
void prt_stack(void);
void operate(char src, char dst);
void hanoi(int n, char src, char tmp, char dst, int PRT_X, int PRT_Y, int option);
void game(int PRT_X, int PRT_Y,char src,char dst,int n);
void prt_title(char src, char dst, int n);
void pause(void);