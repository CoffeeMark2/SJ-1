/*2152988 јЖїЖ СовэГъ*/
#include <iostream>
using namespace std;

int main()
{
	int i, j, k, sum = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				cout << "*";
				sum++;
				if (3 == k)
					break;
				/************/
			}
			cout << ' ';
			if (1 == j)
				break;
			/************/
		}
		cout << endl;
		if (2 == i)
			break;
		/************/
	}
	cout << "sum=" << sum << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;

	return 0;
}
