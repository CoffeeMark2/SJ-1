/* 2153299 �ư� ��Ƿ� */

//�������αͼ�ν��湲�õĹ��ߺ���
#include <iostream>
#include <iomanip>
#include <conio.h>

#include "cmd_console_tools.h"
#include "common_menu_and_tools.h"
#include "90-01-b2.h"
using namespace std;


//��д�ĺ�����tj_str����û�е�
/***************************************************************************
�������ƣ�tj_charupr
��    �ܣ���Сд��ĸת�ɴ�д��ĸ
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void tj_charupr(char* a)
{
	if (*a >= 'a' && *a <= 'z')
		*a = *a - 32;
}


/***************************************************************************
�������ƣ�wait_for_enter
��    �ܣ�����������ַ�������Ҫ�󰴻س������ܼ���
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void wait_for_enter(const char* const prompt)
{
	if ((prompt == NULL) || (strlen(prompt) == 0))
		cout << endl << "���س�������";
	else
		cout << endl << prompt;

	while (_getch() != '\r')
		;
}

/***************************************************************************
�������ƣ�input_row_and_column
��    �ܣ�����ѡ���������У��У����ж��Ƿ�����ϳ�Ŀ��
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void input_row_and_column(int* row, int* column, int* target, char option)
{
	//��������
	for (;;) {
		cout << "����������(5-8)��" << endl;
		cin >> *row;
		if (cin.good()) {
			if (*row >= 5 && *row <= 8) {
				cin.ignore(0xffffffff, '\n');
				break;
			}
			else {
				cin.ignore(0xffffffff, '\n');
			}
		}
		else {
			cin.clear();
			cin.ignore(0xffffffff, '\n');
		}
	}

	//������
	for (;;) {
		cout << "����������(5-10)��" << endl;
		cin >> *column;
		if (cin.good()) {
			if (*column >= 5 && *column <= 10) {
				cin.ignore(0xffffffff, '\n');
				break;
			}
			else {
				cin.ignore(0xffffffff, '\n');
			}
		}
		else {
			cin.clear();
			cin.ignore(0xffffffff, '\n');
		}
	}

	//ֻ�в���ѡ����Ҫ����ϳ�Ŀ��
	if (option == '3' || option == '4' || option == '9') {
		for (;;) {
			cout << "������ϳ�Ŀ��(5-20)��" << endl;
			cin >> *target;
			if (cin.good()) {
				if (*target >= 5 && *target <= 20) {
					cin.ignore(0xffffffff, '\n');
					break;
				}
				else {
					cin.ignore(0xffffffff, '\n');
				}
			}
			else {
				cin.clear();
				cin.ignore(0xffffffff, '\n');
			}
		}
	}
}