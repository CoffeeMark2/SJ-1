/*2152988 �ƿ� ������*/
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */

public:
	int calc_days();     //�����ǵ���ĵڼ���

	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */
	Days(int y, int m, int d);
	int IsLeap();
};

/* --- �˴��������Ա����������ʵ�� --- */
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

int Days::IsLeap()
{
	return year % 4 == 0 && year % 100 != 0
		|| year % 400 == 0;
}

int Days::calc_days()
{
	if (month == 2) {
		if (day > 29) {
			return -1;
		}
		else if (!(IsLeap()) && day > 28) {
			return -1;
		}
	}
	int no = 0;
	int monthvalue[13] = { -1,31,28,31,30,31,30,
		31,31,30,31,30,31 };
	if (IsLeap())
		monthvalue[2]++;
	for (int i = 1; i < month; i++) {
		no += monthvalue[i];
	}
	return no + day;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
