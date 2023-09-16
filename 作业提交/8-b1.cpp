/*2152988 计科 杨恺铭*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int N = 16;

int main()
{
    clog << "文件名以下形式均可以:" <<endl;
    clog << "    a.txt                    : 不带路径形式" <<endl;
    clog << "    ..\\data\\b.dat          : 相对路径形式" <<endl;
    clog << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" <<endl;
    clog << "请输入文件名 : ";

    char path[100];
    cin.getline(path, 100);

    ifstream in(path, ios::in | ios::binary);
    if (!in.is_open()) {
        cerr << "输入文件 " << path
            << "打开失败!" << endl;
        return -1;
    }

    int cnt = 0;
    //可以使用文件指针tellg()来记录位置代替cnt
    char ch;
    char tmp[N];
    cout << hex << setiosflags(ios::uppercase);
    while (in.peek()!=EOF) {
        //prt title
        if (cnt % N == 0) {
            cout << setfill('0');
            cout << setw(8) << cnt << ":  ";
            cout << setfill(' ');
        }

        in.read(&ch,1);
        if (ch >= 33 && ch <= 126) {
            tmp[cnt % N] = ch;
        }
        else {
            tmp[cnt % N] = '.';
        }
        cnt++;
        //prt item
        unsigned char x = ch;
        cout << setfill('0');
        cout << setw(2) << int(x) << ' ';
        cout << setfill(' ');
        if (cnt % (N / 2) == 0
            &&cnt%N!=0) {
            cout << "- ";
        }
        //prt ASC
        //clear tmp
        if (cnt % N == 0) {
            cout << ' ';
            for (int i = 0; i < N; i++) {
                cout << tmp[i];
            }
            cout << endl;
        }

    }

    //最后一行多余的处理
    if (cnt % N != 0) {
        int cur = (cnt % N);
        while (cnt % N != 0) {
            cnt++;
            cout << setw(2) << ' ' << ' ';
            if (cnt % (N / 2) == 0
                && cnt % N != 0) {
                cout << "  ";
            }

        }
        cout << ' ';
        for (int i = 0; i < cur; i++) {
            cout << tmp[i];
        }
        cout << endl;
    }
    //clog,cerr的更改
    in.close();
	return 0;
}