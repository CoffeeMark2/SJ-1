/*21529988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "������һ��[1..30000]�������:" << endl;
	int a, b1, b2, b3, b4, b5;
	cin >> a;
	b1 = a % 10;
	b2 = a / 10 % 10;
	b3 = a / 100 % 10;
	b4 = a / 1000 % 10;
	b5 = a / 10000 % 10;
	cout << "��λ : " << b5 << endl;
	cout << "ǧλ : " << b4 << endl;
	cout << "��λ : " << b3 << endl;
	cout << "ʮλ : " << b2 << endl;
	cout << "��λ : " << b1 << endl;

	return 0;
}
