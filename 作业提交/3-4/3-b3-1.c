/*21529988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	printf("������[0-100��)֮�������:\n");
	double a, b;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
	scanf("%lf", &a);
	a1 = (int)(a / 10) % 10;
	a2 = (int)(a / 100) % 10;
	a3 = (int)(a / 1000) % 10;
	a4 = (int)(a / 10000) % 10;
	a5 = (int)(a / 100000) % 10;
	a6 = (int)(a / 1000000) % 10;
	a7 = (int)(a / 10000000) % 10;
	a8 = (int)(a / 100000000) % 10;
	a9 = (int)(a / 1000000000) % 10;
	a0 = (int)(a - a9 * pow(10, 9)) % 10;
	b = a - a9 * pow(10, 9) - a8 * pow(10, 8) - a7 * pow(10, 7)
		- a6 * pow(10, 6) - a5 * pow(10, 5) - a4 * pow(10, 4)
		- a3 * pow(10, 3) - a2 * pow(10, 2) - a1 * pow(10, 1)
		- a0 + 0.001;
	b1 = (int)(b * 10) % 10;
	b2 = (int)(b * 100) % 10;

	printf("%-7s: %d\n", "ʮ��λ", a9);
	printf("%-7s: %d\n", "��λ", a8);
	printf("%-7s: %d\n", "ǧ��λ", a7);
	printf("%-7s: %d\n", "����λ", a6);
	printf("%-7s: %d\n", "ʮ��λ", a5);
	printf("%-7s: %d\n", "��λ", a4);
	printf("%-7s: %d\n", "ǧλ", a3);
	printf("%-7s: %d\n", "��λ", a2);
	printf("%-7s: %d\n", "ʮλ", a1);
	printf("%-7s: %d\n", "Բ", a0);
	printf("%-7s: %d\n", "��", b1);
	printf("%-7s: %d\n", "��", b2);

	return 0;
}
