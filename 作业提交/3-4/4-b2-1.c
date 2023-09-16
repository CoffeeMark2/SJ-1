/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/***************************************************************************
  �������ƣ�DayValue
  ��    �ܣ�������£�����·ݶ�Ӧ������
  ���������
  �� �� ֵ������
  ˵    ����
***************************************************************************/
int DayValue(int year, int month)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	int daymax = 28;
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		daymax += 3;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daymax += 2;
	else
		daymax += leap;
	return daymax;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int Zeller(int year, int month, int day)
{
	int week = -1;
	if (month == 1 || month == 2) {
		month += 12;
		--year;
	}
	int c = year / 100;
	week = year % 100 + (year % 100 / 4) + (c / 4) - 2 * c
		+ (13 * (month + 1) / 5) + day - 1;
	while (week < 0)
		week += 7;
	return week % 7;
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
	int year, month, day;
	int ret=-1;
	while (1) {
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d%d%d", &year, &month,&day);
		if (ret < 3)
			printf("����Ƿ�������������\n");
		else if (year < 1900 || year > 2100) {
			printf( "��ݲ���ȷ������������\n");
		}
		else if (month < 1 || month>12) {
			printf( "�·ݲ���ȷ������������\n");
		}
		else if (day<1 || day > DayValue(year, month)) {
			printf( "�ղ���ȷ������������\n");
		}
		else {
			break;
		}
		while (getchar() != '\n')
			;

	}

	printf( "����");

	switch (Zeller(year, month, day)) {
		case 0:
			printf( "��");
			break;
		case 1:
			printf( "һ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	printf("\n");


	return 0;
}
