/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int IsLeap(int year)
{
	return year % 4 == 0 && year % 100 != 0
		|| year % 400 == 0;
}
int DayNo(int year, int month, int day)
{
	int no = 0;
	int monthvalue[13] = { -1,31,28,31,30,31,30,
		31,31,30,31,30,31 };
	if (IsLeap(year))
		monthvalue[2]++;
	for (int i = 1; i < month; i++) {
		no += monthvalue[i];
	}
	return no + day;
}

int main()
{
	printf("�������꣬�£���\n");
	int year, month, day;
	scanf("%d %d %d", &year, &month, &day);
	bool ret = true;
	if (month < 1 || month>12) {
		printf("�������-�·ݲ���ȷ\n");
		ret = false;
	}
	else if (day < 1 || day>31) {
		printf("�������-�����¹�ϵ�Ƿ�\n");
		ret = false;
	}
	else if ((month == 4 || month == 6 ||
		month == 9 || month == 11) && day > 30) {
		printf("�������-�����¹�ϵ�Ƿ�\n");
		ret = false;
	}
	else if (month == 2) {
		if (day > 29) {
			printf("�������-�����¹�ϵ�Ƿ�\n");
			ret = false;
		}
		else if (!(IsLeap(year)) && day > 28) {
			printf("�������-�����¹�ϵ�Ƿ�\n");
			ret = false;
		}
	}

	printf("%d-%d-%d��%d��ĵ�%d��\n", 
		year, month, day, year, DayNo(year, month, day));
	return 0;
}