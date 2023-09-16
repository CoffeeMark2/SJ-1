/*2152988 计科 杨恺铭*/
#include <iostream>
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
  功    能：
  输入参数：
  返 回 值：
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
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	int year, month, day;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month>>day;
		if (cin.fail()) {
			
			cout << "输入非法，请重新输入" << endl;

		}
		else if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
		}
		else if (month < 1 || month>12) {
			cout << "月份不正确，请重新输入" << endl;
		}
		else if (day<1 || day > DayValue(year, month)) {
			cout<< "日不正确，请重新输入" << endl;
		}
		else {
			break;
		}
		cin.clear();
		cin.ignore(0xffffffff, '\n');
	}

	cout << "星期";
	
	switch (Zeller(year, month, day)) {
		case 0:
			cout << "日";
			break;
		case 1:
			cout << "一";
			break;
		case 2:
			cout << "二";
			break;
		case 3:
			cout << "三";
			break;
		case 4:
			cout << "四";
			break;
		case 5:
			cout << "五";
			break;
		case 6:
			cout << "六";
			break;
		default:
			cout << "error";
			break;
	}
	cout << endl;


	return 0;
}
