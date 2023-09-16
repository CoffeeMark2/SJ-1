/* 2153299 �ư� ��Ƿ� */

//��αͼ��ʵ�ֵĺ���
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include "cmd_console_tools.h"
#include "90-01-b2.h"
using namespace std;

/*
			 ��αͼ�ν�����صĺ���
										 */


										 /**************************************************************************
										 �������ƣ�display
										  ��    ��:/*����canshu�Ĳ�ͬ��(coordinate_x, coordinate_y)���ķ�����в�ͬ����ʾ
										  canshu����ȡ:
										  1         ����ǰ��ɫΪ��ɫ��ͻ����ʾ
										  0         ����ǰ��ɫΪ��ɫ����ͨ��ʾ
										  -1        ���д���ɫ�ĸ���
										 ���������
										 �� �� ֵ����
										 ˵    ������������ѡ��Ϊ5���������Ϊ����ļ���᲻ͬ
										 ***************************************************************************/
void display(int canshu, struct shuzu* array, int coordinate_x, int coordinate_y)
{

	if (canshu == 1) {//����ͻ����ʾ,ǰ��ɫΪ��ɫ
		cct_setcolor(array->number[coordinate_x][coordinate_y], 15);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1);
		cout << "������";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x);

		if (array->number[coordinate_x][coordinate_y] < 10)
			cout << "��" << array->number[coordinate_x][coordinate_y] << " ��";
		else
			cout << "��" << array->number[coordinate_x][coordinate_y] << "��";

		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1);
		cout << "������";
		cct_setcolor(0, 15);
	}

	if (canshu == 0) {//������ͨ��ʾ��ǰ��ɫΪ��ɫ
		cct_setcolor(array->number[coordinate_x][coordinate_y], 0);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1);
		cout << "������";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x);

		if (array->number[coordinate_x][coordinate_y] < 10)
			cout << "��" << array->number[coordinate_x][coordinate_y] << " ��";
		else
			cout << "��" << array->number[coordinate_x][coordinate_y] << "��";

		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1);
		cout << "������";
		cct_setcolor(0, 15);
	}

	if (canshu == -1) {//���ںϲ�����ʱ������������ʧ���ô���ɫ�����������ϲ��ķ���
		cct_setcolor(15, 15);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1);
		cout << "      ";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x);
		cout << "      ";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1);
		cout << "      ";
		cct_setcolor(0, 15);
	}
}


/**************************************************************************
�������ƣ�flash
��    ��:����ģ�ⷽ��ϳ�ʱ����ѡ�еķ�����˸��Ч��
���������
�� �� ֵ����
˵    ����
***************************************************************************/
void flash(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y)
{//����ģ�ⷽ��ϳ�ʱ����ѡ�еķ�����˸��Ч��
	int i = 1;
	for (i = 1; i <= 10; i++) {
		//ͻ����ʾ����ͨ��ʾ���������ģ����˸��Ч��
		display(1, array, coordinate_x, coordinate_y);
		Sleep(50);
		display(0, array, coordinate_x, coordinate_y);
		Sleep(50);
	}
	Sleep(300);
}


