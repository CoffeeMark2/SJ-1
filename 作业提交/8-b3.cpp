/*2152988 计科 杨恺铭*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
using namespace std;
const int M = 31, NUM_MAX = 30;
const int ORDER_M = 100;
struct KFC {
    char no;
    char name[M];
    double price;
};
struct SPECIAL {
    char content[NUM_MAX];
    char name[M];
    double price;
};
struct ORDER {
    char content;
    int num;
};



char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

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



double price(int order[], const KFC list[], const SPECIAL special[])
{
    double cnt = 0;
    for (int i = 0; *special[i].content; i++) {
        //比较能否满足套餐
        int tmp[NUM_MAX] = { 0 };
        const char* p1 = special[i].content;
        while (*p1) {
            char ch = *p1;
            if (ch > 'Z') {
                ch -= 'a' - 'A';
            }
            tmp[ch - 'A']++;
            p1++;
        }
        int ret = 1;
        for (int j = 0; j < NUM_MAX && list[j].no != 0; j++) {
            if (tmp[j] > order[j]) {
                ret = 0;
                break;
            }
        }
        if (1 == ret) {
            cnt += special[i].price;
            for (int j = 0; j < NUM_MAX && list[j].no != 0; j++) {
                order[j] -= tmp[j];
            }
            i = 0;
        }
    }
    for (int i = 0; i < NUM_MAX && list[i].no != 0; i++) {
        cnt += order[i] * list[i].price;
    }
    return cnt;
}

double prt_order(const char* p, const KFC list[], const SPECIAL special[])
{
    double cnt = 0;
    int order[NUM_MAX] = { 0 };
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
    for (int i = first; i < NUM_MAX && list[i].no != 0; i++) {
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
        //cnt还要考虑套餐
        //cnt += list[i].price;
    }
    cnt = price(order,list,special);
    return cnt;
}
void prt_menu(const KFC list[],const SPECIAL special[])
{
    cout << "=============================================================" << endl;
    cout << "                      KFC 2022秋季菜单" << endl;
    cout << "=============================================================" << endl;
    cout << setiosflags(ios::left);
    for (int i = 0; i < NUM_MAX && list[i].no != 0; i++) {
        cout << " " << setw(2) << list[i].no
            << setw(20) << list[i].name
            << setw(7) << list[i].price;
        if (i % 2 == 0)
            cout << "|   ";
        else
            cout << endl;
    }

    cout << endl << "【优惠信息】：" << endl;
    for (int i = 0; *special[i].content; i++) {
        cout << special[i].name << '=';
        prt_order(special[i].content, list, special);
        cout << '=' << special[i].price << endl;
    }
    cout << endl;
    cout << "【输入规则说明】：" << endl
        << "ANV = 香辣鸡腿堡 + 薯条(小) + 百事可乐(小) / akaak = 香辣鸡腿堡*3 + 香辣鸡翅*2"
        << endl
        << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
    cout << endl;
    cout << "请点单: ";

}
int input_file(KFC list[], SPECIAL special[],int &cnt_l,int &cnt_s )
{
    ifstream in("KFC-price.cfg", ios::in);
    if (!in.is_open()) {
        cerr << "文件打开错误" << endl;
        in.close();
        return -1;
    }
    char ch;
    int flag_list = 0, flag_special = 0;
    while ((ch = in.peek()) != EOF) {
        if (ch == '#') {
            while (in.get() != '\n')
                ;
        }
        else if (ch == '[') {
            char tmp[12];
            in >> tmp;
            if (strcmp(tmp, "[单品菜单]")==0) {
                flag_list = 1;
                flag_special = 0;
            }
            else if(strcmp(tmp, "[组合菜单]") == 0) {
                flag_special = 1;
                flag_list = 0;
            }
            else {
                while (in.get() != '\n')
                    ;
            }
        }
        else if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
            if (flag_list) {
                in >> list[cnt_l].no >> list[cnt_l].name >> list[cnt_l].price;
                ++cnt_l;
            }
            else if (flag_special) {
                char tmp[NUM_MAX];
                in >> tmp;
                int i = 0;
                for (i = 0; tmp[i]; i++) {
                    if (!(tmp[i] > 'a' && tmp[i] < 'z' || tmp[i]>'A' && tmp[i] < 'Z')) {
                        break;
                    }
                }
                if (tmp[i] == 0) {
                    tj_strcpy(special[cnt_s].content, tmp);
                    in >> special[cnt_s].name >> special[cnt_s].price;
                    ++cnt_s;
                }
                else {
                    while (in.get() != '\n')
                        ;
                }
            }
            else {
                while (in.get() != '\n')
                    ;
            }
        }
        else {
            in.get();
        }
    }
    //结构体末尾置零
    list[cnt_l] = { '\0', NULL,0 };
    special[cnt_s] = {NULL, NULL, 0};
    in.close();
    return 0;
}
void sort(KFC list[], int cnt, int flag_prt = 0)
{
    for (int i = cnt - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            char tmp1 = list[j].no,tmp2= list[j+1].no;
            if (!flag_prt) {
                if (tmp1 > 'Z') {
                    tmp1 -= 'a' - 'A';
                }
                if (tmp2 > 'Z') {
                    tmp2 -= 'a' - 'A';
                }
            }
            if (tmp1 > tmp2) {
                KFC tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

int order(void)
{
    KFC list[NUM_MAX];

    SPECIAL special[NUM_MAX];
    int cnt_l = 0, cnt_s = 0;
    if (input_file(list,special,cnt_l,cnt_s) < 0) {
        return -1;
    }
    KFC list_prt[NUM_MAX];
    for (int i = 0; i < cnt_l+1; i++) {
        list_prt[i] = list[i];
    }
    sort(list, cnt_l);
    sort(list_prt, cnt_l, 1);
    int flag_sort = 1;
    while (1) {
        system("cls");
        prt_menu(list_prt, special);
        char order[ORDER_M];
        cin.getline(order, ORDER_M);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if (strcmp(order, "0") == 0) {
            return 0;
        }
        tj_strupr(order);
        const char* p = order;
        for (; *p; p++) {
            if (!(*p >= 'A' && *p <= 'Z')) {
                cout << "输入错误，按任意键继续." << endl;
                _getch();
                break;
            }
        }
        if (*p) {
            continue;
        }//输入状态判断

        cout << "您的点餐=";
        double cnt = prt_order(order, list, special);
        cout << endl;
        cout << "共计：" << cnt << "元" << endl;
        cout << "点单完成，按任意键继续." << endl;
        _getch();
    }
    return 0;
}
int main()
{
    system("mode con cols=120 lines=35");
    if (order() < 0) {
        return -1;
    }
    return 0;
}