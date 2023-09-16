/*2152988 计科 杨恺铭*/
#include <iostream>
#include <cmath>
using namespace std;
const int MAXPOINT = 7;
const int DIMENTION = 2;
double vector_product(double x1, double y1,
	double x2, double y2, double x3, double y3)
{
	double v1x = x2 - x1, v1y = y2 - y1;
	double v2x = x3 - x1, v2y = y3 - y1;
	return  v1x * v2y - v2x * v1y;
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
	double point[MAXPOINT][DIMENTION];
	int num;
	while (1) {
		cout << "请输入多边形的顶点数量(4-7)"<<endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (num>=4&&num<=7) {
			break;
		}
	}
	cout << "请按顺时针/逆时针方向输入"<<num
		<<"个顶点的x,y坐标：" << endl;
	for (int i = 1; i <= num; i++) {
		double x, y;
		while (1) {
			cout << "请输入第" << i << "个顶点的坐标："<<endl;
			cin >> x >> y;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else if (1) {
				point[i - 1][0] = x;
				point[i - 1][1] = y;
				break;
			}
		}
	}

	double last;
	int is_convex = 1;
	for (int i = 0; i < num; i++) {
		double p1x = point[i][0], p1y = point[i][1];
		double p2x = point[(i + 1) % num][0],
			p2y = point[(i + 1) % num][1];
		double p3x = point[(i + 2) % num][0], 
			p3y = point[(i + 2) % num][1];
		double current = vector_product(p1x, p1y, p2x, p2y, p3x, p3y);
		//cout << current << endl;
		//判断顺序出现问题：
		if (fabs(current) < 1e-6) {
			is_convex = 0;
			break;
		}
		if (i == 0) {
			last = current;
			continue;
		}else if (current * last < 0 ) {
			is_convex = 0;
			break;
		}
		last = current;
	}

	double area = 0;
	if (is_convex) {
		for (int i = 0; i < num; i++) {
			area+=vector_product(0, 0, point[i][0], point[i][1],
				point[(i + 1) % num][0], point[(i + 1) % num][1]);
		}
		area = (fabs(area / 2.0));
		cout << "凸" << num << "边形的面积=" << area << endl;
	}
	else {
		cout << "不是凸" << num << "边形" << endl;
	}

	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < DIMENTION; j++) {
	//		cout << point[i][j] <<' ';
	//	}
	//	cout << endl;
	//}

	return 0;
}