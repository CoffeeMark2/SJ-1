/*2152988 计科 杨恺铭*/
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	int year, month, week;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (year >= 2000 && year <= 2030 &&
			month >= 1 && month <= 12) {
			break;
		}
		cout << "输入非法，请重新输入" << endl;

	}

	while (1) {
		cout << "请输入" << year << "年" <<
			month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> week;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(0xffffffff, '\n');
		}
		else if (week >= 0 && week <= 6) {
			break;
		}
		cout << "输入非法，请重新输入" << endl;
	}

	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout<<setfill('=')<<setw(8*7-2)<<'='<<setfill(' ')<<endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六"
		<<endl;
	cout<<setfill('=')<<setw(8*7-2)<<'='<<setfill(' ')<<endl;
	
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	int daymax = 28;
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		daymax += 3;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daymax += 2;
	else
		daymax += leap;
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

	return 0;
}
