/*2152988 计科 杨恺铭*/
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	pnum = a;
	pa = a;
	is_num = false;
	gets_s(str);
	for (p = str; *p; p++) {
		if (pnum - a >= N) {
			break;
		}
		if (*p >= '0' && *p <= '9') {
			*pa = *pa * 10 + (*p - '0');
			is_num = true;
		}
		else if (is_num) {
			//什么时候移动？*p不是数且之前是数
			pnum++;
			pa++;
			is_num = false;
		}
	}
	//!!!判断整数在最后的情况
	if (is_num)
		pnum++;
	cout << "共有" << pnum - a << "个整数" << endl;
	for (pa = a; pa < pnum; pa++) {
		if (pa == a) {
			cout << *pa;
		}
		else {
			cout << ' ' << *pa;
		}
	}
	cout << endl;
	return 0;
}