/**************************************************************************
�������ƣ�console_output_original_array
��    ��:��ӡ��ʼ��ÿ��С����
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void console_output_original_array(struct shuzu* array, int row, int column, char option)
{
	int i, j;
	//ѡ��Ϊ5��û�б߿�������Ҫ��������
	if (option == '5') {
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= column; j++) {
				int x, y;
				x = 6 * j - 2;
				y = 3 * i;
				cct_setcolor(array->number[i][j], 0);
				cct_gotoxy(x, y);
				cout << "������";
				cct_gotoxy(x, y + 1);
				cout << "��" << array->number[i][j] << " ��";
				cct_gotoxy(x, y + 2);
				cout << "������";
				cct_setcolor(0, 15);
			}
		}
	}

	else {
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= column; j++) {
				int x, y;
				x = 8 * j - 4;
				y = 4 * i - 1;

				display(0, array, i, j);
			}
		}
	}
}




/**************************************************************************
�������ƣ� console_output_original_form
��    ��:��ӡ��ʼ�ı��
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void console_output_original_form(int row, int column, char option)
{
	int cols, lines, buffer_cols, buffer_lines;
	int i, j, k;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);

	if (option == '5') {//��Ӧ����option=5�����û�к��ߵı��
		cols = column * 6 + 7;
		lines = row * 3 + 8;
		cct_setconsoleborder(cols, lines, buffer_cols, buffer_lines);
		cct_cls();
		cout << "��Ļ��ǰ����Ϊ��" << lines << "��" << cols << "��" << endl;

		//�ȴ�ӡһ����ɫ���̵ı��
		cout << " ";
		for (j = 1; j <= column; j++) {
			cout << "     " << j - 1;
		}
		cout << endl;

		//��ӡ�ϱ߿�
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "��";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "������";
			Sleep(1);
		}
		cout << "��";
		Sleep(1);
		cout << endl;


		//��ӡ�м������
		for (i = 1; i <= row; i++) {
			for (k = 1; k <= 3; k++) {
				cct_setcolor(0, 15);
				if (k == 2)
					cout << char('A' + i - 1) << " ";
				else
					cout << "  ";

				cct_setcolor(15, 0);
				cout << "��";
				Sleep(1);
				for (j = 1; j <= column; j++) {
					cout << "      ";
					Sleep(1);
				}
				cout << "��";
				Sleep(1);
				cout << endl;
			}
		}

		//��ӡ�±߿�
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "��";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "������";
			Sleep(1);
		}
		cout << "��";
		Sleep(1);
		cout << endl;
		cct_setcolor(0, 15);
	}

	else {//��Ӧ����option=6,7,8,9ʱ���к��ߵı��
		cols = column * 8 + 5;
		lines = row * 4 + 7;
		cct_setconsoleborder(cols, lines, buffer_cols, buffer_lines);
		cct_cls();
		cout << "��Ļ��ǰ����Ϊ��" << lines << "��" << cols << "��" << endl;
		//�ȴ�ӡһ����ɫ���̵ı��
		for (j = 1; j <= column; j++) {
			if (j == 1)
				cout << "      " << j - 1;
			else
				cout << "       " << j - 1;
		}
		cout << endl;

		//��ӡ�ϱ߿�
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "��";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "������";
			if (j != column)
				cout << "��";
			Sleep(1);
		}
		cout << "��";
		Sleep(1);
		cout << endl;

		//��ӡ�м�����
		for (i = 1; i <= row; i++) {
			for (k = 1; k <= 3; k++) {
				cct_setcolor(0, 15);
				if (k == 2)
					cout << char('A' + i - 1) << " ";
				else
					cout << "  ";

				cct_setcolor(15, 0);
				cout << "��";
				Sleep(1);
				for (j = 1; j <= column; j++) {
					cout << "      ";
					if (j != column)
						cout << "��";
					Sleep(1);
				}
				cout << "��";
				Sleep(1);
				cout << endl;
			}

			if (i != row) {
				cct_setcolor(0, 15);
				cout << "  ";
				cct_setcolor(15, 0);
				cout << "��";
				Sleep(1);
				for (j = 1; j <= column; j++) {
					cout << "������";
					if (j != column)
						cout << "��";
					Sleep(1);
				}
				cout << "��";
				Sleep(1);
				cout << endl;
			}
		}


		//��ӡ�±߿�
		cct_setcolor(0, 15);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "��";
		Sleep(1);
		for (j = 1; j <= column; j++) {
			cout << "������";
			if (j != column)
				cout << "��";
			Sleep(1);
		}
		cout << "��";
		Sleep(1);
		cout << endl;
		cct_setcolor(0, 15);
	}
}



/**************************************************************************
�������ƣ�mouse_area_judge
��    ��:�ж���ѡ��С�����ʱ������λ���Ƿ�Ϸ������жϹ���Ƿ���ĳ��С�����ڲ�
���������
�� �� ֵ��
˵    ����
***************************************************************************/
int mouse_area_judge(int row, int column, int MX, int MY, int* x, int* y)
{
	int mouse_area_X = 0, mouse_area_Y = 0;
	int i, j;
	for (i = 1; i <= row; i++) {
		if (MY >= 4 * i - 1 && MY <= 4 * i + 1) {
			mouse_area_Y = 1;
			*x = i;
		}
	}

	for (j = 1; j <= column; j++) {
		if (MX >= 8 * j - 4 && MX <= 8 * j + 1) {
			mouse_area_X = 1;
			*y = j;
		}
	}

	return (mouse_area_X * mouse_area_Y);

}



