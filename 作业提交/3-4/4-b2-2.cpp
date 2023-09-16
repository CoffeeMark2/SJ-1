/*2152988 �ƿ� ������*/
#include <iostream>
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
  ��    �ܣ�
  ���������
  �� �� ֵ��
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
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

int main()
{
	int year, month, day;
	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month>>day;
		if (cin.fail()) {
			
			cout << "����Ƿ�������������" << endl;

		}
		else if (year < 1900 || year > 2100) {
			cout << "��ݲ���ȷ������������" << endl;
		}
		else if (month < 1 || month>12) {
			cout << "�·ݲ���ȷ������������" << endl;
		}
		else if (day<1 || day > DayValue(year, month)) {
			cout<< "�ղ���ȷ������������" << endl;
		}
		else {
			break;
		}
		cin.clear();
		cin.ignore(0xffffffff, '\n');
	}

	cout << "����";
	
	switch (Zeller(year, month, day)) {
		case 0:
			cout << "��";
			break;
		case 1:
			cout << "һ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
	cout << endl;


	return 0;
}
