//2152988 ������ �ƿ�
#include<iostream>
#include<cmath>
#include"4-b19.h"
using namespace std;



int main()
{
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	double a, b, c, deta;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	deta = b * b - 4 * a * c;
	if (fabs(a) < 1e-6)
		not_quadradic();
	else if (fabs(deta) < 1e-6)
		root_in_rear(a, b);
	else if (deta > 0)
		root_in_rear(a, b, c);
	else
		root_in_imaginary(a, b, c);
	return 0;
}