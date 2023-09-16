/* 2152988 ������ �ƿ� */
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


//��ӡ����
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

//��ӡ���
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

//��ӡ�ƶ�·��
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

//�ƶ���Ŀ������
void input_ball_set_sub(point& p, int opt,const game&G)
{
	//opt:0������ʼ��1����Ŀ��
	const char* txt[] = {
		"������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺",
		"��ʼλ��Ϊ�գ�����������.",
		"������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺",
		"Ŀ��λ�÷ǿգ�����������.",
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
			cout << "�����������������";
			cout << setw(20) << "";
		}
		cct_showch(prt_beg.x, prt_beg.y, ' ', 0, 7, 50);
		cct_gotoxy(prt_beg.x, prt_beg.y);
	}
	cout << "����Ϊ" << char(p.x + 'A') << "��"<<p.y+1<<"��" 
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
	cout << "��ǰ����:" << endl;
	prt_G(G);
	cout << endl;

	//��������ɫ
	int next_color[3];
	for (int i = 0; i < 3; i++) {
		next_color[i] = rand() % COLOR_MAX + 1;
	}
	cout << "��3���������ɫ�ֱ��ǣ�";
	for (int i = 0; i < 3; i++) {
		cout << next_color[i] << ' ';
	}
	cout << endl;

	//�ж��ƶ�
	point src, dst;
	stack path_s;
	input_ball_set(src, dst, G);
	int ret = find_path(G, src, dst, path_s);
	cout << endl;
	//�ƺ����˵����⣬�����Լ��鲻����

	//�ƶ�
	if (ret) {
		cout << "���ҽ�����飺" << endl;
		prt_G_mark(G);

		cout << endl;
		cout << "�ƶ�·��(��ͬɫ��ʶ)��" << endl;
		prt_G_move(G, src);
	}
	else {
		cout << "�޷��ҵ��ƶ�·��" << endl;
	}

	//��������

	//���G.mark����ʵmark���ò�����,path���������mark��
	//���������õ���˳���¼·����stack��Ӧ�ñ����
	path_s.top = 0;

}

void option3(game& G)
{
	//��ղ���ʼ��Ϸ
	G.score = 0;
	clear_G_mark(G);

	const int NEW_BALL = 3;
	int next_color[NEW_BALL] = { 0 };
	int flag_new = 1;
	while (1) {
		cout << "��ǰ����:" << endl;
		prt_G(G);
		cout << endl;

		//��Ϸ��������
		if (G.vertex_num >= G.row * G.line) {
			cout << "�޿�λ���ƶ�����Ϸ����!" << endl;
			break;
		}

		generate_color(next_color, NEW_BALL, flag_new);
		cout << "��3���������ɫ�ֱ��ǣ�";
		for (int i = 0; i < NEW_BALL; i++) {
			cout << next_color[i] << ' ';
		}
		cout << endl;

		//�ж��ƶ�
		point src, dst;
		stack path_s;
		input_ball_set(src, dst, G);
		int ret = find_path(G, src, dst, path_s);
		cout << endl;

		//���mark
		clear_G_mark(G);


		if (ret) {
			flag_new = 0;
			//swap
			int tmp = G.board[src.x][src.y];
			G.board[src.x][src.y] = G.board[dst.x][dst.y];
			G.board[dst.x][dst.y] = tmp;

			//������
			int bingo_n = bingo(G);
			if (!bingo_n) {
				//��������
				flag_new = 1;
				gen_ball(G, next_color, NEW_BALL);
			}

			cout << "�ƶ��������(��ͬɫ��ʶ)��" << endl;
			prt_G(G);
			cout << "���ε÷֣�" 
				<<(bingo_n ? (bingo_n - 1) * (bingo_n - 2) : 0)
				<< " �ܵ÷֣�" << G.score << endl;
			cout << endl;
		}
		else {
			flag_new = 0;
			cout << "�޷��ҵ��ƶ�·��" << endl;
			cout << endl;
			continue;
		}

	}
	G.score = 0;
	clear_G_mark(G);
}