/*2152988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	const double Pi = 3.14159;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	int a, b, deg;
	cin >> a >> b >> deg;
	double rad = deg / 360.0 * 2 * Pi;
	float s = 0.5 * a * b * sin(rad);
	cout << "三角形面积为 : " << setiosflags(ios::fixed) 
		<< setprecision(3) << s << endl;
	return 0;
}