//2152988 ������ �ƿ�
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
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
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