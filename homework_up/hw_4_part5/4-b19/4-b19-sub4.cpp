//2152988 ������ �ƿ�
#include<iostream>
#include<cmath>
using namespace std;
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