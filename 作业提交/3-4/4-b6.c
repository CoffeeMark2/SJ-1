/*2152988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/***************************************************************************
  函数名称：
  功    能：返回n阶legendre多项式的值
  输入参数：
  返 回 值：
  说    明：函数名、形参、返回类型均不准动
***************************************************************************/
double legendre(double x, int n)
{
	if (0 == n)
		return 1;
	else if (1 == n)
		return x;
	else
		return ((2 * n - 1) * x * legendre(x, n - 1)
			- (n - 1) * legendre(x, n - 2)) / (double)n;
}

int main()
{
	printf("计算legendre，请输入x和n的值\n");
	double x;
	int n;
	scanf("%lf%d", &x, &n);
	double result=legendre(x, n);
	printf("legendre[%d](%f)=%f\n", n, x, result);
	return 0;
} 