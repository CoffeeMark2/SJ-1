/*21529988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iomanip> 
int main()
{
	double m;
	printf("请输入找零值：\n");
	scanf("%lf", &m);
	m += 0.001;
	//浮点数误差！！!

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

	printf("共%d张找零，具体如下：\n",sum);
	if (y50)
		printf("50元 : %d张\n", y50);
	if (y20)
		printf("20元 : %d张\n", y20);
	if (y10)
		printf("10元 : %d张\n", y10);
	if (y5)
		printf("5元  : %d张\n", y5);
	if (y1)
		printf("1元  : %d张\n", y1);
	if (j5)
		printf("5角  : %d张\n", j5);
	if (j1)
		printf("1角  : %d张\n", j1);
	if (f5)
		printf("5分  : %d张\n", f5);
	if (f2)
		printf("2分  : %d张\n", f2);
	if (f1)
		printf("1分  : %d张\n", f1);


	return 0;
}
