/* 2152988 杨恺铭 计科 */
#include <iostream>
#include <cstring>
#include <conio.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;


Status Init(QNode& Q)
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}
Status Enter(QNode& Q, ElemType e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
Status Delete(QNode& Q, ElemType& e)
{
	if (Q.rear == Q.front)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
int Empty(const QNode& Q)
{
	return (Q.rear == Q.front);
}

char* tj_strupr(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL) {
		return str;
	}
	char* p = str;
	while (*p) {
		if (*p >= 'a' && *p <= 'z') {
			(*p) -= 'a' - 'A';
		}
		p++;
	}
	return str;
}
char* tj_strlwr(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (!str) {
		return str;
	}
	char* p = str;
	while (*p) {
		if (*p >= 'A' && *p <= 'Z') {
			(*p) += 'a' - 'A';
		}
		p++;
	}
	return str;
}

void to_be_continued(void)
{
	cct_setcolor(); //恢复缺省颜色
	cout << endl << endl;
	cout << "本小题结束，请输入End继续...";
	int x1, y1;
	cct_getxy(x1, y1);
	const int m = 30;

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	char str[m];
	while (1) {
		cin.getline(str, m);
		tj_strlwr(str);
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		if (strcmp(str, "end") == 0) {
			break;
		}
		else {
			cout << "输入错误，请重新输入";
			cct_showch(x1, y1, ' ', 0, 7, m);
			cct_gotoxy(x1, y1);
		}
	}

	cct_cls();

	return;
}

void to_be_continued_endl(const char* prompt, const int X , const int Y )
{
	cct_setcolor(); //恢复缺省颜色

	if (prompt)
		cout << prompt;

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	cct_cls();

	return;
}


//参数输入
void input_rl(int& row, int& line)
{
	while (1) {
		cout << "请输入行数(7-9)" << endl;
		cin >> row;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (row >= ROW_MIN && row <= ROW_MAX) {
			break;
		}
	}
	while (1) {
		cout << "请输入列数(7-9)" << endl;
		cin >> line;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (line >= ROW_MIN && line <= ROW_MAX) {
			break;
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');

}

//生成球_初始化
int gen_ball_init(game& G, int n)
{
	srand((unsigned int)(time(0)));
	int cnt = 0;
	while (cnt < n) {
		if (G.vertex_num >= G.row * G.line) {
			return MY_OVERFLOW;
		}
		int x = rand() % G.row, y = rand() % G.line;
		int color = rand() % COLOR_MAX + 1;
		if (G.board[x][y] == 0) {
			G.board[x][y] = color;
			cnt++;
			G.vertex[color]++;
			G.vertex_num++;
		}

	}
	return OK;
}

//生成球
int gen_ball(game& G, int next_color[],int n)
{
	srand((unsigned int)(time(0)));
	int cnt = 0;
	while (cnt < n) {
		if (G.vertex_num >= G.row * G.line) {
			return MY_OVERFLOW;
		}
		int x = rand() % G.row, y = rand() % G.line;
		int color = next_color[cnt];
		if (G.board[x][y] == 0) {
			G.board[x][y] = color;
			cnt++;
			G.vertex[color]++;
			G.vertex_num++;
		}

	}
	return OK;
}


//清空棋盘
void clear_G_mark(game& G)
{
	memset(&G.mark, 0, sizeof(G.mark));
}

//寻找路径
int find_path(game& G, const point src,
	const point dst, stack& path_s)
{

	int visited[ROW_MAX][LINE_MAX] = { 0 };
	point path[ROW_MAX][LINE_MAX] = { {0,0} };
	QNode Q;
	Init(Q);
	visited[src.x][src.y] = 1;
	Enter(Q, src);
	int ret = 0;
	while (!Empty(Q)) {
		point P;
		Delete(Q, P);
		if (P.x == dst.x && P.y == dst.y) {
			ret = 1;
			break;
		}
		//找到所有子节点
		//左
		if (G.board[P.x][P.y - 1] == 0 && (P.y - 1 >= 0)
			&& visited[P.x][P.y - 1] == 0) {
			visited[P.x][P.y - 1] = 1;
			path[P.x][P.y - 1] = P;
			point P1 = P;
			P1.y--;
			Enter(Q, P1);
		}
		//右
		if (G.board[P.x][P.y + 1] == 0 && (P.y + 1 <= G.line - 1)
			&& visited[P.x][P.y + 1] == 0) {
			visited[P.x][P.y + 1] = 1;
			path[P.x][P.y + 1] = P;
			point P2 = P;
			P2.y++;
			Enter(Q, P2);
		}
		//上
		if (G.board[P.x - 1][P.y] == 0 && (P.x - 1 >= 0)
			&& visited[P.x - 1][P.y] == 0) {
			visited[P.x - 1][P.y] = 1;
			path[P.x - 1][P.y] = P;
			point P3 = P;
			P3.x--;
			Enter(Q, P3);
		}
		//下
		if (G.board[P.x + 1][P.y] == 0 && P.x + 1 <= G.row - 1
			&& visited[P.x + 1][P.y] == 0) {
			visited[P.x + 1][P.y] = 1;
			path[P.x + 1][P.y] = P;
			point P4 = P;
			P4.x++;
			Enter(Q, P4);
		}

	}
	if (ret) {
		for (point p = dst; !(p.x == src.x && p.y == src.y);
			p = path[p.x][p.y]) {
			path_s.base[path_s.top++] = p;
			G.mark[p.x][p.y] = 1;
		}
		G.mark[src.x][src.y] = 1;
		path_s.base[path_s.top++] = src;
	}
	return ret;
}

void generate_color(int next_color[], int len, int flag_new)
{
	if (flag_new) {

		for (int i = 0; i < len; i++) {
			next_color[i] = rand() % COLOR_MAX + 1;
		}
	}

}

//消除球,返回被消除的球数量
int bingo(game& G)
{
	int ret = 0;
	int bingo_n =0;
	clear_G_mark(G);
	const int BINGO_MIN = 5;//满五个及以上消除

	for (int i = 0; i < G.row; i++) {
		for (int j = 0; j < G.line; j++) {
			if (G.mark[i][j] != 0) {
				continue;
			}
			//空位置直接跳过
			if (G.board[i][j] == 0) {
				continue;
			}

			int color = G.board[i][j];
			//横向
			if (G.line - j >= BINGO_MIN) {
				//遍历，但两种状态退出
				int k;
				for (k = 0; j+k<G.line ; k++) {
					if (G.board[i][j + k] != color) {
						break;
					}
				}
				if (k >= BINGO_MIN) {
					ret = 1;
					bingo_n += k;
					for (int l = 0; l < k; l++) {
						G.mark[i][j + l] = 1;
					}
				}
			}
			//纵向
			if (G.row - i >= BINGO_MIN) {
				int k;
				for (k = 0; i + k < G.row; k++) {
					if (G.board[i + k][j] != color) {
						break;
					}
				}
				if (k >= BINGO_MIN) {
					ret = 1;
					bingo_n += k;

					for (int l = 0; l < k; l++) {
						G.mark[i + l][j] = 1;
					}
				}
			}
			//右下
			if (G.row - i >= BINGO_MIN && G.line - j >= BINGO_MIN) {
				int k;
				for (k = 0; j + k < G.line && i + k < G.row; k++) {
					if (G.board[i + k][j + k] != color) {
						break;
					}
				}
				if (k >= BINGO_MIN) {
					ret = 1;
					bingo_n += k;

					for (int l = 0; l < k; l++) {
						G.mark[i + l][j + l] = 1;
					}
				}
			}
			//左下
			if (G.row - i >= BINGO_MIN && j+1>=BINGO_MIN) {
				int k;
				for (k = 0; j - k >= 0 && i + k < G.row; k++) {
					if (G.board[i + k][j - k] != color) {
						break;
					}
				}
				if (k >= BINGO_MIN) {
					ret = 1;
					bingo_n += k;

					for (int l = 0; l < k; l++) {
						G.mark[i + l][j - l] = 1;
					}
				}

			}
		}
	}//end judge

	//消除球
	if (ret) {
		for (int i = 0; i < G.row; i++) {
			for (int j = 0; j < G.line; j++) {
				if (G.mark[i][j] == 1) {
					++G.vertex_bingo[G.board[i][j]];
					--G.vertex[G.board[i][j]];
					G.board[i][j] = 0;
				}
			}
		}
		G.score += (bingo_n ? (bingo_n - 1) * (bingo_n - 2) : 0);
	}

	return bingo_n;
}