/*2152988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
using namespace std;

const int WEEK = 7, ROW = 6;
/***************************************************************************
  �������ƣ�DayValue
  ��    �ܣ�������£�����·ݶ�Ӧ������
  ���������
  �� �� ֵ������
  ˵    ����
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
	week = year % 100 + (year % 100 / 4) + (c / 4) - 2 * c
		+ (13 * (month + 1) / 5) + day - 1;
	while (week < 0)
		week += 7;
	return week % 7;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���������
  ���������
  �� �� ֵ���·���������������������λ��
  ˵    ����Needf: DayValue Zeller
***************************************************************************/
int CreateMonth(int year, int month, int matrix[][WEEK])
{
	int daymax = DayValue(year, month);
	int week = Zeller(year, month, 1);
	int count = daymax + week;//��ӡ����
	for (int i = 1; i <= count; i++) {
		if (i <= week)
			continue;
		else {
			//cout << setw(4) << i - week << "    ";
			matrix[(i - 1) / WEEK][(i - 1) % WEEK] = i - week;
		}
		//if (line % 7 == 0)
		//	cout << endl;
	}
	return count;
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
	cout << "���������[1900-2100]" << endl;
	int year;
	cin >> year;
	cout << year << "�������:" << endl << endl;

	for (int i_month = 1; i_month <= 12; i_month += 3) {
		cout << setiosflags(ios::right);
		cout << setw(13) << i_month << "��            ";
		cout << "     ";
		cout << setw(13) << i_month + 1 << "��            ";
		cout << "     ";
		cout << setw(13) << i_month + 2 << "��";
		cout << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		cout << "     ";
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		cout << "     ";
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		cout << endl;
		cout << resetiosflags(ios::right)
			<<setiosflags(ios::left);

		int month1[ROW][WEEK] = { 0 };
		int month2[ROW][WEEK] = { 0 };
		int month3[ROW][WEEK] = { 0 };


		int row_is_5 = 1;
		if (CreateMonth(year, i_month, month1) > (ROW - 1) * 7) {
			row_is_5 = 0;
		}
		if (CreateMonth(year, i_month + 1, month2) > (ROW - 1) * 7) {
			row_is_5 = 0;
		}
		if (CreateMonth(year, i_month + 2, month3) > (ROW - 1) * 7) {
			row_is_5 = 0;
		}
				
		cout << setiosflags(ios::left);
		for (int row = 0; row < ROW; row++) {
			for (int line = 0; line < WEEK; line++) {
				if (month1[row][line] == 0) {
					cout << setw(4) << "";
				}
				else {
					cout << setw(4) << month1[row][line];
				}
			}
			cout << "    ";
			for (int line = 0; line < WEEK; line++) {
				if (month2[row][line] == 0) {
					cout << setw(4) << "";
				}
				else {
					cout << setw(4) << month2[row][line];
				}
			}
			cout << "    "; 
			for (int line = 0; line < WEEK; line++) {
				if (month3[row][line] == 0) {
					cout << setw(4) << "";
				}
				else {
					cout << setw(4) << month3[row][line];
				}
			}
			cout << endl;
			if (row_is_5 && row == 4) {
				break;
			}

		}
		cout << endl;
	}
	cout << endl;
	return 0;
}