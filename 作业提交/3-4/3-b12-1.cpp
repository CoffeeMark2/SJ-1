/*2152988 计科 杨恺铭*/
#include <iostream>
using namespace std;

int main()
{
    int x;
    while (1) {
        cout << "请输入x的值[0-100] : ";
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
        }
        else if(x >= 0 && x <= 100){
            break;
        }
    }
    cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

    return 0;
}
