/*21529988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iomanip> 
int main()
{
	double m;
	printf("����������ֵ��\n");
	scanf("%lf", &m);
	m += 0.001;
	//����������!

	int y50 = 0, y20 = 0, y10 = 0, y5 = 0, y1 = 0,
		j5 = 0, j1 = 0, f5 = 0, f2 = 0, f1 = 0, sum = 0;

	if (m >= 50) {
		m -= 50;
		y50 += 1;
		sum += 1;
	}
	if (m >= 20) {
		m -= 20;
		y20 += 1;
		sum += 1;
	}
	if (m >= 20) {
		m -= 20;
		y20 += 1;
		sum += 1;
	}
	if (m >= 10) {
		m -= 10;
		y10 += 1;
		sum += 1;
	}
	if (m >= 5) {
		m -= 5;
		y5 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 0.5) {
		m -= 0.5;
		j5 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.05) {
		m -= 0.05;
		f5 += 1;
		sum += 1;
	}
	if (m >= 0.02) {
		m -= 0.02;
		f2 += 1;
		sum += 1;
	}
	if (m >= 0.02) {
		m -= 0.02;
		f2 += 1;
		sum += 1;
	}
	if (m >= 0.01) {
		m -= 0.01;
		f1 += 1;
		sum += 1;
	}

	printf("��%d�����㣬�������£�\n",sum);
	if (y50)
		printf("50Ԫ : %d��\n", y50);
	if (y20)
		printf("20Ԫ : %d��\n", y20);
	if (y10)
		printf("10Ԫ : %d��\n", y10);
	if (y5)
		printf("5Ԫ  : %d��\n", y5);
	if (y1)
		printf("1Ԫ  : %d��\n", y1);
	if (j5)
		printf("5��  : %d��\n", j5);
	if (j1)
		printf("1��  : %d��\n", j1);
	if (f5)
		printf("5��  : %d��\n", f5);
	if (f2)
		printf("2��  : %d��\n", f2);
	if (f1)
		printf("1��  : %d��\n", f1);


	return 0;
}
