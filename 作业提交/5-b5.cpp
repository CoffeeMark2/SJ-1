/*2152988 �ƿ� ������*/
#include <iostream>
#include<iomanip>
using namespace std;

const int M = 1000;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

int main()
{
	int a, num = 0;
	int array[M];
	cout << "������ɼ������1000��������-1����" << endl;
	cin >> a;
	while (a >= 0 && num < M) {
		array[num++] = a;
		cin >> a;
	}
	if (0 == num) {
		cout << "����Ч����" << endl;
		return -1;
	}
	cout << "���������Ϊ:" << endl;
	int i;
	for (i = 0; i < num; i++) {
		cout << array[i] << ' ';
		if ((i+1) % 10 == 0)
			cout << endl;
	}
	if ((i + 1) % 10 != 1) {
		cout << endl;
	}

	for (int i = 0; i < num-1 ; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (array[j] < array[j + 1]) {
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}

	}

	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	int grade = array[0], cnt = 0, rank = 1;
	for (int i = 0; i < num; i++) {
		if (grade != array[i]) {
			grade = array[i];
			rank = cnt+1;
		}
		cout << grade << ' ' << rank << endl;
		cnt++;
	}

	return 0;
}