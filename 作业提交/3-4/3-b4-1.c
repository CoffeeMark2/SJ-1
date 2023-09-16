/*21529988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	const double Pi = 3.14159;
	printf("请输入三角形的两边及其夹角(角度)\n");
	int a, b, deg;
	scanf("%d %d %d", &a, &b, &deg);
	double rad = deg / 360.0 * 2 * Pi;
	float s = (float)(0.5 * a * b * sin(rad));
	printf("三角形面积为 : %.3f\n", s);

	return 0;
}
