/* 2152988 �ƿ� ������ */
#include <iostream>
using namespace std;
const int M = 101;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int light[M] = { -1 };
	for (int i = 1; i < M; i++) {
		light[i] = 0;
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = i; j <= 100; j += i) {
			light[j]=!light[j];
		}
	}
	for (int i = 1; i < M; i++) {
		if (light[i]) {
			if (100 == i)
				cout << i;
			else
				cout << i << ' ';
		}
	}
	cout << endl;

	return 0;
}