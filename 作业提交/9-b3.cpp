/*2152988 �ƿ� ������*/
#include <iostream>
#include <conio.h>
using namespace std;

/* --- �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� --- */
const int Y = 2000, M = 1, D = 1;
const int Y_MAX = 2099, Y_MIN = 1900;
/* --- ���������ȫ�ֺ�����Ҫ������д�ڴ˴� --- */

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */

public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
	Date();
	Date(int y , int m , int d);
	Date(int d);
	int DayValue(int year, int month);
	bool check(int& year, int& month, int& day);
	int is_leap(const int year);
	void set(int y = 0, int m = 0, int d = 0);
	void show();
	void get(int& y, int& m, int& d);
};

/* --- ���� Date ������г�Ա����������ʵ�� --- */
Date::Date()
{
	year = Y;
	month = M;
	day = D;
}
Date::Date(int y,int m,int d)
{
	check(y, m, d);
	year = y;
	month = m;
	day = d;
}
Date::Date(int d)
{
	//day==0��ʲô�����
	//day==0Ӧ����1�ţ�����ʽ����ʵ��day����1�ŵ�day����Ӧ��+1
	if (d < 0) {
		Date::year = Y_MIN;
		Date::month = M;
		Date::day = D;
		return;
	}
	
	int year = Y_MIN;
	int leap = is_leap(year);
	while (d > 365 + leap) {
		d -= 365 + leap;
		year++;
		leap = is_leap(year);
	}

	//���������ˣ��ϴ�Ҳ�����Ƶ�����,ѭ������ĸ���俪ʼִ�ж��ɣ�
	//ȡ�����ж�����������
	int month = 1;
	int daymax = DayValue(year, month);
	while (d > daymax) {
		d -= daymax;
		month++;
		daymax = DayValue(year, month);
	}
	if (year > Y_MAX) {
		Date::year = Y_MAX;
		Date::month = 12;
		Date::day = 31;
		return;
	}
	Date::year = year;
	Date::month = month;
	Date::day = d;
}
void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}
int Date::DayValue(int year, int month)
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
int Date::is_leap(const int year)
{
	return year % 4 == 0 && year % 100 != 0
		|| year % 400 == 0;
}

bool Date::check(int& year, int& month, int& day)
{
	bool ret = true;
	if (year < Y_MIN || year>Y_MAX) {
		year = Y;
		ret = false;
	}
	if (month < 1 || month>12) {
		month = M;
		ret = false;
	}
	if (day < 1 || day>31) {
		day = D;
		ret = false;
	}
	else if ((month == 4 || month == 6 ||
		month == 9 || month == 11) && day > 30) {
		day = D;
		ret = false;
	}
	else if (month == 2) {
		if (day > 29) {
			day = D;
			ret = false;
		}
		else if (!(is_leap(year)) && day > 28) {
			day = D;
			ret = false;
		}
	}
	return ret;
}
void Date::set(int y, int m, int d)
{
	check(y, m, d);
	year = y;
	month = m;
	day = d;
}
void Date::show()
{
	cout << year << '.' << month << '.' << day<< endl;
}
/* --- �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� --- */

/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��������ʱ���滻
***************************************************************************/
int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2022, 12, 9);	//2022.12.9

		cout << "�޲μ����ι��캯�����ԣ���ȫ��ȷ��" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.1.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.12.9��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2022, 6, 32);  //2022.6.1

		cout << "���ι��캯�����ԣ��ꡢ�¡��շǷ���" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.3.15��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2000.3.4�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2005.1.15��ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.6.1�� ʵ��Ϊ��";
		d4.show();

		/* �������������˳���� */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5Ӧ����2000.2.29��ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1�� ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.1.31��ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2000.1.1�� ʵ��Ϊ��";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "���ι��캯�����ԣ����꣩" << endl;
		cout << "========================" << endl;

		cout << "d1Ӧ����2022.2.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2020.2.29��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		Date d5(30000);      //1982.2.19
		Date d6(44903);      //2022.12.9

		cout << "һ�ι��캯�����ԣ������Ϸ����Ƿ�ֵ" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����1900.1.1��  ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����1900.1.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2099.12.31��ʵ��Ϊ��";
		d4.show();
		cout << "d5Ӧ����1982.2.19�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2022.12.9�� ʵ��Ϊ��";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //����2000.1.1

		cout << "����set����ȱʡֵ" << endl;
		cout << "=================" << endl;

		d1.set(2022, 6, 10);	//2022.6.10
		d2.set(2022, 6);		//2022.6.1
		d3.set(2022);		//2022.1.1

		cout << "d1Ӧ����2022.6.10��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.6.1�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.1.1�� ʵ��Ϊ��";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "����set���ꡢ�¡��շǷ�" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2022, 5, 32);  //2022.5.1
		d4.set(2022, 13, 12); //2022.1.12

		cout << "d1Ӧ����2000.2.29�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2019.2.1��  ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.5.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.1.12�� ʵ��Ϊ��";
		d4.show();

		/* �����+��ȱʡֵ����������˳���� */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5Ӧ����2000.2.29�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1��  ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.2.1��  ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2020.2.1��  ʵ��Ϊ��";
		d8.show();
		cout << "d9Ӧ����2020.1.1��  ʵ��Ϊ��";
		d9.show();
		cout << "d10Ӧ����2000.1.31��ʵ��Ϊ��";
		d10.show();
		cout << "d11Ӧ����2000.1.1�� ʵ��Ϊ��";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 12, 9);
		int y, m, d;

		cout << "����get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "Ӧ��y=2022,m=12,d=9��ʵ��Ϊ��";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}
