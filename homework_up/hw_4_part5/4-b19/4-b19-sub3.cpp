//2152988 ������ �ƿ�
#include<iostream>
#include<cmath>
using namespace std;
void root_in_rear(double a, double b)
{
	double ans = (-b) / (2 * a);
	if (fabs(ans) < 1e-6)
		ans = 0;
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << ans << endl;
}