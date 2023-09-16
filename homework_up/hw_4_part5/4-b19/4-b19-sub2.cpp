//2152988 杨恺铭 计科
#include<iostream>
#include<cmath>
using namespace std;
void root_in_rear(double a, double b, double c)
{
	double deta_s = sqrt(b * b - 4 * a * c);
	double ans1 = (-b + deta_s) / (2 * a);
	if (fabs(ans1) < 1e-6)
		ans1 = 0;
	double ans2 = (-b - deta_s) / (2 * a);
	if (fabs(ans2) < 1e-6)
		ans2 = 0;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << ans1 << endl;
	cout << "x2=" << ans2 << endl;
}