/*2152988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	const double Pi = 3.14159;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	int a, b, deg;
	cin >> a >> b >> deg;
	double rad = deg / 360.0 * 2 * Pi;
	float s = 0.5 * a * b * sin(rad);
	cout << "���������Ϊ : " << setiosflags(ios::fixed) 
		<< setprecision(3) << s << endl;
	return 0;
}