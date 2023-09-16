/*21529988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "请输入半径和高度" << endl;
	const double Pi = 3.14159;
	double r, h, cirC, cirS, ballS, ballV, cylV;
	cin >> r >> h;
	cirC = 2 * Pi * r;
	cirS = Pi * r * r;
	ballS = 4 * cirS;
	ballV = 4.0 / 3.0 * Pi * r * r * r;
	cylV = cirS * h;
	cout << setiosflags(ios::fixed) << setprecision(2) << setiosflags(ios::left);
	cout << setw(11) << "圆周长" << ": " << cirC << endl;
	cout << setw(11) << "圆面积" << ": " << cirS << endl;
	cout << setw(11) << "圆球表面积" << ": " << ballS << endl;
	cout << setw(11) << "圆球体积" << ": " << ballV << endl;
	cout << setw(11) << "圆柱体积" << ": " << cylV << endl;

	return 0;
}
