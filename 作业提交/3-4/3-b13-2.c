/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int  ret;
	int year ,month, week;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d%d", &year,&month);
		if (ret == 2 && (year >= 2000 && year <= 2030 &&
			month >= 1 && month <= 12))
			break;
		if (ret < 2)
			while(getchar()!='\n')
				;
		printf("����Ƿ�������������\n"); //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 
	}
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : "
			,year,month);
		ret = scanf("%d", &week);
		if (ret == 1 && (week >= 0 && week <= 6))
			break;
		if (ret < 1)
			while(getchar()!='\n')
				;
		printf("����Ƿ�������������\n"); //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 
	}

	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n",year,month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	int daymax = 28;
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		daymax += 3;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daymax += 2;
	else
		daymax += leap;
	int count = daymax + week;//��ӡ����
	for (int i = 1; i <= count; i++) {
		if (i <= week)
			printf( "        ");
		else {
			printf("%4d" "    ",i-week);
		}
		if (i % 7 == 0)
			printf( "\n");
	}
	printf("\n");

	return 0;
}
