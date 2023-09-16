/*2152988 计科 杨恺铭*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double m;
	cout << "请输入找零值：" << endl;
	cin >> m;
	m += 0.001;
	//浮点数误差！！!

	int y50 = 0, y20 = 0, y10 = 0, y5 = 0, y1 = 0,
		j5 = 0, j1 = 0, f5 = 0, f2 = 0, f1 = 0, sum = 0;

	if (m >= 50) {
		m -= 50;
		y50 += 1;
		sum += 1;
	}
	if (m >= 20) {
		m -= 20;
		y20 += 1;
		sum += 1;
	}
	if (m >= 20) {
		m -= 20;
		y20 += 1;
		sum += 1;
	}
	if (m >= 10) {
		m -= 10;
		y10 += 1;
		sum += 1;
	}
	if (m >= 5) {
		m -= 5;
		y5 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 1) {
		m -= 1;
		y1 += 1;
		sum += 1;
	}
	if (m >= 0.5) {
		m -= 0.5;
		j5 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.1) {
		m -= 0.1;
		j1 += 1;
		sum += 1;
	}
	if (m >= 0.05) {
		m -= 0.05;
		f5 += 1;
		sum += 1;
	}
	if (m >= 0.02) {
		m -= 0.02;
		f2 += 1;
		sum += 1;
	}
	if (m >= 0.02) {
		m -= 0.02;
		f2 += 1;
		sum += 1;
	}
	if (m >= 0.01) {
		m -= 0.01;
		f1 += 1;
		sum += 1;
	}

	cout << "共" << sum << "张找零，具体如下：" << endl;
	if (y50)
		cout << "50元 : " << y50 << "张\n";
	if (y20)
		cout << "20元 : " << y20 << "张\n";
	if (y10)
		cout << "10元 : " << y10 << "张\n";
	if (y5)
		cout << "5元  : " << y5 << "张\n";
	if (y1)
		cout << "1元  : " << y1 << "张\n";
	if (j5)
		cout << "5角  : " << j5 << "张\n";
	if (j1)
		cout << "1角  : " << j1 << "张\n";
	if (f5)
		cout << "5分  : " << f5 << "张\n";
	if (f2)
		cout << "2分  : " << f2 << "张\n";
	if (f1)
		cout << "1分  : " << f1 << "张\n";

	return 0;
}