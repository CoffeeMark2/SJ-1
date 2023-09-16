/*2152988 计科 杨恺铭*/
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    cout << "请输入x的值[-10 ~ +65]" << endl;
    int x;
    while (1) {
        cin >> x;
        if (x >= -10 && x <= 65) {
            break;
        }
        else {
            cout << "输入非法，请重新输入" << endl;
            cout << "请输入x的值[-10 ~ +65]" << endl;
        }
    }

    double ans = 0, temp = 0 ;
    double power = 1;

    //ans +=temp 应在判断后，temp值改变之前
    int i = 0;
    do
    {
        ans += temp;
        //int 越界
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

//100.3输出异常，执行两次cin，第一次是100 第二次是0

