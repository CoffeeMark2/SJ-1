/*2152988 �ƿ� ������*/

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
const int M = 31,NUM = 26;
const int ORDER_M = 100;
struct KFC {
    char name[M];
    double price;
};
struct SPECIAL {
    char content[NUM];
    char name[M];
    double price;
};
struct ORDER {
    char content;
    int num;
};
const struct KFC list[NUM+1] = {
    {"�������ȱ�", 18.5},
    {"���༦�ȱ�", 18.5},
    {"�°¶��������ȱ�", 19},
    {"�ϱ��������", 17},
    {"������ţ��", 19.5},
    {"����㱤", 18.5},
    {"˱ָԭζ��(1��)", 11.5},
    {"֥֥����������Ƥ��", 12.5},
    {"�°¶�������(2��)", 12.5},
    {"�������׻�", 11.5},
    {"��������(2��)", 12.0},
    {"�ٽ��޹Ǵ���(2��)", 12.5},
    {"����ɫ��", 13},
    {"����(С)", 9},
    {"����(��)", 12},
    {"����(��)", 14},
    {"ܽ��������", 9},
    {"ԭζ��Ͳ������", 6},
    {"����������", 7},
    {"�������װ�", 9.0},
    {"��ʽ��̢", 8.0},
    {"���¿���(С)", 7.0},
    {"���¿���(��)", 9.5},
    {"���¿���(��)", 11.5},
    {"�����֭����", 12.5},
    {"����������", 11.5},
    {NULL,0},
};

const struct SPECIAL special[] = {
    	{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
        //{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
        {"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
        {"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
        {"JJ","�������׻�(2��С)",       12.5},
        {NULL, NULL, 0}
};

char* tj_strupr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return str;
    }
    char* p = str;
    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            (*p) -= 'a' - 'A';
        }
        p++;
    }
    return str;
}

char* tj_strcpy(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */

    if (s1 == NULL) {
        return s1;
    }
    if (s2 == NULL) {
        *s1 = 0;
        return s1;
    }
    char* p1 = s1;
    const char* p2 = s2;

    while (*p2) {
        *p1++ = *p2++;
    }
    *p1 = 0;
    return s1;
}



double price(int order[])
{
    double cnt = 0;
    for (int i = 0; *special[i].content; i++) {
        //�Ƚ��ܷ������ײ�
        int tmp[NUM] = { 0 };
        const char* p1 = special[i].content;
        while (*p1) {
            tmp[*p1 - 'A']++;
            p1++;
        }
        int ret = 1;
        for (int j = 0; j < NUM; j++) {
            if (tmp[j] > order[j]) {
                ret = 0; 
                break;
            }
        }
        if (1 == ret) {
            cnt += special[i].price;
            for (int j = 0; j < NUM; j++) {
                order[j] -= tmp[j];
            }
            i = 0;
        }
    }
    for (int i = 0; i < NUM; i++) {
        cnt += order[i] * list[i].price;
    }
    return cnt;
}

double prt_order(const char* p)
{
    double cnt = 0;
    int order[NUM] = { 0 };
    char tmp[ORDER_M], * p1 = tmp;
    tj_strcpy(tmp, p);
    tj_strupr(tmp);
    while (*p1) {
        order[*p1 - 'A']++;
        p1++;
    }
    int first = 0;
    for (; order[first] == 0; first++)
        ;
    for (int i = first; i < NUM; i++) {
        if (order[i] == 0)
            continue;
        if (i != first) {
            cout << '+';
        }
        if (order[i] == 1) {
            cout << list[i].name;
        }
        else {
            cout << list[i].name << '*' << order[i];
        }
        //cnt��Ҫ�����ײ�
        //cnt += list[i].price;
    }
    cnt = price(order);
    return cnt;
}
void prt_menu(void)
{
    cout << "=============================================================" << endl;
    cout << "                      KFC 2022�＾�˵�" << endl;
    cout << "=============================================================" << endl;
    cout << setiosflags(ios::left);
    for (int i = 0; i < NUM; i++) {
        cout << " " << setw(2) << char('A' + i)
            << setw(20) << list[i].name 
            << setw(7)  << list[i].price;
        if (i % 2 == 0)
            cout << "|   ";
        else
            cout << endl;
    }

    cout << endl << "���Ż���Ϣ����" << endl;
    for (int i = 0; *special[i].content; i++) {
        cout << special[i].name << '=';
        prt_order(special[i].content);
        cout << '=' << special[i].price << endl;
    }
    cout << endl;
    cout << "���������˵������" << endl 
        << "ANV = �������ȱ� + ����(С) + ���¿���(С) / akaak = �������ȱ�*3 + ��������*2" 
        << endl 
        << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
    cout << endl;
    cout << "��㵥: ";

}

void order(void)
{
    while (1) {
        system("cls");
        prt_menu();
        char order[ORDER_M];
        cin.getline(order, ORDER_M);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if (strcmp(order, "0") == 0) {
            return;
        }
        tj_strupr(order);
        const char* p = order;
        for (; *p; p++) {
            if (!(*p >= 'A' && *p <= 'Z')) {
                cout << "������󣬰����������." << endl;
                _getch();
                break;
            }
        }
        if (*p) {
            continue;
        }//����״̬�ж�

        cout << "���ĵ��=";
        double cnt = prt_order(order);
        cout << endl;
        cout << "���ƣ�" << cnt << "Ԫ" << endl;
        cout << "�㵥��ɣ������������." << endl;
        _getch();
    }
}

int main()
{
    system("mode con cols=120 lines=35");
    order();
    return 0;
}
