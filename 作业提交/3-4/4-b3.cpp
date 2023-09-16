/*2152988 �ƿ� ������*/
#include <iostream>
#include<iomanip>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�DayValue
  ��    �ܣ�������£�����·ݶ�Ӧ������
  ���������
  �� �� ֵ������
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
int DayValue(int year, int month)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	int daymax = 28;
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		daymax += 3;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daymax += 2;
	else
		daymax += leap;
	return daymax;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ĳ���ڶ�Ӧ������
  ���������
  �� �� ֵ����Ӧ�����ڣ�0-6��
  ˵    ����
***************************************************************************/
int Zeller(int year, int month, int day)
{
	int week = -1;
	if (month == 1 || month == 2) {
		month += 12;
		--year;
	}
	int c = year / 100;
	week = year%100 + (year%100 / 4) + (c / 4) - 2 * c
		+ (13 * (month + 1) / 5) + day - 1;
	while (week < 0)
		week += 7;
	return week%7;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ����
  ���������
  �� �� ֵ��void
  ˵    ����Needf: DayValue Zeller
***************************************************************************/
void PrintMonth(int year, int month)
{
	cout << endl;
	cout << year << "��" << month << "��" << endl;
	cout << setfill('=') << setw(8 * 7 - 2) << '=' << setfill(' ') << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������"
		<< endl;
	cout << setfill('=') << setw(8 * 7 - 2) << '=' << setfill(' ') << endl;

	int daymax = DayValue(year, month);
	int week = Zeller(year, month, 1);
	int count = daymax + week;//��ӡ����
	for (int i = 1; i <= count; i++) {
		if (i <= week)
			cout << "        ";
		else {
			cout << setw(4) << i - week << "    ";
		}
		if (i % 7 == 0)
			cout << endl;
	}
	cout << endl;
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
	int year, month;
	while (1) {
		cout << "��������[1900-2100]����" << endl;
		cin >> year >> month;
		if (cin.fail()) {

			cout << "����Ƿ�������������" << endl;

		}
		else if (year < 1900 || year > 2100) {
			cout << "��ݲ���ȷ������������" << endl;
		}
		else if (month < 1 || month>12) {
			cout << "�·ݲ���ȷ������������" << endl;
		}
		//else if (day<1 || day > DayValue(year, month)) {
		//	cout << "�ղ���ȷ������������" << endl;
		//}
		else {
			break;
		}
		cin.clear();
		cin.ignore(0xffffffff, '\n');
	}
	PrintMonth(year, month);
	cout << endl;

	return 0;
}
