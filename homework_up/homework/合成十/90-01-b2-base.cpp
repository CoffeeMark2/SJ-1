/* 2153299 �ư� ��Ƿ� */
#include <iostream>
#include <iomanip>
#include <conio.h>

#include "cmd_console_tools.h"
#include "common_menu_and_tools.h"
#include "90-01-b2.h"
using namespace std;

/*
			 ���ڲ�����ʵ�ֵĺ���
										 */


/***************************************************************************
�������ƣ�random_number_generation
��    �ܣ�����Ŀǰ�����е����ֵ����0����ֵ���������ֵ
���������max_of_number -> Ŀǰ�����е����ֵ.row->����.column->����
 �� �� ֵ����
***************************************************************************/
void random_number_generation(struct shuzu* array, int max_of_number, int row, int column)
{
	int a = 0, b;
	int i, j, k;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->number[i][j] == 0) {

				/*�������max_of_number��ֵ����������ֵa�����õĲ�ֵͬ�ĸ���
				����������b��b����Ϊĳ�������ϵ����ֵ��֮����ݶ�����Ļ���������a*/
				//���ֵΪ3
				if (max_of_number == 3)
					a = rand() % 3 + 1;
				//���ֵΪ4
				else if (max_of_number == 4) {
					b = rand() % 10 + 1;
					for (k = 1; k <= 3; k++) {
						if (b >= 3 * k - 2 && b <= 3 * k) {
							a = k;
							break;
						}
					}
					if (b == 10)
						a = 4;
				}
				//���ֵΪ5
				else if (max_of_number == 5) {
					b = rand() % 100 + 1;
					for (k = 1; k <= 3; k++) {
						if (b >= 1 + (k - 1) * 25 && b <= k * 25) {
							a = k;
							break;
						}
					}
					if (b >= 76 && b <= 90)
						a = 4;
					if (b >= 91 && b <= 100)
						a = 5;
				}
				//���ֵΪ6
				else if (max_of_number == 6) {
					b = rand() % 100 + 1;
					for (k = 1; k <= 4; k++) {
						if (b >= 1 + (k - 1) * 20 && b <= k * 20) {
							a = k;
							break;
						}
					}
					if (b >= 81 && b <= 95)
						a = 5;
					if (b >= 96 && b <= 100)
						a = 6;
				}
				//���ֵ����6
				else {
					b = rand() % 100 + 1;
					if (b >= 96 && b <= 100)
						a = max_of_number;

					else if (b >= 91 && b <= 95)
						a = max_of_number - 1;

					else if (b >= 81 && b <= 90)
						a = max_of_number - 2;

					else {
						for (k = 1; k <= max_of_number - 3; k++) {
							if (b >= 1 + 80 * (k - 1) / (max_of_number - 3) && b <= 80 * k / (max_of_number / 3)) {
								a = k;
								break;
							}
						}
					}
				}
				array->number[i][j] = a;
			}
		}
	}
}
/**************************************************************************
�������ƣ�coordinate_judge
��    �ܣ��ж�һ��������������ͬ����
���������row->����.column->����
�� �� ֵ����Χ����ֵͬ����1��û�з���0
˵    ����
***************************************************************************/
bool coordinate_judge(struct shuzu* array, int row, int column, int x, int y, int canshu)
{
	bool coordinate_judge = 0;
	//�ж���Χ�ĸ�������û����ͬ��
	coordinate_judge = array->number[x][y] + canshu == array->number[x - 1][y]
		|| array->number[x][y] + canshu == array->number[x + 1][y]
		|| array->number[x][y] + canshu == array->number[x][y - 1]
		|| array->number[x][y] + canshu == array->number[x][y + 1];

	return coordinate_judge;
}


