/*2152988 计科 杨恺铭*/

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
    {"香辣鸡腿堡", 18.5},
    {"劲脆鸡腿堡", 18.5},
    {"新奥尔良烤鸡腿堡", 19},
    {"老北京鸡肉卷", 17},
    {"川辣嫩牛卷", 19.5},
    {"深海鳕鱼堡", 18.5},
    {"吮指原味鸡(1块)", 11.5},
    {"芝芝肉酥热辣脆皮鸡", 12.5},
    {"新奥尔良烤翅(2块)", 12.5},
    {"劲爆鸡米花", 11.5},
    {"香辣鸡翅(2块)", 12.0},
    {"藤椒无骨大鸡柳(2块)", 12.5},
    {"鲜蔬色拉", 13},
    {"薯条(小)", 9},
    {"薯条(中)", 12},
    {"薯条(大)", 14},
    {"芙蓉蔬荟汤", 9},
    {"原味花筒冰激凌", 6},
    {"醇香土豆泥", 7},
    {"香甜粟米棒", 9.0},
    {"葡式蛋挞", 8.0},
    {"百事可乐(小)", 7.0},
    {"百事可乐(中)", 9.5},
    {"百事可乐(大)", 11.5},
    {"九珍果汁饮料", 12.5},
    {"纯纯玉米饮", 11.5},
    {NULL,0},
};

const struct SPECIAL special[] = {
    	{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
        //{"BMV", "劲脆鸡腿堡超值套餐",    26},
        {"ABCGGIIKKOUWWW", "超值全家桶", 115},
        {"KIIRRJUWW", "缤纷小吃桶",      65},
        {"JJ","劲爆鸡米花(2份小)",       12.5},
        {NULL, NULL, 0}
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



double price(int order[])
{
    double cnt = 0;
    for (int i = 0; *special[i].content; i++) {
        //比较能否满足套餐
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
        //cnt还要考虑套餐
        //cnt += list[i].price;
    }
    cnt = price(order);
    return cnt;
}
void prt_menu(void)
{
    cout << "=============================================================" << endl;
    cout << "                      KFC 2022秋季菜单" << endl;
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

    cout << endl << "【优惠信息】：" << endl;
    for (int i = 0; *special[i].content; i++) {
        cout << special[i].name << '=';
        prt_order(special[i].content);
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
                cout << "输入错误，按任意键继续." << endl;
                _getch();
                break;
            }
        }
        if (*p) {
            continue;
        }//输入状态判断

        cout << "您的点餐=";
        double cnt = prt_order(order);
        cout << endl;
        cout << "共计：" << cnt << "元" << endl;
        cout << "点单完成，按任意键继续." << endl;
        _getch();
    }
}

int main()
{
    system("mode con cols=120 lines=35");
    order();
    return 0;
}
