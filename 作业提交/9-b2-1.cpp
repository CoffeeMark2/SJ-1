/*2152988 计科 杨恺铭*/
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x;
	int y;
	//除上面的两个private数据成员外，不再允许添加任何类型的数据成员
public:
	int getx() const
	{
		return x;
	}
	int gety() const
	{
		return y;
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	void set(int X, int Y) {
		x = X;
		y = Y;
	}
};

class triangle {
private:
	point p1;
	point p2;
	point p3;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员
public:
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		double v1x = p2.getx() - p1.getx(), v1y = p2.gety() - p1.gety();
		double v2x = p3.getx() - p1.getx(), v2y = p3.gety() - p1.gety();
		double ans=fabs((v1x * v2y - v2x * v1y) / 2);
		return ans ? ans : -1;
	}
	/* 构造函数 */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */

};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //三角形为(0,0) (0,1) (1,0)三点组成
		cout << "三角形面积应该是：0.5，实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //三角形为(0,2) (-1,-1) (1,-1)三点组成
		cout << "三角形面积应该是：3，  实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //三角形为(5,5) (-3,1) (9,-2)三点组成
		cout << "三角形面积应该是：36， 实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //三点共线
		cout << "三角形面积应该是：-1， 实际是：" << tr.area() << endl;
	}

	return 0;
}