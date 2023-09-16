/*2152988 计科 杨恺铭*/
#include <iostream>
#include<iomanip>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：DayValue
  功    能：给年和月，输出月份对应的天数
  输入参数：
  返 回 值：天数
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
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
  函数名称：
  功    能：输出某日期对应的星期
  输入参数：
  返 回 值：对应的星期（0-6）
  说    明：
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
  函数名称：
  功    能：打印月历
  输入参数：
  返 回 值：void
  说    明：Needf: DayValue Zeller
***************************************************************************/
void PrintMonth(int year, int month)
{
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	cout << setfill('=') << setw(8 * 7 - 2) << '=' << setfill(' ') << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六"
		<< endl;
	cout << setfill('=') << setw(8 * 7 - 2) << '=' << setfill(' ') << endl;

	int daymax = DayValue(year, month);
	int week = Zeller(year, month, 1);
	int count = daymax + week;//打印次数
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	int year, month;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (cin.fail()) {

			cout << "输入非法，请重新输入" << endl;

		}
		else if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
		}
		else if (month < 1 || month>12) {
			cout << "月份不正确，请重新输入" << endl;
		}
		//else if (day<1 || day > DayValue(year, month)) {
		//	cout << "日不正确，请重新输入" << endl;
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
