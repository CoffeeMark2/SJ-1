/*21529988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;
	int a, b1, b2, b3, b4, b5;
	cin >> a;
	b1 = a % 10;
	b2 = a / 10 % 10;
	b3 = a / 100 % 10;
	b4 = a / 1000 % 10;
	b5 = a / 10000 % 10;
	cout << "万位 : " << b5 << endl;
	cout << "千位 : " << b4 << endl;
	cout << "百位 : " << b3 << endl;
	cout << "十位 : " << b2 << endl;
	cout << "个位 : " << b1 << endl;

	return 0;
}
