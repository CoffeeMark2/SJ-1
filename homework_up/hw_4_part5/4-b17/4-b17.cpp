//2152988 杨恺铭 计科
#include<iostream>
#include<cmath>
using namespace std;

void not_quadradic(void)
{
	cout << "不是一元二次方程" << endl;
}
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
void root_in_rear(double a, double b)
{
	double ans = (-b) / (2 * a);
	if (fabs(ans) < 1e-6)
		ans = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << ans << endl;
}
void root_in_imaginary(double a, double b, double c)
{
	double deta_s = sqrt(-(b * b - 4 * a * c));
	double real = (-b) / (2 * a);
	
	double imaginary = deta_s / (2 * a);
	cout << "有两个虚根：" << endl;
	if (fabs(real) < 1e-6) {
		cout << "x1=" << imaginary << 'i' << endl;
		cout << "x2=" << '-' << imaginary << 'i' << endl;
	}
	else {
		if (fabs(imaginary - 1) < 1e-6) {
			cout << "x1=" << real << "+i" << endl;
			cout << "x2=" << real << "-i" << endl;
		}
		else {
			cout << "x1=" << real << '+' << imaginary << 'i' << endl;
			cout << "x2=" << real << '-' << imaginary << 'i' << endl;
		}
	}
}
int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double a, b, c,deta;
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