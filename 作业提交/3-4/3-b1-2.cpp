/*21529988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "������뾶�͸߶�" << endl;
	const double Pi = 3.14159;
	double r, h, cirC, cirS, ballS, ballV, cylV;
	cin >> r >> h;
	cirC = 2 * Pi * r;
	cirS = Pi * r * r;
	ballS = 4 * cirS;
	ballV = 4.0 / 3.0 * Pi * r * r * r;
	cylV = cirS * h;
	cout << setiosflags(ios::fixed) << setprecision(2) << setiosflags(ios::left);
	cout << setw(11) << "Բ�ܳ�" << ": " << cirC << endl;
	cout << setw(11) << "Բ���" << ": " << cirS << endl;
	cout << setw(11) << "Բ������" << ": " << ballS << endl;
	cout << setw(11) << "Բ�����" << ": " << ballV << endl;
	cout << setw(11) << "Բ�����" << ": " << cylV << endl;

	return 0;
}
