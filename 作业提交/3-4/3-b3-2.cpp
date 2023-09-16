/*2152988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
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
	cout << setw(7) << "十亿位" << ": " << a9 << endl;
	cout << setw(7) << "亿位" << ": " << a8 << endl;
	cout << setw(7) << "千万位" << ": " << a7 << endl;
	cout << setw(7) << "百万位" << ": " << a6 << endl;
	cout << setw(7) << "十万位" << ": " << a5 << endl;
	cout << setw(7) << "万位" << ": " << a4 << endl;
	cout << setw(7) << "千位" << ": " << a3 << endl;
	cout << setw(7) << "百位" << ": " << a2 << endl;
	cout << setw(7) << "十位" << ": " << a1 << endl;
	cout << setw(7) << "圆" << ": " << a0 << endl;
	cout << setw(7) << "角" << ": " << b1 << endl;
	cout << setw(7) << "分" << ": " << b2 << endl;
	return 0;
}
