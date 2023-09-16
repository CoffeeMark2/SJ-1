/* 2152988 ������ �ƿ� */

/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		int option = menu() - '0';
		if (option >= 1 && option <= 3) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp);
			stack_init(src, n);
			int PRT_X = 0, PRT_Y = 25;
			hanoi(n, src, tmp, dst, PRT_X, PRT_Y, option);
			cout <<endl << "���س�������...";

			while (_getch() != '\r')
				;

			cct_cls();
		}
		else if (option == 4) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 1);
			int PRT_X = 5, PRT_Y = 15;
			stack_init(src, n);
			cct_cls();
			prt_title(src, dst, n);
			prt_init_stack(PRT_X, PRT_Y);
			prt_stack_verticle(PRT_X, PRT_Y);
			pause();
			hanoi(n, src, tmp, dst, PRT_X, PRT_Y, option);
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 5) {
			cct_cls();
			prt_column();
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 6) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp);

			cct_cls();
			prt_column();
			prt_init_column(src, n);
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 7) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 0);
			cct_cls();
			prt_column();
			prt_init_column(src, n);
			stack_init(src, n);
			Sleep(500);
			prt_move(src, dst, 1);
			to_be_continued(NULL);
			stack_clear();
		}
		else if (option == 8) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 1);
			int PRT_X = 0, PRT_Y = 25;
			stack_init(src, n);
			cct_cls();
			prt_init_stack(PRT_X, PRT_Y);
			prt_stack_verticle(PRT_X, PRT_Y);
			prt_column();
			prt_init_column(src, n);
			pause();
			hanoi(n, src, tmp, dst, PRT_X, PRT_Y, option);
			to_be_continued(NULL);
			stack_clear();

		}
		else if (option == 9) {
			int n;
			char src, dst, tmp;
			input(&n, &src, &dst, &tmp, 0);
			int PRT_X = 0, PRT_Y = 25;
			stack_init(src, n);
			cct_cls();
			prt_init_stack(PRT_X, PRT_Y);
			prt_stack_verticle(PRT_X, PRT_Y);
			prt_column();
			prt_init_column(src, n);
			Sleep(500);
			game(PRT_X, PRT_Y, src, dst, n);
			to_be_continued(NULL);
			stack_clear();

		}
		else if (option == 0) {
			break;
		}
		else {
			cct_cls();
			cout << "option error" << endl;
		}
		stack_clear();
	}

	return 0;
}