/**************************************************************************
�������ƣ�input_coordinate
��    �ܣ�
���������row->����.column->����
�� �� ֵ����
˵    ����
***************************************************************************/
void input_coordinate(struct shuzu* array, int row, int column, int* coordinate_x, int* coordinate_y)
{
	int x, y;
	char coordinate[30];
	for (;;) {
		cout << "������ĸ+������ʽ[���磺c2]����������꣺";
		cct_getxy(x, y);
		cin.getline(coordinate, 30, '\n');
		tj_strupr(coordinate);

		if (!coordinate) {//�ų����ַ��������
			cout << "�����������������";
			cct_showch(x, y, ' ', 0, 7, 30);
			cct_gotoxy(0, y);
			continue;
		}

		//�ж������λ����Χ�ĸ������Ƿ��к�����ͬ��
		if ((coordinate[0] >= 'A' && coordinate[0] <= 'A' + row - 1) && (coordinate[1] >= '0' && coordinate[1] <= '0' + column - 1)) {
			int x1, y1;
			x1 = coordinate[0] - 'A' + 1;//ת��Ϊ��������� ���м���
			y1 = coordinate[1] - '0' + 1;
			cout << "����Ϊ" << coordinate[0] << "��" << coordinate[1] << "��" << endl;
			if (coordinate_judge(array, row, column, x1, y1, 0)) {
				array->sign[x1][y1] = '*';
				*coordinate_x = x1;
				*coordinate_y = y1;
				break;
			}

			//����������ʾ
			else {
				cout << "����ľ������괦��������ֵͬ������������" << endl;
			}
		}
		//����������ʾ
		else {
			cout << "�����������������";
			cct_showch(x, y, ' ', 0, 7, 30);
			cct_gotoxy(0, y);
		}
	}
}


