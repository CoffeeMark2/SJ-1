/*2152988 �ƿ� ������*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
	cout << "������[0-100��)֮�������:" << endl;
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

	cout << "��д�����:" << endl;

	int ret0 = 0;
	//�ڷ���ǰ����㣬���700�������㲻���������
	int begin = 0;
	//�������700���Ϊ����۵�����


	//���ڡ��򡢸�Ϊһ��������������ԭ�򡤡������ڲ��䣩
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a9 != 0)
		begin = 1;
	//���� λ��Ӧ�����ģ�
	//ʲô˳��Ϊʲô�����ü�����

	if (a9 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a9 == 0)
		ret0 = 1;

	switch (a9) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a9)
		cout << "ʰ";

	if (begin == 0)
		ret0 = 0;
	if (a8 != 0)
		begin = 1;

	if (a8 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a8 == 0)
		ret0 = 1;

	switch (a8) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a9 || a8)
		cout << "��";


	//��
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a7 != 0)
		begin = 1;

	if (a7 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a7 == 0)
		ret0 = 1;
	switch (a7) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a7)
		cout << "Ǫ";

	if (begin == 0)
		ret0 = 0;
	if (a6 != 0)
		begin = 1;

	if (a6 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a6 == 0)
		ret0 = 1;

	switch (a6) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a6)
		cout << "��";


	if (begin == 0)
		ret0 = 0;
	if (a5 != 0)
		begin = 1;

	if (a5 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a5 == 0)
		ret0 = 1;

	switch (a5) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a5)
		cout << "ʰ";

	if (begin == 0)
		ret0 = 0;
	if (a4 != 0)
		begin = 1;

	if (a4 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a4 == 0)
		ret0 = 1;

	switch (a4) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a7 || a6 || a5 || a4)
		cout << "��";


	//��
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a3 != 0)
		begin = 1;

	if (a3 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a3 == 0)
		ret0 = 1;
	switch (a3) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a3)
		cout << "Ǫ";

	if (begin == 0)
		ret0 = 0;
	if (a2 != 0)
		begin = 1;

	if (a2 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a2 == 0)
		ret0 = 1;

	switch (a2) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a2)
		cout << "��";

	if (begin == 0)
		ret0 = 0;
	if (a1 != 0)
		begin = 1;

	if (a1 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a1 == 0)
		ret0 = 1;

	switch (a1) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (a1)
		cout << "ʰ";

	if (begin == 0)
		ret0 = 0;
	if (a0 != 0)
		begin = 1;

	if (a0 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (a0 == 0)
		ret0 = 1;

	switch (a0) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	//if (a3||a2||a1||a0)
	//	cout << "��";

	if (a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 || a1 || a0)
		cout << "Բ";



	//С������
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (b1 != 0)
		begin = 1;

	if (b1 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (b1 == 0)
		ret0 = 1;

	switch (b1) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (b1)
		cout << "��";

	if (begin == 0)
		ret0 = 0;
	if (b2 != 0)
		begin = 1;

	if (b2 != 0 && ret0) {
		ret0 = 0;
		cout << "��";
	}
	else if (b2 == 0)
		ret0 = 1;

	switch (b2) {
		case 9:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 7:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 5:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 0:
			//cout << "��";
			break;
		default:
			break;
	}
	if (b2)
		cout << "��";

	//��Ԫ�� ֻ�����ж�Ϊ0����������������
	if (!(a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 ||
		a1 || a0 || b1 || b2))
		cout << "��Բ";
	//����Զ�����������
	if (b2 == 0)
		cout << "��" << endl;

	return 0;
}

