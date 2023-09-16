#pragma once

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define MY_OVERFLOW    -2

const int OPTION_NUM = 8;
const int ROW_MAX = 9, LINE_MAX = 9;
const int ROW_MIN = 7;
const int COLOR_MAX = 7;
const int COLOR_BG = COLOR_HBLACK;

//棋盘打印初始坐标
const int BOARDER_X = 0, BOARDER_Y = 1;
//打印⭕的初始坐标
const int POINT_X = BOARDER_X + 2, POINT_Y = BOARDER_Y + 1;


struct point {
	int x;
	int y;
};
struct game {
	int board[ROW_MAX][LINE_MAX];
	int mark[ROW_MAX][LINE_MAX];
	int row, line;
	int vertex_num= 0;
	int vertex[COLOR_MAX + 1] = { 0 };
	int score = 0;
	int vertex_bingo[COLOR_MAX + 1] = { 0 };
};

//队列
typedef int Status;

const int MAXSIZE = 100;

typedef point ElemType;

typedef struct {
	ElemType base[MAXSIZE];
	int front;
	int rear;
}QNode;
Status Init(QNode& Q);
Status Enter(QNode& Q, ElemType e);
Status Delete(QNode& Q, ElemType& e);
int Empty(const QNode& Q);

//栈
struct stack {
	ElemType base[MAXSIZE];
	int top = 0;
};

void input_rl(int& row, int& line);
void clear_G_mark(game& G);

//生成新球
int gen_ball_init(game& G, int n);
int gen_ball(game& G, int next_color[], int n);

void to_be_continued(void);
void to_be_continued_endl(const char* prompt, const int X = 0, const int Y = 22);
char* tj_strlwr(char* str);
char* tj_strupr(char* str);
void prt_G(const game& G);
void prt_G_mark(const game& G);
void prt_G_move(const game& G, point src);

void input_ball_set(point& src, point& dst, const game& G);
int find_path(game& G, const point src, const point dst,stack&path);
void generate_color(int next_color[], int len, int flag_new);
//消除球,返回被消除的球数量
int bingo(game& G);

void option3(game& G);
void option2(game& G);


//伪图形界面
//调整窗口大小
void change_boarder(const game& G, int& option,
	int& line, int& row, int& buff_r, int& buff_l);
void prt_boarder_opt4(game& G);
void prt_boarder(game& G);

void opt6(game& G);
void game_gui(game& G);
//游戏辅助内容
void prt_other_init(game& G);
void prt_per(game& G);