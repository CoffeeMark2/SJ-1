/*2152988 �ƿ� ������*/
#include <iostream>
using namespace std;
int main()
{
	cout << "�������꣬�£���" << endl;
	int year, month, day;
	cin >> year >> month >> day;
	bool ret = true;
	if (month < 1 || month>12) {
		cout << "�������-�·ݲ���ȷ" << endl;
		ret = false;
	}
	else if (day < 1 || day>31) {
		cout << "�������-�����¹�ϵ�Ƿ�" << endl;
		ret = false;
	}
	else if ((month == 4 || month == 6 ||
		month == 9 || month == 11) && day > 30) {
		cout << "�������-�����¹�ϵ�Ƿ�" << endl;
		ret = false;
	}
	else if (month == 2) {
		if (day > 29) {
			cout << "�������-�����¹�ϵ�Ƿ�" << endl;
			ret = false;
		}
		else if (!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && day > 28) {
			cout << "�������-�����¹�ϵ�Ƿ�" << endl;
			ret = false;
		}
	}

	int sum = 0;
	if (ret) {
		switch (month) {
			case 12:
				sum += 30;
			case 11:
				sum += 31;
			case 10:
				sum += 30;
			case 9:
				sum += 31;
			case 8:
				sum += 31;
			case 7:
				sum += 30;
			case 6:
				sum += 31;
			case 5:
				sum += 30;
			case 4:
				sum += 31;
			case 3:
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
					sum += 29;
				else
					sum += 28;
			case 2:
				sum += 31;
			case 1:
				sum += day;
				break;
			default:
				break;
		}
		cout << year << '-' << month << '-' << day << "��" 
			<< year << "��ĵ�" << sum << "��" << endl;
	}

	return 0;
}