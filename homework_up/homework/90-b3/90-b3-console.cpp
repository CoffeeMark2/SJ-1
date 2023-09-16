/* 2152988 ������ �ƿ� */
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;

char* tj_strupr(char* str)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
//��ӡ�ؿ�
void prt_board(const int prt_x, const int prt_y)
{
	cct_gotoxy(prt_x, prt_y);
	cout << "�X�T�[";
	cct_gotoxy(prt_x, prt_y + 1);
	cout << "�U  �U";
	cct_gotoxy(prt_x, prt_y + 2);
	cout << "�^�T�a";
}
void prt_mark(const int prt_x, const int prt_y, const char* p)
{
	cct_gotoxy(prt_x + 2, prt_y + 1);
	cout << p;
}
void prt_game_elem(const int row, const int col, const char type)
{
	int prt_x = col * 6, prt_y = row * 3;
	if (type == '9') {
		return;
	}
	else if (type == 'W') {
		cct_setcolor(COLOR_RED, COLOR_BLACK);
		prt_board(prt_x, prt_y);
		prt_mark(prt_x, prt_y,"XX");
	}
	else if (type == '0') {
		cct_setcolor(COLOR_HBLACK, COLOR_HBLACK);
		prt_board(prt_x, prt_y);	
	}
	else if (type == 'B') {
		cct_setcolor(COLOR_GREEN);
		prt_board(prt_x, prt_y);
		prt_mark(prt_x, prt_y, "��");
	}
	else if (type == 'F') {
		cct_setcolor(COLOR_HCYAN, COLOR_GREEN);
		prt_board(prt_x, prt_y);
		prt_mark(prt_x, prt_y, "��");
	}
	else if (type == 'S') {
		cct_setcolor(COLOR_BLUE);
		prt_board(prt_x, prt_y);
		prt_mark(prt_x, prt_y, "��");
	}
	else if (type == 'R') {
		cct_setcolor(COLOR_HYELLOW,COLOR_RED);
		prt_board(prt_x, prt_y);
		prt_mark(prt_x, prt_y, "��");
	}

	cct_setcolor();
}
int prt_game(const file_list& L)
{
	//���ļ�
	//��ʵ��strcat()����
	stringstream name_buff;
	name_buff << "./stage/" << filename_demo
		<< L.list[L.cur_list] << filename_type;
	char file_name[100];
	name_buff >> file_name;
	ifstream in(file_name, ios::in);
	if (!in.is_open()) {
		return -1;
	}
	//��ȡ��ĸ��ȷ����������λ��
	const int BUFF_LEN_MAX = BOARD_COL/2;
	char game_buff[BUFF_LEN_MAX];
	int row = 0;
	while (in.peek() != EOF) {
		in.getline(game_buff, BUFF_LEN_MAX);
		tj_strupr(game_buff);
		int col = 0;
		for (col = 0; game_buff[col]; col++) {
			//��ӡλ��
			prt_game_elem(row, col, game_buff[col]);
		}
		++row;
	}
	in.close();

	return 0;
}