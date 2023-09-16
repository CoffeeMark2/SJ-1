/* 2152988 杨恺铭 计科 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;


//打印棋盘
void prt_G(const game& G)
{
	cout << "  |";
	for (int i = 1; i <= G.line; i++) {
		cout << setw(3) << i;
	}
	cout << endl;

	cout << "--+-";
	for (int i = 1; i <= G.line; i++) {
		cout << "---";
	}
	cout << endl;

	for (int i = 0; i < G.row; i++) {
		cout << char('A' + i) << " |";
		for (int j = 0; j < G.line; j++) {
			cout << setw(2) << "";
			if (G.board[i][j] == 0) {
				cout << 0;
			}
			else {
				cct_setcolor(COLOR_BG, G.board[i][j]);
				cout << G.board[i][j];
				cct_setcolor();
			}
		}
		cout << endl;
	}
	cout << endl;
}

//打印标记
void prt_G_mark(const game& G)
{
	cout << "  |";
	for (int i = 1; i <= G.line; i++) {
		cout << setw(3) << i;
	}
	cout << endl;

	cout << "--+-";
	for (int i = 1; i <= G.line; i++) {
		cout << "---";
	}
	cout << endl;

	for (int i = 0; i < G.row; i++) {
		cout << char('A' + i) << " |";
		for (int j = 0; j < G.line; j++) {
			cout << setw(2) << "";
			if (G.mark[i][j] == 0) {
				cout << 0;
			}
			else {
				cout << '*';
			}
		}
		cout << endl;
	}
	cout << endl;
}

//打印移动路径
void prt_G_move(const game& G,const point src)
{
	cout << "  |";
	for (int i = 1; i <= G.line; i++) {
		cout << setw(3) << i;
	}
	cout << endl;

	cout << "--+-";
	for (int i = 1; i <= G.line; i++) {
		cout << "---";
	}
	cout << endl;

	for (int i = 0; i < G.row; i++) {
		cout << char('A' + i) << " |";
		for (int j = 0; j < G.line; j++) {
			cout << setw(2) << "";
			if (G.board[i][j] == 0) {
				if (G.mark[i][j] != 0) {
					cct_setcolor(COLOR_BG, COLOR_CYAN);
					cout << 0;
					cct_setcolor();
				}
				else {

					cout << 0;
				}
			}
			else {
				if (i == src.x && j == src.y) {
					cct_setcolor(COLOR_BG, COLOR_CYAN);
					cout << G.board[i][j];
					cct_setcolor();
				}
				else {
					cout << G.board[i][j];

				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

//移动和目的坐标
void input_ball_set_sub(point& p, int opt,const game&G)
{
	//opt:0代表起始，1代表目标
	const char* txt[] = {
		"请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：",
		"起始位置为空，请重新输入.",
		"请以字母+数字形式[例：c2]输入要移动球的目的坐标：",
		"目标位置非空，请重新输入.",
	};
	cout << txt[opt*2];
	char next_set[3];
	point prt_beg;
	cct_getxy(prt_beg.x, prt_beg.y);
	while (1) {
		cin.getline(next_set, sizeof(next_set));
		tj_strupr(next_set);
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		if (next_set[0] >= 'A' && next_set[0] <= ('A' - 1 + G.row)
			&& next_set[1] >= '1' && next_set[1] <= ('0' + G.line)) {
			p.x = next_set[0] - 'A';
			p.y = next_set[1] - '1';
			if ((opt == 0 && G.board[p.x][p.y] == 0)
				|| (opt == 1 && G.board[p.x][p.y] != 0)) {
				cout << txt[opt*2+1];
				cout << setw(20) << "";
			}
			else {
				break;
			}
		}
		else {
			cout << "输入错误，请重新输入";
			cout << setw(20) << "";
		}
		cct_showch(prt_beg.x, prt_beg.y, ' ', 0, 7, 50);
		cct_gotoxy(prt_beg.x, prt_beg.y);
	}
	cout << "输入为" << char(p.x + 'A') << "行"<<p.y+1<<"列" 
		<< setw(20) << "" << endl;
}
void input_ball_set(point& src, point& dst,const game &G)
{
	input_ball_set_sub(src, 0,G);
	input_ball_set_sub(dst, 1,G);
}

//void prt_path(point path[ROW_MAX][LINE_MAX],game &G)
//{
//	for (int i = 0; i < ROW_MAX; i++) {
//		for (int j = 0; j < LINE_MAX; j++) {
//			cout << "(" << path[i][j].x << ','
//				<< path[i][j].y << ")" << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//}

void option2(game& G)
{
	cout << "当前数组:" << endl;
	prt_G(G);
	cout << endl;

	//产生新颜色
	int next_color[3];
	for (int i = 0; i < 3; i++) {
		next_color[i] = rand() % COLOR_MAX + 1;
	}
	cout << "下3个彩球的颜色分别是：";
	for (int i = 0; i < 3; i++) {
		cout << next_color[i] << ' ';
	}
	cout << endl;

	//判断移动
	point src, dst;
	stack path_s;
	input_ball_set(src, dst, G);
	int ret = find_path(G, src, dst, path_s);
	cout << endl;
	//似乎出了点问题，但是自己查不出来

	//移动
	if (ret) {
		cout << "查找结果数组：" << endl;
		prt_G_mark(G);

		cout << endl;
		cout << "移动路径(不同色标识)：" << endl;
		prt_G_move(G, src);
	}
	else {
		cout << "无法找到移动路径" << endl;
	}

	//产生新球

	//清空G.mark（其实mark作用不明显,path作用替代了mark）
	//真正起作用的是顺序记录路径的stack，应该被清空
	path_s.top = 0;

}

void option3(game& G)
{
	//清空并开始游戏
	G.score = 0;
	clear_G_mark(G);

	const int NEW_BALL = 3;
	int next_color[NEW_BALL] = { 0 };
	int flag_new = 1;
	while (1) {
		cout << "当前数组:" << endl;
		prt_G(G);
		cout << endl;

		//游戏结束条件
		if (G.vertex_num >= G.row * G.line) {
			cout << "无空位可移动，游戏结束!" << endl;
			break;
		}

		generate_color(next_color, NEW_BALL, flag_new);
		cout << "下3个彩球的颜色分别是：";
		for (int i = 0; i < NEW_BALL; i++) {
			cout << next_color[i] << ' ';
		}
		cout << endl;

		//判断移动
		point src, dst;
		stack path_s;
		input_ball_set(src, dst, G);
		int ret = find_path(G, src, dst, path_s);
		cout << endl;

		//清空mark
		clear_G_mark(G);


		if (ret) {
			flag_new = 0;
			//swap
			int tmp = G.board[src.x][src.y];
			G.board[src.x][src.y] = G.board[dst.x][dst.y];
			G.board[dst.x][dst.y] = tmp;

			//消除球
			int bingo_n = bingo(G);
			if (!bingo_n) {
				//产生新球
				flag_new = 1;
				gen_ball(G, next_color, NEW_BALL);
			}

			cout << "移动后的数组(不同色标识)：" << endl;
			prt_G(G);
			cout << "本次得分：" 
				<<(bingo_n ? (bingo_n - 1) * (bingo_n - 2) : 0)
				<< " 总得分：" << G.score << endl;
			cout << endl;
		}
		else {
			flag_new = 0;
			cout << "无法找到移动路径" << endl;
			cout << endl;
			continue;
		}

	}
	G.score = 0;
	clear_G_mark(G);
}