/* 2152988 �ƿ� ������ */
#include <iostream>
using namespace std;
const int M = 21;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int num, i = 0;
	int array[M];
	cout << "��������������������������20��������-1����" << endl;
	cin >> num;
	while (num >= 0 && i < 20) {
		array[i++] = num;
		cin >> num;
	}
	if (0 == i) {
		cout << "����Ч����" << endl;
		return -1;
	}
	if (i >= 20)
		cin.ignore(1024, '\n');
	int size = i;
	cout << "ԭ����Ϊ��" << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;



	cout << "������Ҫ�����������" << endl;
	cin >> num;
	int j;
	for (j = 0; j < size; j++) {
		if (array[j] >= num)
			break;
	}
	for (int i = size - 1; i >= j; i--) {
		array[i + 1] = array[i];
	}
	array[j] = num;
	size++;
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	return 0;
}