/**************************************************************************
�������ƣ�confirm
��    ��:ͨ�����������߻س���������ȷ��
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void console_confirm(const char* const prompt, int row)
{
	cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
	cct_gotoxy(0, 3 + 4 * row);
	cout << prompt;
	int loop = 1;
	for (; loop;) {
		int MX = 0, MY = 0, MAction = 0, keycode1 = 0, keycode2 = 0;
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);//��ȡ���ͼ����ϵİ���
		if (MAction == 2 || keycode1 == 13)
			loop = 0;
	}
}


/**************************************************************************
�������ƣ�move_2
��    ��:ͼ�����ƶ������еĶ���չʾ
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void move_2(struct shuzu* array, int coordinate_x, int coordinate_y)
{
	//ͨ��������ʾС������ϵ��£��м䴩�����ߵĹ���
	int i = 0;
	for (i = 1; i <= 4; i++) {//ͨ���������Ĵβ�ȥ�ڴ�ӡģ�⶯��Ч��
		cct_setcolor(array->number[coordinate_x][coordinate_y], 0);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 1 + i);
		cout << "������";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + i);
		cout << "��" << array->number[coordinate_x][coordinate_y] << " ��";
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x + 1 + i);
		cout << "������";

		cct_setcolor(15, 0);
		cct_gotoxy(8 * coordinate_y - 4, 4 * coordinate_x - 2 + i);
		if (i == 4)
			cout << "������";//��Ĩȥ�ĺ����ٴδ�ӡ����
		else
			cout << "      ";
		Sleep(10);
		cct_setcolor(0, 15);
	}
}


/**************************************************************************
�������ƣ�move_1
��    ��:ͼ�����ƶ������еĶ���չʾ
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void move1(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y)
{
	int i, j, k, m;
	int t1;
	char t2;


	//�ȴ����ң��ڴ��ϵ��£��������˳���÷������䣬�ܹ���֤ͼ�α任��������Ȼ����
	for (j = 1; j <= column; j++)
		for (i = row - 1; i >= 1; i--) {
			k = i;
			for (m = 1; m <= row; m++) {
				if (k <= row - 1 && array->sign[k][j] != '*' && array->sign[k + 1][j] == '*') {

					//����αͼ�εı任
					move_2(array, k, j);

					//�����ڲ�����ı任
					t2 = array->sign[k + 1][j];
					array->sign[k + 1][j] = array->sign[k][j];
					array->sign[k][j] = t2;
					t1 = array->number[k + 1][j];
					array->number[k + 1][j] = array->number[k][j];
					array->number[k][j] = t1;
					k++;
				}
				else
					break;
			}
		}
}




/**************************************************************************
�������ƣ�choose_ketboard_and_mouse
��    ��:��ȡ���ͼ����ϵİ���
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void choose_ketboard_and_mouse(char option, struct shuzu* array, int row, int column, int* max_of_number, int* score, int* target, int* loop_q)
{
	int MX, MY, MAction, keycode1, keycode2;
	int coordinate_x = 1, coordinate_y = 1;
	int loop = 1;//loop��������ѭ���Ƿ���ֹ
	cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
	cct_gotoxy(0, 3 + 4 * row);
	cout << "��ͷ��/����ƶ����س���/������ѡ�񲢽���";

	display(1, array, coordinate_x, coordinate_y);//�Ƚ����Ͻǵķ���ͻ����ʾ

	cct_enable_mouse();
	cct_setcursor(3);
	for (; loop == 1;) {
		MX = 0, MY = 0, MAction = 0, keycode1 = 0, keycode2 = 0;
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);//��ȡ���ͼ����ϵİ���
		display_of_choose(option, &loop, array, &coordinate_x, &coordinate_y, row, column, MX, MY, MAction, keycode1, keycode2);
		if (keycode1 == 'q' || keycode1 == 'Q') {
			loop = -1;
			*loop_q = 0;
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		}
	}

	if ((option == '8' || option == '9') && loop != -1) {
		int one_step_score = 0;
		int i, j;
		int a = array->number[coordinate_x][coordinate_y];

		//������ֵ�ĺϳɣ�������ÿһ���ĵ÷ֺ��ܵ÷�
		for (i = 1; i <= row; i++)
			for (j = 1; j <= column; j++)
				if (array->sign[i][j] == '*') {
					if (i == coordinate_x && j == coordinate_y) {
						array->number[i][j]++;
						display(1, array, i, j);
					}
					else {
						array->number[i][j] = 0;
						display(-1, array, i, j);
						Sleep(10);
					}
					one_step_score += 3 * a;
				}
		*score += one_step_score;
		*max_of_number = search_max_of_number(array, row, column);//�����������е����ֵ
		cct_gotoxy(0, 0);
		cout << "���ε÷�: " << one_step_score << " �ܷ�: " << *score << " �ϳ�Ŀ��: " << *target;
		cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		cct_gotoxy(0, 3 + 4 * row);

		flash(array, row, column, coordinate_x, coordinate_y);//�ϳɵ�Ч��չʾ


		//ѡ��Ϊ8��ʱ��Ҫ�ֲ�����У��м�Ҫ�ж����ͣ
		if (option == '8')
			console_confirm("�ϳ���ɣ��س���/�����������0", row);

		array->sign[coordinate_x][coordinate_y] = '0';
		move1(array, row, column, coordinate_x, coordinate_y);//���з�0������ڲ�����仯�Լ�αͼ�α仯
		display(0, array, coordinate_x, coordinate_y);
		if (option == '8')
			console_confirm("����0��ɣ��س���/������������ֵ", row);

		random_number_generation(array, *max_of_number, row, column);

		for (i = 1; i <= row; i++)
			for (j = 1; j <= column; j++)
				if (array->sign[i][j] == '*') {
					Sleep(20);
					display(0, array, i, j);
				}
		if (option == '8') {
			console_confirm("���κϳɽ�������c/�������������һ�εĺϳ�", row);
			cct_gotoxy(0, 3 + 4 * row);
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		}
	}
	cct_disable_mouse();
	cct_setcursor(2);
}



/**************************************************************************
�������ƣ�display_of_choose
��    ��: ����ͻ����ʾ���ͼ�����ѡ�еķ���
***************************************************************************/
void display_of_choose(char option, int* loop, struct shuzu* array, int* coordinate_x, int* coordinate_y,
	int row, int column, int MX, int MY, int MAction, int keycode1, int keycode2)
{
	int x = *coordinate_x, y = *coordinate_y;
	int mouse_area = 0;
	if (keycode1 == 224) {//��Ӧ���������������Ҽ�ͷ�����
		//���з�֧�ṹ��������߽绷��
		if (keycode2 == 72) {
			if (x == 1)
				x = row;
			else
				x--;
		}
		if (keycode2 == 80)
			x = x % column + 1;
		if (keycode2 == 75) {
			if (y == 1)
				y = column;
			else
				y--;
		}
		if (keycode2 == 77)
			y = y % row + 1;

		display(0, array, *coordinate_x, *coordinate_y);

		display(1, array, x, y);

		*coordinate_x = x;
		*coordinate_y = y;
		cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
		cct_gotoxy(0, 3 + 4 * row);
		cout << "[��ǰ����] " << char('A' + *coordinate_x - 1) << "��" << *coordinate_y - 1 << "��                          ";
	}


	else if (MAction == 1) {//��Ӧ����ƶ�
		mouse_area = mouse_area_judge(row, column, MX, MY, &x, &y);
		if (mouse_area) {//�ж�����Ƿ��ں���������
			display(0, array, *coordinate_x, *coordinate_y);

			display(1, array, x, y);

			*coordinate_x = x;
			*coordinate_y = y;
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
			cct_gotoxy(0, 3 + 4 * row);
			cout << "[��ǰ���] " << char('A' + *coordinate_x - 1) << "��" << *coordinate_y - 1 << "��                          ";
		}
		else {
			display(0, array, *coordinate_x, *coordinate_y);
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
			cct_gotoxy(0, 3 + 4 * row);
			cout << "[��ǰ���] λ�÷Ƿ�                             ";
		}
	}

	else if (keycode1 == 13) {
		//ֹͣ���������̵�ѭ��������
		if (option == '7') {
			cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
			cct_gotoxy(0, 3 + 4 * row);
			cout << "ѡ����" << char('A' + *coordinate_x - 1) << "��" << *coordinate_y - 1 << "��                              ";
			*loop = 0;
			return;
		}
		else {//ѡ��Ϊ8,9��ʱ��Ҫ���д����ж��Լ�ѡ���ȷ��
			if (!coordinate_judge(array, row, column, *coordinate_x, *coordinate_y, 0)) {
				cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
				cct_gotoxy(0, 3 + 4 * row);
				cout << "��Χ����ֵͬ����ͷ��/�������ƶ�";
			}
			else {
				cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
				cct_gotoxy(0, 3 + 4 * row);
				cout << "��ͷ��/�����ƶ�ȡ����ǰѡ��,�س���/��������ϳ�";
				display_of_choose2(array, row, column, *coordinate_x, *coordinate_y);
				int MX_ = 0, MY_ = 0, MAction_ = 0, keycode1_ = 0, keycode2_ = 0;
				cct_read_keyboard_and_mouse(MX_, MY_, MAction_, keycode1_, keycode2_);//��ȡ���ͼ����ϵİ���
				//ֻ���������ͻس������ܽ���ȷ��
				if (keycode1_ == 13 || (MAction_ == 2 && mouse_area_judge(row, column, MX, MY, &x, &y))) {
					*loop = 0;
				}
				else {//ȡ����ѡ�еķ����ͻ����ʾ
					int u, v;
					for (u = 1; u <= row; u++)
						for (v = 1; v <= column; v++)
							if (array->sign[u][v] == '*')
								display(0, array, u, v);
					initialization_array_sign(array);
					display_of_choose(option, loop, array, coordinate_x, coordinate_y, row, column, MX_, MY_, MAction, keycode1_, keycode2_);
				}
			}
		}
	}
	else if (MAction == 2) {//��Ӧ������
		mouse_area = mouse_area_judge(row, column, MX, MY, &x, &y);//Ҫ�ж���������
		if (mouse_area == 1) {
			if (option == '7') {
				cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
				cct_gotoxy(0, 3 + 4 * row);
				cout << "ѡ����" << char('A' + *coordinate_x - 1) << "��" << *coordinate_y - 1 << "��                               ";
				*loop = 0;
				return;
			}
			else {//ѡ��Ϊ8,9��ʱ��Ҫ���д����ж��Լ�ѡ���ȷ��
				if (!coordinate_judge(array, row, column, *coordinate_x, *coordinate_y, 0)) {
					cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
					cct_gotoxy(0, 3 + 4 * row);
					cout << "��Χ����ֵͬ����ͷ��/�������ƶ�";
				}
				else {
					cct_showch(0, 3 + 4 * row, ' ', 0, 7, 50);
					cct_gotoxy(0, 3 + 4 * row);
					cout << "��ͷ��/�����ƶ�ȡ����ǰѡ��,�س���/��������ϳ�";
					display_of_choose2(array, row, column, *coordinate_x, *coordinate_y);
					int MX_ = 0, MY_ = 0, MAction_ = 0, keycode1_ = 0, keycode2_ = 0;
					cct_read_keyboard_and_mouse(MX_, MY_, MAction_, keycode1_, keycode2_);//��ȡ���ͼ����ϵİ���
					//ֻ���������ͻس������ܽ���ȷ��
					if (keycode1_ == 13 || (MAction_ == 2 && mouse_area_judge(row, column, MX, MY, &x, &y))) {
						*loop = 0;
					}
					else {//ȡ����ѡ�еķ����ͻ����ʾ
						int u, v;
						for (u = 1; u <= row; u++)
							for (v = 1; v <= column; v++)
								if (array->sign[u][v] == '*')
									display(0, array, u, v);
						initialization_array_sign(array);
						display_of_choose(option, loop, array, coordinate_x, coordinate_y, row, column, MX_, MY_, MAction, keycode1_, keycode2_);
					}
				}
			}
		}
	}
}


//����ͻ����ʾ����ѡ�еķ���һ��ϳɵķ���
void display_of_choose2(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y)
{
	int i, j;
	search_recursion(array, row, column, coordinate_x, coordinate_y);
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->sign[i][j] == '*') {
				display(1, array, i, j);
			}
		}
	}
}
