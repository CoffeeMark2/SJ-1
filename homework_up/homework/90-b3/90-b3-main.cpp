/* 2152988 ������ �ƿ� */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;
const int OPTION_NUM = 2;
int menu(void)
{
	const char* menu[OPTION_NUM] =
	{
		"1.��ʾ�ؿ�",
		"0.�˳�",
	};
	cct_setcolor();
	cout << "---------------------------------" << endl;
	for (int i = 0; i < OPTION_NUM; i++) {
		cout << menu[i] << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��:] ";

	int i;
	while (1) {
		i = _getche();
		if (i >= '0' && i <= OPTION_NUM + '0') {
			break;
		}
		else if (i == '\r') {
			cout << "[��ѡ��:] ";
		}
		else {
			cout << "\b \b";
		}
	}
	return i - '0';
}

int main()
{
	cct_setfontsize("������", 20);
	cct_setconsoleborder(BOARD_COL, BOARD_ROW, BOARD_COL, BOARD_ROW*2);
	while (1) {
		file_list L;
		//get filename
		if (get_filename(L) < 0) {
			return -1;
		}
		int option = menu();
		if (option == 1) {
			cct_cls();

			popmenu(L);
			to_be_continued_end();
		}
		else if (option == 0) {
			break;
		}
		else {
			cct_cls();
		}
	}

	return 0;
}