//2152988 杨恺铭 计科
#include<iostream>
#include<cmath>
using namespace std;
void not_quadradic(void);
void root_in_rear0(void);
void root_in_imaginary(void);
void root_in_rear(void);
double a, b, c;

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double deta;
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
		root_in_rear0();
	else if (deta > 0)
		root_in_rear();
	else
		root_in_imaginary();
	return 0;
}