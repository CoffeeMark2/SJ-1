/*2152988 �ƿ� ������*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int N = 16;

int main()
{
    clog << "�ļ���������ʽ������:" <<endl;
    clog << "    a.txt                    : ����·����ʽ" <<endl;
    clog << "    ..\\data\\b.dat          : ���·����ʽ" <<endl;
    clog << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" <<endl;
    clog << "�������ļ��� : ";

    char path[100];
    cin.getline(path, 100);

    ifstream in(path, ios::in | ios::binary);
    if (!in.is_open()) {
        cerr << "�����ļ� " << path
            << "��ʧ��!" << endl;
        return -1;
    }

    int cnt = 0;
    //����ʹ���ļ�ָ��tellg()����¼λ�ô���cnt
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

    //���һ�ж���Ĵ���
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
    //clog,cerr�ĸ���
    in.close();
	return 0;
}