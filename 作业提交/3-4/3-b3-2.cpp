/*2152988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	cout << "������[0-100��)֮�������:" << endl;
	double a, b;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
	cin >> a;
	a1 = int(a / 10) % 10;
	a2 = int(a / 100) % 10;
	a3 = int(a / 1000) % 10;
	a4 = int(a / 10000) % 10;
	a5 = int(a / 100000) % 10;
	a6 = int(a / 1000000) % 10;
	a7 = int(a / 10000000) % 10;
	a8 = int(a / 100000000) % 10;
	a9 = int(a / 1000000000) % 10;
	a0 = int(a - a9 * pow(10, 9)) % 10;
	b = a - a9 * pow(10, 9) - a8 * pow(10, 8) - a7 * pow(10, 7)
		- a6 * pow(10, 6) - a5 * pow(10, 5) - a4 * pow(10, 4)
		- a3 * pow(10, 3) - a2 * pow(10, 2) - a1 * pow(10, 1)
		- a0 + 0.001;
	b1 = int(b * 10) % 10;
	b2 = int(b * 100) % 10;

	cout << setiosflags(ios::left);
	cout << setw(7) << "ʮ��λ" << ": " << a9 << endl;
	cout << setw(7) << "��λ" << ": " << a8 << endl;
	cout << setw(7) << "ǧ��λ" << ": " << a7 << endl;
	cout << setw(7) << "����λ" << ": " << a6 << endl;
	cout << setw(7) << "ʮ��λ" << ": " << a5 << endl;
	cout << setw(7) << "��λ" << ": " << a4 << endl;
	cout << setw(7) << "ǧλ" << ": " << a3 << endl;
	cout << setw(7) << "��λ" << ": " << a2 << endl;
	cout << setw(7) << "ʮλ" << ": " << a1 << endl;
	cout << setw(7) << "Բ" << ": " << a0 << endl;
	cout << setw(7) << "��" << ": " << b1 << endl;
	cout << setw(7) << "��" << ": " << b2 << endl;
	return 0;
}
