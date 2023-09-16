/* 2152988 ������ �ƿ� */


/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;




int cnt = 0;
int prt_speed;
int stack[N_STACK][N]; //��¼����ջ
int top[N_STACK];//ջ��ָ�루ָ�����Ԫ�ص���һ����

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����static ��ʲô�ô�?
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y)
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
	while (_getch() != '\r')
		;

	cct_cls();

	return;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void prt_title(char src, char dst, int n)
{
	cct_gotoxy(0, 0);
	cout << "�� " << src << " �ƶ��� " << dst
		<< "���� " << n << " �㣬��ʱ����Ϊ " << prt_speed;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

void input(int* pn, char* psrc, char* pdst, char* ptmp, int flag_speed)
{
	cct_gotoxy(INITX, INITY);
	int n;
	char src, dst;
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (n >= 1 && n <= N) {
			break;
		}
	}
	*pn = n;
	cin.clear();
	cin.ignore(65536, '\n');
	while (1) {
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;
		if (src >= 'a' && src <= 'c')
			src -= 32;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if ((src >= 'A' && src <= 'C')) {
			break;
		}
	}
	*psrc = src;
	cin.clear();
	cin.ignore(65536, '\n');
	while (1) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		dst = (dst >= 'a' && dst <= 'c') ? dst - 32 : dst;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if ((dst >= 'A' && dst <= 'C')) {
			if (dst == src)
				cout << "Ŀ����(" << dst
				<< ")��������ʼ��(" << src << ")��ͬ\n";
			else
				break;
		}
	}
	*pdst = dst;
	cin.clear();
	cin.ignore(65536, '\n');
	*ptmp = 'B' * 3 - src - dst;
	if (flag_speed) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> prt_speed;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void prt_column(int color, int SETX, int SETY)
{
	//const int LENGTH = 23, HEIGHT = 12,GAP=9;
	int	set = SETX + LENGTH / 2;

	for (int i = 0; i < N_STACK; i++) {
		cct_showch(SETX + i * (LENGTH + GAP), SETY, CH, color, color, LENGTH);
	}
	for (int j = 0; j < HEIGHT; j++) {
		for (int i = 0; i < N_STACK; i++) {
			cct_showch(set + i * (LENGTH + GAP), SETY - j, CH, color, color, 1);
			Sleep(SLEEP/50);
		}
	}

	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(0, 0);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void prt_init_column(char src, int n, int SETX, int SETY)
{
	const int SET_COL = SET_COL_A + (src - 'A') * (LENGTH + GAP);
	for (int i = 0; i < n; i++) {
		int lenth = (n - i) * 2 + 1;
		cct_showch(SET_COL - n + i, SETY - i - 1, CH, n - i, n - i, lenth);
		Sleep(SLEEP / 20);
	}
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(0, 0);
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void prt_stack_verticle(int PRT_X, int PRT_Y)
{
	//�ָ�Ĭ����ɫ
	int xa = PRT_X + 2, xb = xa + (PRT_LEN - 5) / 2,
		xc = xa + (PRT_LEN - 5);
	cct_gotoxy(PRT_X, PRT_Y);
	for (int i = 0; i < PRT_LEN; i++) {
		cout << '=';
	}
	cct_gotoxy(xa, PRT_Y + 1);
	cout << "A" << setw((PRT_LEN - 5) / 2)
		<< "B" << setw((PRT_LEN - 5) / 2) << "C";

	for (int set = 0; set < N_STACK; set++) {
		for (int i = 0; i < N; i++) {
			cct_gotoxy(xa + set * (PRT_LEN - 5) / 2 - 1, PRT_Y - 1 - i);
			if (i < top[set]) {
				cout << setw(2) << stack[set][i];
			}
			else {
				cout << setw(2) << "";
			}
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void prt_init_stack(int PRT_X, int PRT_Y)
{
	cct_gotoxy(PRT_X, PRT_Y + 4);
	cout << "��ʼ:" << setw(14) << "";
	prt_stack();

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void stack_init(char src, int n)
{
	for (int i = 0; i < n; i++) {
		stack[src - 'A'][i] = n - i;
	}
	top[src - 'A'] = n;

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void stack_clear(void)
{
	for (int i = 0; i < N_STACK; i++) {
		top[i] = 0;
	}
	cnt = 0;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������n�̵����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void prt_move(const char src, const char dst, const int n, int SETX, int SETY, int flag_game)
{
	const int SRC_X = SET_COL_A + (src - 'A') * (LENGTH + GAP),
		SRC_Y = SETY - top[src - 'A'];
	const int DST_X = SET_COL_A + (dst - 'A') * (LENGTH + GAP),
		DST_Y = SETY - top[dst - 'A'];
	//����
	for (int i = 0; i < HEIGHT - top[src - 'A']; i++) {
		cct_showch(SRC_X - n, SRC_Y - i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		cct_showch(SRC_X, SRC_Y - i, ' ', COLOR_WHITE, COLOR_WHITE, 1);
		cct_showch(SRC_X - n, SRC_Y - i - 1, ' ', n, n, 2 * n + 1);
		if (prt_speed)
			Sleep(SLEEP/prt_speed / 20);
		else
			Sleep(SLEEP / 20);
	}

	if (src < dst) {
		//���ƣ������ܷ�����ͬ�ĵط���
		for (int i = 0; i < DST_X - SRC_X; i++) {
			cct_showch(SRC_X - n + i, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);

			cct_showch(SRC_X - n + i + 1, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', n, n, 2 * n + 1);
			if (prt_speed)
				Sleep(SLEEP / prt_speed/3 / 20);
			else
				Sleep(SLEEP/3 / 20);
		}
	}
	else {
		//����
		for (int i = 0; i < SRC_X - DST_X; i++) {
			cct_showch(SRC_X - n - i, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);

			cct_showch(SRC_X - n - i - 1, (SRC_Y - (HEIGHT - top[src - 'A']))
				, ' ', n, n, 2 * n + 1);
			if (prt_speed)
				Sleep(SLEEP / prt_speed/3 / 20);
			else
				Sleep(SLEEP/3 / 20);
		}
	}


	//�½�
	for (int i = HEIGHT - top[dst - 'A']; i > 1; i--) {
		cct_showch(DST_X - n, DST_Y - i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		if (i != HEIGHT - top[dst - 'A']) {
			cct_showch(DST_X, DST_Y - i, ' ', COLOR_WHITE, COLOR_WHITE, 1);
		}
		cct_showch(DST_X - n, DST_Y - i + 1, ' ', n, n, 2 * n + 1);
		if (prt_speed)
			Sleep(SLEEP / prt_speed/20);
		else
			Sleep(SLEEP/20);
	}
	cct_setcolor();
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void prt_stack_horizontal(int PRT_X, int PRT_Y, char src, char dst, int n)
{
	cct_gotoxy(PRT_X, PRT_Y + 4);
	cout << "��" << setw(4) << cnt
		<< "��(" << n << "#: "
		<< src << "-->" << dst << ")";
	prt_stack();
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void prt_stack(void)
{
	//�ָ�Ĭ����ɫ
	for (int j = 0; j < N_STACK; j++) {
		cout << char(j + 'A') << ":";
		for (int i = 0; i < top[j]; i++) {
			cout << setw(2) << stack[j][i];
		}
		cout << setw(2 * (N - top[j])) << "";
		cout << ' ';
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void operate(char src, char dst)
{
	int pop = src - 'A';
	int push = dst - 'A';
	stack[push][top[push]++] = stack[pop][--top[pop]];
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����Ƿ���Ҫ�Ӳ�����
  ***************************************************************************/
void pause(void)
{
	if (prt_speed == 0) {
		while (_getch() != '\r')
			;
	}
	else {
		Sleep(SLEEP / prt_speed);
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void prt_option(int n, char src, char tmp, char dst, int PRT_X, int PRT_Y, int option)
{
	if (option == 1) {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	if (option == 2) {
		cout << "��" << setw(4) << cnt
			<< "��(" << n << "#: "
			<< src << "-->" << dst << ")"<<endl;
		
	}
	if (option == 3) {
		cout << "��" << setw(4) << cnt
			<< "��(" << n << "#: "
			<< src << "-->" << dst << ")";
		prt_stack();
		cout << endl;
	}
	if (option == 4 || option == 8) {
		prt_stack_horizontal(PRT_X, PRT_Y, src, dst, n);
		prt_stack_verticle(PRT_X, PRT_Y);
		operate(dst, src);
		if (option == 8)
			prt_move(src, dst, n);
		operate(src, dst);
		pause();
	}
}
  /***************************************************************************
	�������ƣ�
	��    �ܣ���ŵ���ݹ麯��
	���������
	�� �� ֵ��
	˵    ����
	***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int PRT_X, int PRT_Y, int option)
{
	if (n == 0)
		return;
	hanoi(n - 1, src, dst, tmp, PRT_X, PRT_Y, option);
	cnt++;
	operate(src, dst);
	prt_option(n, src, tmp, dst, PRT_X, PRT_Y, option);
	hanoi(n - 1, tmp, src, dst, PRT_X, PRT_Y, option);
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void game(int PRT_X, int PRT_Y, char src, char dst, int n)
{
	cct_gotoxy(0, 0);
	cout << "�� "<<src<<" �ƶ��� "<<dst<<"���� "<<n<<" ��";
	cct_gotoxy(0, PRT_Y + 6);
	cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
	int cnt = 0;
	while (1) {
		if (top[dst - 'A'] == n) {
			cct_gotoxy(0, PRT_Y + 7);
			cout << "��Ϸ����������";
			break;
		}
		char src, dst;
		while (1) {
			cct_gotoxy(61, PRT_Y + 6);
			char tmp[3];
			cin.getline(tmp, 3, '\n');
			src = tmp[0];
			dst = tmp[1];
			
			if (src >= 'a' && src <= 'c')
				src -= 32;
			if (dst >= 'a' && dst <= 'c')
				dst -= 32;
			if (src == 'Q'||src == 'q') {
				return;
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			
			else if ((src >= 'A' && src <= 'C')
				&& (dst >= 'A' && dst <= 'C') && (src != dst)) {
				if (0 == top[src - 'A']) {
					cout << endl << "Դ��Ϊ��!";
					Sleep(500);
				}
				else if (0 != top[dst - 'A']
					&& stack[src - 'A'][top[src - 'A']-1] 
					> stack[dst - 'A'][top[dst - 'A'] - 1]) {
					cout << endl << "����ѹС�̣��Ƿ��ƶ�!";
					Sleep(500);

				}
				else {
					cct_showch(61, PRT_Y + 6, ' ', 0, 7, 100);
					cnt++;
					break;
				}
			}
			Sleep(SLEEP/5);
			cct_showch(61, PRT_Y + 6,' ',0,7,100);
			cct_showch(0, PRT_Y + 8, ' ', 0, 7, 50);
		}
		operate(src, dst);
		prt_stack_horizontal(PRT_X, PRT_Y, src, dst, cnt);
		prt_stack_verticle(PRT_X, PRT_Y);
		operate(dst, src);
		prt_move(src, dst, stack[src - 'A'][top[src - 'A'] - 1]);
		operate(src, dst);

	}
}