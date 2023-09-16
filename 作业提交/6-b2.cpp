/*2152988 计科 杨恺铭*/
#include <iostream>
using namespace std;

const int N = 81;
int tj_strlen(const char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int cnt = 0;
	while (str[cnt] != '\0') {
		cnt++;
	}
	return cnt; //return值可根据需要修改
}
int main()
{
	char str[N], * p1 = str, * p2 = str;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, N, stdin);
	p2 = p2 + tj_strlen(str) - 1;
	//处理回车
	//只有在未读满的情况下才会有回车
	//这里更简单直接
	if (*p2 == '\n') {
		*p2 = 0;
		p2--;
	}
	//考虑空串和单串
	//空串无法处理，特判
	if (!p1) {
		cout << "yes" << endl;
		return 0;
	}
	int ret = 1;
	while (p1 < p2) {
		if (*p1 != *p2) {
			ret = 0;
			break;
		}
		p1++;
		p2--;
	}

	if (ret)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}