/*2152988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "5-b7.h"
using namespace std;

const int N = 10;//��ŵ��������
const int N_STACK = 3;
//��ֱ��ӡ��ŵ��λ�ã��ӷָ��߿�ʼ��
const int PRT_X = 10, PRT_Y = 12, PRT_LEN = 25;
const int SLEEP = 1000;

int cnt = 0; 
static int prt_speed;
static int prt_array;
int stack[N_STACK][N];
int top[N_STACK];

int stack_a[N], stack_b[N], stack_c[N];//��¼����ջ
int top_a, top_b, top_c;//ջ��ָ�루ָ�����Ԫ�ص���һ����
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
		while (_getch() != 13)
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
  ˵    �������ʼ�մ�ӡtitle
  ***************************************************************************/
void prt_title(char src, char dst, int n)
{
	cct_gotoxy(0, 0);
	cout << "�� " << src << " �ƶ��� " << dst
		<< "���� " << n << " �㣬��ʱ����Ϊ " << prt_speed
		<< "��" << (!prt_array ? "��" : "") << "��ʾ�ڲ�����ֵ";
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void prt_stack_verticle()
{
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
			cct_gotoxy(xa+set*(PRT_LEN - 5) / 2 - 1, PRT_Y - 1 - i);
			if (i < top[set]) {
				cout << setw(2) << stack[set][i];
			}
			else {
				cout << setw(2) << "";
			}
		}
	}
	
	/*for (int i = 0; i < N; i++) {
		cct_gotoxy(xb - 1, PRT_Y - 1 - i);
		if (i < top_b) {
			cout << setw(2) << stack_b[i];
		}
		else {
			cout << setw(2) << "";
		}
	}
	for (int i = 0; i < N; i++) {
		cct_gotoxy(xc - 1, PRT_Y - 1 - i);
		if (i < top_c) {
			cout << setw(2) << stack_c[i];
		}
		else {
			cout << setw(2) << "";
		}
	}*/
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
  ˵    ����
  ***************************************************************************/
void prt_stack(void) {
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
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
			char src����ʼ��
			char tmp���м���
			char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 0)
		return;
	hanoi(n - 1, src, dst, tmp);

	cct_gotoxy(0, PRT_Y + 5);
	cout << "��" << setw(4) << ++cnt
		<< "��(" << n << "#: "
		<< src << "-->" << dst << ")";

	operate(src, dst);
	if (prt_array) {
		prt_stack();
		if (prt_speed == 0) {
			while (_getch() != 13)
				;
		}
	}

	prt_stack_verticle();
	pause();

	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp;
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
	cin.clear();
	cin.ignore(65536, '\n');

	for (int i = 0; i < n; i++) {
		stack[src - 'A'][i] = n - i;
	}
	top[src - 'A'] = n;


	cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
	cin >> prt_speed;
	cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
	cin >> prt_array;

	cin.clear();
	cin.ignore(65536, '\n');

	cct_cls();

	prt_title(src, dst, n);
	if (prt_array) {
		cct_gotoxy(0, PRT_Y + 5);
		cout << "��ʼ:" << setw(16) << "";
		prt_stack();
		if (prt_speed == 0) {
			while (_getch() != 13)
				;
		}
	}
	prt_stack_verticle();
	pause();

	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);

	cct_gotoxy(0, PRT_Y + 15);
	system("pause");
	return 0;
}

/*
Ϊʲôֻʹ��һ��������
*/