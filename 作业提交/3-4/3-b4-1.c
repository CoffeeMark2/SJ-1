/*21529988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	const double Pi = 3.14159;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	int a, b, deg;
	scanf("%d %d %d", &a, &b, &deg);
	double rad = deg / 360.0 * 2 * Pi;
	float s = (float)(0.5 * a * b * sin(rad));
	printf("���������Ϊ : %.3f\n", s);

	return 0;
}
