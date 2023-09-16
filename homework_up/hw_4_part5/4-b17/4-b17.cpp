//2152988 ������ �ƿ�
#include<iostream>
#include<cmath>
using namespace std;

void not_quadradic(void)
{
	cout << "����һԪ���η���" << endl;
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
	cout << "����������ʵ����" << endl;
	cout << "x1=" << ans1 << endl;
	cout << "x2=" << ans2 << endl;
}
void root_in_rear(double a, double b)
{
	double ans = (-b) / (2 * a);
	if (fabs(ans) < 1e-6)
		ans = 0;
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << ans << endl;
}
void root_in_imaginary(double a, double b, double c)
{
	double deta_s = sqrt(-(b * b - 4 * a * c));
	double real = (-b) / (2 * a);
	
	double imaginary = deta_s / (2 * a);
	cout << "�����������" << endl;
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
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
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