/*2152988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：菜单函数
  功    能：
  输入参数：无
  返 回 值：菜单按钮
  说    明：使用参数控制选项个数？
***************************************************************************/
int menu(void)
{
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n"
		"2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n"
		"3.用箭头键控制上下左右，边界停止\n"
		"4.用箭头键控制上下左右，边界回绕\n"
		"5.用箭头键控制上下左右(边界停止，演示大写HPKM可移动的错误，此项不需要实现)\n"
		"6.用箭头键控制上下左右(边界回绕，演示大写HPKM可移动的错误，此项不需要实现)\n"
		"0.退出\n"
		"[请选择0 - 6]");
	int option = _getch() - '0';
	return option;
}
/***************************************************************************
  函数名称：
  功    能：使用ijkl控制光标移动
  输入参数：if_rotate
  返 回 值：void
  说    明：参数为真，光标回转，否则到头就会停住
***************************************************************************/
void move_by_ijkl(int if_rotate)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;
	gotoxy(hout, MAX_X / 2 + 1, MAX_Y / 2 + 1);
	while (1) {
		int move = _getch();
		//printf( move << '\b');
		if (move == 'l' || move == 'l' - 32) {
			if (x >= MAX_X) {
				if (if_rotate) {
					x = 1;
					//if (y != MAX_Y)
					//	++y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, ++x, y);
			}
		}
		else if (move == 'j' || move == 'j' - 32) {
			if (x <= 1) {
				if (if_rotate) {
					x = MAX_X;
					//if (y != 1)
					//	--y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, --x, y);
			}
		}
		else if (move == 'i' || move == 'i' - 32) {
			if (y <= 1) {
				if (if_rotate) {
					y = MAX_Y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, --y);
			}
		}
		else if (move == 'k' || move == 'k' - 32) {
			if (y >= MAX_Y) {
				if (if_rotate) {
					y = 1;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, ++y);
			}
		}
		else if (move == ' ') {
			printf( " \b");
		}
		else if (move == 'q' || move == 'q' - 32) {
			break;
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：使用ijkl控制光标移动
  输入参数：if_rotate
  返 回 值：void
  说    明：参数为真，光标回转，否则到头就会停住
***************************************************************************/
void move_by_arrow(int if_rotate)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;
	gotoxy(hout, MAX_X / 2 + 1, MAX_Y / 2 + 1);
	while (1) {
		int a = _getch();
		if (a == 224) {
			int move = _getch();
			//printf( move );
			if (move == 77) {
				if (x >= MAX_X) {
					if (if_rotate) {
						x = 1;
						//if (y != MAX_Y)
						//	++y;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, ++x, y);
				}
			}
			else if (move == 75) {
				if (x <= 1) {
					if (if_rotate) {
						x = MAX_X;
						//if (y != 1)
						//	--y;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, --x, y);
				}
			}
			else if (move == 72) {
				if (y <= 1) {
					if (if_rotate) {
						y = MAX_Y;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, x, --y);
				}
			}
			else if (move == 80) {
				if (y >= MAX_Y) {
					if (if_rotate) {
						y = 1;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, x, ++y);
				}
			}

		}
		else {
			if (a == ' ') {
				printf( " \b");
			}
			else if (a == 'q' || a == 'q' - 32) {
				break;
			}
		}



	}
}
/***************************************************************************
  函数名称：
  功    能：使用ijkl控制光标移动
  输入参数：if_rotate
  返 回 值：void
  说    明：参数为真，光标回转，否则到头就会停住
***************************************************************************/
void move_by_ijkl1(int if_rotate)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;
	gotoxy(hout, MAX_X / 2 + 1, MAX_Y / 2 + 1);
	while (1) {
		int move = _getch();
		if (move == 224) {
			_getch();
			continue;
		}
		//printf( move << '\b');
		if (move == 'l' || move == 'l' - 32) {
			if (x >= MAX_X) {
				if (if_rotate) {
					x = 1;
					//if (y != MAX_Y)
					//	++y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, ++x, y);
			}
		}
		else if (move == 'j' || move == 'j' - 32) {
			if (x <= 1) {
				if (if_rotate) {
					x = MAX_X;
					//if (y != 1)
					//	--y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, --x, y);
			}
		}
		else if (move == 'i' || move == 'i' - 32) {
			if (y <= 1) {
				if (if_rotate) {
					y = MAX_Y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, --y);
			}
		}
		else if (move == 'k' || move == 'k' - 32) {
			if (y >= MAX_Y) {
				if (if_rotate) {
					y = 1;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, ++y);
			}
		}
		else if (move == ' ') {
			printf( " \b");
		}
		else if (move == 'q' || move == 'q' - 32) {
			break;
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

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	while (1) {
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);
		int option = menu();
		if (option >= 1 && option <= 6) {//最好用充要条件
			cls(hout);
			/* 显示初始的边框及其中的随机字符 */
			init_border(hout);
			if (1 == option)
				move_by_ijkl(0);
			else if (2 == option)
				move_by_ijkl(1);
			else if (3 == option)
				move_by_arrow(0);
			else if (4 == option)
				move_by_arrow(1);
			else if (5 == option)
				move_by_ijkl1(0);
			else if (6 == option)
				move_by_ijkl1(1);
			//暂停
			//getchar();

			//菜单问题，返回菜单
			gotoxy(hout, 0, 23);
			printf( "游戏结束，按回车键返回菜单.");



			//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
			while (_getch() != 13)
				;

			//getchar();
		}
		else if (option == 0)
			break;

	}



	return 0;
}
//使用箭头控制光标移动，按下箭头按钮，实际上读入两个数 224和对应的方向控制键，而左键刚好是‘K’的ASCII码
// 第一次读入244，不符合任何条件，进入下一个循环读入'K'，于是向下移动
// 
//随机数：有可能<20个数，伪随机数可能相同，此时会在同一个地方生成两次字符，所以看起来<20.