/***************************************************************************
�������ƣ�output_array_number
��    �ܣ�������־���
���������row->����.column->����
�� �� ֵ��
˵    ����canshu���ڲ������ƣ�Ϊ0ʱ���������Ϊ0�������������ֵ�����
							  Ϊ1ʱֱ��������־���
***************************************************************************/
void output_array_number(struct shuzu* array, int row, int column, int canshu, int max_of_number, const char* const prompt)
{
	if ((prompt == NULL) || (strlen(prompt) == 0))
		cout << endl << "���س�������";
	else
		cout << endl << prompt;
	cout << endl;


	int i, j, k;//ѭ������
	//ֻ����array.number[i][j]û�г�ʼֵ��ʱ���ִ�д˲�
	if (canshu == 0) {
		random_number_generation(array, max_of_number, row, column);
	}

	//��ʼ������������
	cout << "  |";
	for (j = 1; j <= column; j++) {
		cout << "  " << j - 1;
	}
	cout << endl;
	k = 3 * column;
	cout << "--+" << setfill('-') << setw(k) << "-" << endl;//��ӡ���߽���
	for (i = 1; i <= row; i++) {
		cout << (char)('A' - 1 + i) << " |";//��ӡ���߽���
		for (j = 1; j <= column; j++) {
			if (array->sign[i][j] == '*') {
				cout << "  ";
				cct_setcolor(14, 0);
				cout << array->number[i][j];
				cct_setcolor(0, 15);
			}
			else
				cout << "  " << array->number[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//����������������
}


/***************************************************************************
�������ƣ�output_sign
��    �ܣ�����ַ�����
���������row->����.column->����
�� �� ֵ��
˵    ����
***************************************************************************/
void output_array_sign(struct shuzu* array, int row, int column)
{
	int i, j, k;

	cout << "���ҽ�����飺" << endl;

	//��ʼ������������
	cout << "  |";
	for (j = 1; j <= column; j++) {
		cout << "  " << j - 1;
	}
	cout << endl;
	k = 3 * column;
	cout << "--+-" << setfill('-') << setw(k) << "-" << endl;//��ӡ���߽���
	for (i = 1; i <= row; i++) {
		cout << (char)('A' - 1 + i) << " |";//��ӡ���߽���
		for (j = 1; j <= column; j++) {
			cout << "  " << array->sign[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//����������������
}

/***************************************************************************
�������ƣ�search_no_recursion
��    �ܣ��÷ǵݹ�ķ�ʽѰ�Һ�������һ��ϲ��������������Ǳ��
���������row->����.column->����
�� �� ֵ��
˵    ����
***************************************************************************/
void search_no_recursion(struct shuzu& array, int row, int column)
{
	int i, j, k;
	for (k = 20; k >= 0; k--) {//���ھ����������������ĺ����꣬������Ĳ���ᳬ��10������20�ξ��ܹ�search��������
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= column; j++) {
				if (array.sign[i][j] == '*') {
					//ÿ�ζ��б�ǵ����ֽ������ܵ�Ѱ��
					//��һ������Χ������ͬ���ĸ���Ҳ�����ϱ��
					if (array.number[i - 1][j] == array.number[i][j])
						array.sign[i - 1][j] = '*';
					if (array.number[i + 1][j] == array.number[i][j])
						array.sign[i + 1][j] = '*';
					if (array.number[i][j - 1] == array.number[i][j])
						array.sign[i][j - 1] = '*';
					if (array.number[i][j + 1] == array.number[i][j])
						array.sign[i][j + 1] = '*';
				}
			}
		}
	}
}


/***************************************************************************
�������ƣ�search_recursion
��    �ܣ��õݹ�ķ�ʽѰ�Һ�������һ��ϲ�����,�������Ǳ��
���������row->����.column->����
�� �� ֵ��
˵    ����
***************************************************************************/
void search_recursion(struct shuzu* array, int row, int column, int x, int y)
{
	if (x >= 1 && x <= row && y >= 1 && y <= column) {
		//���if���ж������в�����array->sign[x-1][y]=='0'�����Ļ������ڵ�������ͬ�������������޵ݹ�
		if (array->number[x - 1][y] == array->number[x][y] && array->sign[x - 1][y] == '0') {
			array->sign[x - 1][y] = '*';
			search_recursion(array, row, column, x - 1, y);
		}
		if (array->number[x + 1][y] == array->number[x][y] && array->sign[x + 1][y] == '0') {
			array->sign[x + 1][y] = '*';
			search_recursion(array, row, column, x + 1, y);
		}
		if (array->number[x][y - 1] == array->number[x][y] && array->sign[x][y - 1] == '0') {
			array->sign[x][y - 1] = '*';
			search_recursion(array, row, column, x, y - 1);
		}
		if (array->number[x][y + 1] == array->number[x][y] && array->sign[x][y + 1] == '0') {
			array->sign[x][y + 1] = '*';
			search_recursion(array, row, column, x, y + 1);
		}
	}
	else
		return;
}


/***************************************************************************
�������ƣ�array_change_confirm
��    �ܣ�ȷ���Ƿ�����ڵ�ֵ�ϲ���ĳλ��
���������
�� �� ֵ��
˵    ����Y��ʾȷ�� N��ʾ��ȷ��������ѡ���������꣬Q��ʾֱ���˳�
***************************************************************************/
void array_change_confirm(char* confirm, int coordinate_x, int coordinate_y)
{
	int x, y;
	cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << (char)('A' - 1 + coordinate_x) << coordinate_y - 1 << "��(Y/N/Q):";
	cct_getxy(x, y);
	for (;;) {
		*confirm = _getche();
		tj_charupr(confirm);
		if (*confirm == 'Y' || *confirm == 'N' || *confirm == 'Q') {
			cout << endl;
			return;
		}
		else
			cct_gotoxy(x, y);
	}
}

/***************************************************************************
�������ƣ�array_change_zero_fall
��    �ܣ����������ĳ�α仯��0��������һ����
�� �� ֵ��
˵    ����
***************************************************************************/
void array_change_zero_fall(struct shuzu* array, int row, int column)
{
	int i, j, k;
	char t1;
	int t2;
	for (j = 1; j <= column; j++)
		for (k = 0; k <= M; k++)
			for (i = 2; i <= row; i++)
				if (array->sign[i][j] == '*') {
					//������������λ�õ����ֺͱ��
					t2 = array->sign[i - 1][j];
					array->sign[i - 1][j] = array->sign[i][j];
					array->sign[i][j] = t2;

					t1 = array->number[i - 1][j];
					array->number[i - 1][j] = array->number[i][j];
					array->number[i][j] = t1;
				}
}


/***************************************************************************
�������ƣ�array_change
��    �ܣ��������һ�ε������仯������ɸ������е������������һ���ĵ÷�
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void array_change(struct shuzu* array, int row, int column, int x, int y, int* score, int* target, int* max_of_number)
{
	int one_step_score = 0;//��ʾ��һ���ķ���
	int i, j;//ѭ������

	//��ֵͬ�鲢
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->sign[i][j] == '*') {
				if (i == x && j == y)
					array->number[i][j]++;
				else
					array->number[i][j] = 0;
				one_step_score += 3 * array->number[x][y];//������һ�����õ��ĒO��
			}
		}
	}
	output_array_number(array, row, column, 1, *max_of_number, "��ֵͬ�鲢�������(��ͬɫ���)��");

	*score += one_step_score;
	cout << "���ε÷֣�" << one_step_score << " �ܵ÷֣�" << *score << " �ϳ�Ŀ�꣺" << *target << endl;

	*max_of_number = search_max_of_number(array, row, column);

	wait_for_enter("���س����������������0����...");

	//��0�����������
	array->sign[x][y] = '0';
	array_change_zero_fall(array, row, column);
	output_array_number(array, row, column, 1, *max_of_number, "��0�������(��ͬɫ���)��");


	wait_for_enter("���س���������ֵ���...");
	//������ֵ�����
	output_array_number(array, row, column, 0, *max_of_number, "��ֵ���������(��ͬɫ���)��");

}



//����ֵΪ���־�����������
int search_max_of_number(struct shuzu* array, int row, int column)
{
	int max_of_number = 3;
	int i, j;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (array->number[i][j] > max_of_number)
				max_of_number = array->number[i][j];
		}
	}
	return max_of_number;
}



//�Է���������г�ʼ����ʹÿ��Ԫ�ض�Ϊ'0'
void initialization_array_sign(struct shuzu* array)
{
	int i, j;
	for (i = 1; i < M; i++) {
		for (j = 1; j < N; j++) {
			array->sign[i][j] = '0';
		}
	}
}


/***************************************************************************
�������ƣ�initial_judge
��    �ܣ���һ�κϳ����֮����һ�κϳɿ�ʼ֮ǰ���ж���Ϸ�Ƿ��ܼ������У��Լ��ж��Ƿ�ﵽ�˺ϳ�Ŀ��
***************************************************************************/
void initial_judge(char option, struct shuzu* array, int row, int column, int max_of_number, int* target, int* judge_of_end)
{
	int i, j;
	*judge_of_end = 1;//*judge_of_endΪ1��ʾ��ϷҪ���Ƚ�����Ϊ0��ʾ��Ϸ�ܼ�������
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= column; j++) {
			if (!((array->number[i][j] - array->number[i - 1][j]) * (array->number[i][j] - array->number[i + 1][j])
				* (array->number[i][j] - array->number[i][j - 1]) * (array->number[i][j] - array->number[i][j + 1]))) {
				*judge_of_end = 0;//ֻҪ��һ���������Խ��кϳɣ���ô*judge_if_end��Ϊ0
			}
		}
	}

	if (max_of_number == *target) {//�ж��Ƿ�ﵽ�ϳ�Ŀ��
		if (option == '4') {
			cout << endl;
			cct_setcolor(14, 4);
			cout << "�Ѿ��ϳɵ�" << *target << endl;
			cct_setcolor(0, 15);
			wait_for_enter("���س�����������ߵ�Ŀ�����...");
		}
		(*target)++;
	}

	if (*judge_of_end) {
		cout << endl;
		cct_setcolor(14, 4);
		if (option == '9')
			cct_gotoxy(0, 4 + 4 * row);
		cout << "�޿ɺϲ������Ϸ������" << endl;
		cct_setcolor(0, 15);
		return;
	}
}