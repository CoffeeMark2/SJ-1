/*21529988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
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
		else if (!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && day > 28) {
			printf("�������-�����¹�ϵ�Ƿ�\n");
			ret = false;
		}
	}

	int sum = 0;
	if (ret) {
		switch (month) {
			case 12:
				sum += 30;
			case 11:
				sum += 31;
			case 10:
				sum += 30;
			case 9:
				sum += 31;
			case 8:
				sum += 31;
			case 7:
				sum += 30;
			case 6:
				sum += 31;
			case 5:
				sum += 30;
			case 4:
				sum += 31;
			case 3:
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
					sum += 29;
				else
					sum += 28;
			case 2:
				sum += 31;
			case 1:
				sum += day;
				break;
			default:
				break;
		}
		printf("%d-%d-%d��%d��ĵ�%d��\n",year,month,day,year,sum);
	}

	return 0;
}
