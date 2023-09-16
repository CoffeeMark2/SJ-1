/* 2153299 �ư� ��Ƿ� */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include "cmd_console_tools.h"
#include "90-01-b2.h"
#include "common_menu_and_tools.h"
using namespace std;

/*
			 ��main������menu�����������йصĺ���
													   */


int main()
{
	srand((unsigned int)(time(0)));
	int row, column, target, score = 0;
	int i, j;
	char option = '\0';
	struct shuzu array;
	const int number_of_option = 10;
	const char possible_option[number_of_option] = { '1','2','3','4','5','6','7','8','9','0' };
	const char* content[number_of_option] =
	{ "�������ҳ��ɺϳɵ����ǣ��ǵݹ飩",
		"�������ҳ��ɺϳɵ����ǣ��ݹ飩",
		"���������һ�κϳɣ��ֲ�����ʾ��",
		"�����������棨�ֲ�����ʾ��",
		"αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�",
		"αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�",
		"αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��",
		"αͼ�ν������һ�κϳɣ��ֲ��裩",
		"αͼ�ν��������棨֧����꣩",
		"�˳�" };

	for (;;) {
		//ÿ��ѭ���������Լ�����������Ӧ��ʼ��
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				array.number[i][j] = 0;
				array.sign[i][j] = '0';
			}
		}
		score = 0;

		cct_cls();
		option = common_menu(number_of_option, possible_option, content);
		//֮����Ǹ���ѡ��Ĳ�ͬ��ѡ����õĺ���
		if (option == '1') {
			int coordinate_x, coordinate_y;
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			output_array_number(&array, row, column, 0, 3, "��ǰ���飺");//�����ʼ����
			input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//����ָ���ϳɵ��к���
			search_no_recursion(array, row, column);//Ѱ������λ����ͬ��
			output_array_sign(&array, row, column);//����ڲ��������
			output_array_number(&array, row, column, 1, 3, "��ǰ����(��ͬɫ��ʶ)��");//������鲢ͻ����ʾ����ǵ���
			common_pause_end();
		}
		if (option == '2') {
			int coordinate_x, coordinate_y;
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			output_array_number(&array, row, column, 0, 3, "��ǰ���飺");//�����ʼ����
			input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//����ָ���ϳɵ��к���
			search_recursion(&array, row, column, coordinate_x, coordinate_y);//Ѱ������λ����ͬ��
			output_array_sign(&array, row, column);//����ڲ��������
			output_array_number(&array, row, column, 1, 3, "��ǰ����(��ͬɫ��ʶ)��");//������鲢ͻ����ʾ����ǵ���
			common_pause_end();
		}
		if (option == '3') {
			int coordinate_x, coordinate_y;//������ʾÿ��ѡ���λ�õ�����
			int max_of_number = 3;//��ʾ���������е����ֵ
			char confirm;//����ȷ�Ϻϳɣ�ȡ���ϳ��Լ��˳��ı���
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			output_array_number(&array, row, column, 0, max_of_number, "��ǰ���飺");//�����ʼ����
			input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//����ָ���ϳɵ��к���
			search_recursion(&array, row, column, coordinate_x, coordinate_y);//Ѱ������λ����ͬ��
			output_array_sign(&array, row, column);//����ڲ��������
			output_array_number(&array, row, column, 1, max_of_number, "��ǰ����(��ͬɫ��ʶ)��");//������鲢ͻ����ʾ����ǵ���
			array_change_confirm(&confirm, coordinate_x, coordinate_y);//ȷ���Ƿ���кϳ��Լ��Ƿ��˳�
			if (confirm == 'Y')
				array_change(&array, row, column, coordinate_x, coordinate_y, &score, &target, &max_of_number);//���һ������ı仯

			common_pause_end();
		}
		if (option == '4') {
			int coordinate_x, coordinate_y;//������ʾÿ��ѡ���λ�õ�����
			int max_of_number = 3;//��ʾ���������е����ֵ
			char confirm;//��ʾ���������е����ֵ
			int judge_of_end = 1;//��ʾ��Ϸ�Ƿ��ܼ������еı�����Ϊ1���ܽ���
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			for (;;) {
				initialization_array_sign(&array);//���ַ�������г�ʼ��
				initial_judge(option, &array, row, column, max_of_number, &target, &judge_of_end);//�ж���Ϸ�Ƿ��ܼ�������
				if (judge_of_end)
					break;
				output_array_number(&array, row, column, 0, max_of_number, "��ǰ���飺");//�����ǰ����
				input_coordinate(&array, row, column, &coordinate_x, &coordinate_y);//����ָ���ϳɵ��к���
				search_recursion(&array, row, column, coordinate_x, coordinate_y);//Ѱ������λ����ͬ��
				output_array_sign(&array, row, column);//����ڲ��������
				output_array_number(&array, row, column, 1, max_of_number, "��ǰ����(��ͬɫ��ʶ)��");//������鲢ͻ����ʾ����ǵ���
				array_change_confirm(&confirm, coordinate_x, coordinate_y);//ȷ���Ƿ���кϳ��Լ��Ƿ��˳�
				if (confirm == 'Y')//����ȷ���Ƿ�Ҫ���кϳ�
					;
				else if (confirm == 'N')
					continue;
				else
					break;
				array_change(&array, row, column, coordinate_x, coordinate_y, &score, &target, &max_of_number);//���һ������ı仯
				wait_for_enter("���κϳɽ��������س���������һ�ֵĺϳ�...");
			}
			common_pause_end();
		}

		if (option == '5') {
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, 3, row, column);//�����������������ֵ
			console_output_original_form(row, column, option);//��ӡ��ʼ�ı���ޱ߿�
			console_output_original_array(&array, row, column, option);//��ӡ��ʼ��ÿ��С����
			cct_gotoxy(0, 4 + 3 * row);
			common_pause_end();
		}
		if (option == '6') {
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, 3, row, column);//�����������������ֵ
			console_output_original_form(row, column, option);//��ӡ��ʼ�ı���б߿�
			console_output_original_array(&array, row, column, option);//��ӡ��ʼ��ÿ��С����
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}
		if (option == '7') {
			int max_of_number = 3;
			target = 3;
			int loop_q = 1;//����������q��ʱ������˳�
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, 3, row, column);//�����������������ֵ
			console_output_original_form(row, column, option);//��ӡ��ʼ�ı���б߿�
			console_output_original_array(&array, row, column, option);//��ӡ��ʼ��ÿ��С����
			choose_ketboard_and_mouse(option, &array, row, column, &max_of_number, &score, &target, &loop_q);//���������̵�״̬
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}
		if (option == '8') {
			int max_of_number = 3;
			target = 3;
			int loop_q = 1;//����������q��ʱ������˳�
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, max_of_number, row, column);//�����������������ֵ
			console_output_original_form(row, column, option);//��ӡ��ʼ�ı���б߿�
			console_output_original_array(&array, row, column, option);//��ӡ��ʼ��ÿ��С����
			choose_ketboard_and_mouse(option, &array, row, column, &max_of_number, &score, &target, &loop_q);//���������̵�״̬
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}
		if (option == '9') {
			int max_of_number = 3;
			int judge_of_end = 1;
			int loop_q = 1;//����������q��ʱ�����ֱ�˳���ѡ��
			cct_cls();
			input_row_and_column(&row, &column, &target, option);
			random_number_generation(&array, max_of_number, row, column);//�����������������ֵ
			console_output_original_form(row, column, option);//��ӡ��ʼ�ı���б߿�
			console_output_original_array(&array, row, column, option);//��ӡ��ʼ��ÿ��С����
			//����ѭ����ȡ����״̬������Ҫֹͣ��ʱ���Զ��˳�
			for (; loop_q;) {
				initial_judge(option, &array, row, column, max_of_number, &target, &judge_of_end);
				if (judge_of_end)//����ж�û�п��Ժϳɵ�ֵ�ˣ��ͽ�����Ϸ
					break;

				initialization_array_sign(&array);//���ַ���������г�ʼ��
				choose_ketboard_and_mouse(option, &array, row, column, &max_of_number, &score, &target, &loop_q);//���������̵�״̬
			}
			cct_gotoxy(0, 3 + 4 * row);
			common_pause_end();
		}

		//optionΪ0���˳�
		if (option == '0') {
			int x, y;
			char pause;
			cct_getxy(x, y);
			cct_showstr(0, y + 4, "�밴���������...");
			pause = _getch();
			break;
		}
	}
	return 0;
}