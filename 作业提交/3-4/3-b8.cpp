/*2152988 �ƿ� ������*/
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    cout << "������x��ֵ[-10 ~ +65]" << endl;
    int x;
    while (1) {
        cin >> x;
        if (x >= -10 && x <= 65) {
            break;
        }
        else {
            cout << "����Ƿ�������������" << endl;
            cout << "������x��ֵ[-10 ~ +65]" << endl;
        }
    }

    double ans = 0, temp = 0 ;
    double power = 1;

    //ans +=temp Ӧ���жϺ�tempֵ�ı�֮ǰ
    int i = 0;
    do
    {
        ans += temp;
        //int Խ��
        double jiecheng = 1;
        for (int j = 1; j <= i; j++) {
            jiecheng *= j;
        }
        temp = power / jiecheng;
        power *= x;
        i++;
    } while (fabs(temp) >= 1e-6);


    cout << "e^" << x << '='
        << setprecision(10) << ans << endl;

    return 0;
}

//100.3����쳣��ִ������cin����һ����100 �ڶ�����0

