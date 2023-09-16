//2152988 杨恺铭 计科
#include<iostream>
#include<cmath>
using namespace std;
void root_in_rear(double a, double b)
{
	double ans = (-b) / (2 * a);
	if (fabs(ans) < 1e-6)
		ans = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << ans << endl;
}