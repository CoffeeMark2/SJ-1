/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����n��legendre����ʽ��ֵ
  ���������
  �� �� ֵ��
  ˵    �������������βΡ��������;���׼��
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
	printf("����legendre��������x��n��ֵ\n");
	double x;
	int n;
	scanf("%lf%d", &x, &n);
	double result=legendre(x, n);
	printf("legendre[%d](%f)=%f\n", n, x, result);
	return 0;
} 