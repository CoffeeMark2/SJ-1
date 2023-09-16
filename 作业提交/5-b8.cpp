/*2152988 �ƿ� ������*/
#include <iostream>
#include <cmath>
using namespace std;
const int MAXPOINT = 7;
const int DIMENTION = 2;
double vector_product(double x1, double y1,
	double x2, double y2, double x3, double y3)
{
	double v1x = x2 - x1, v1y = y2 - y1;
	double v2x = x3 - x1, v2y = y3 - y1;
	return  v1x * v2y - v2x * v1y;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
int main()
{
	double point[MAXPOINT][DIMENTION];
	int num;
	while (1) {
		cout << "���������εĶ�������(4-7)"<<endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (num>=4&&num<=7) {
			break;
		}
	}
	cout << "�밴˳ʱ��/��ʱ�뷽������"<<num
		<<"�������x,y���꣺" << endl;
	for (int i = 1; i <= num; i++) {
		double x, y;
		while (1) {
			cout << "�������" << i << "����������꣺"<<endl;
			cin >> x >> y;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else if (1) {
				point[i - 1][0] = x;
				point[i - 1][1] = y;
				break;
			}
		}
	}

	double last;
	int is_convex = 1;
	for (int i = 0; i < num; i++) {
		double p1x = point[i][0], p1y = point[i][1];
		double p2x = point[(i + 1) % num][0],
			p2y = point[(i + 1) % num][1];
		double p3x = point[(i + 2) % num][0], 
			p3y = point[(i + 2) % num][1];
		double current = vector_product(p1x, p1y, p2x, p2y, p3x, p3y);
		//cout << current << endl;
		//�ж�˳��������⣺
		if (fabs(current) < 1e-6) {
			is_convex = 0;
			break;
		}
		if (i == 0) {
			last = current;
			continue;
		}else if (current * last < 0 ) {
			is_convex = 0;
			break;
		}
		last = current;
	}

	double area = 0;
	if (is_convex) {
		for (int i = 0; i < num; i++) {
			area+=vector_product(0, 0, point[i][0], point[i][1],
				point[(i + 1) % num][0], point[(i + 1) % num][1]);
		}
		area = (fabs(area / 2.0));
		cout << "͹" << num << "���ε����=" << area << endl;
	}
	else {
		cout << "����͹" << num << "����" << endl;
	}

	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < DIMENTION; j++) {
	//		cout << point[i][j] <<' ';
	//	}
	//	cout << endl;
	//}

	return 0;
}