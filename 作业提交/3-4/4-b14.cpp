/*2152988 计科 杨恺铭*/
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}
int max(int a, int b, int c)
{
	return (a > b ? a : (c > b ? c : b));
}
int max(int a, int b, int c,int d)
{
	return max(max(a,b),max(c,d));
}
int main()
{
	int n, a = 0, b = 0, c = 0, d = 0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (n >= 2 && n <= 4) {
			if (n == 2) {
				cin >> a >> b;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (a > 0 && b > 0) {
					cout << "max=" << max(a, b) << endl;
					break;
				}
			}
			else if (n == 3) {
				cin >> a >> b >> c;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (a > 0 && b > 0 && c > 0) {
					cout << "max=" << max(a, b,c) << endl;
					break;
				}
			}
			else {
				cin >> a >> b >> c >> d;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (a > 0 && b > 0 && c > 0 && d > 0) {
					cout << "max=" << max(a, b,c,d) << endl;
					break;
				}
			}

		}
		else {
			cout << "个数输入错误\n";
			return -1;
		}

	}


	return 0;
}