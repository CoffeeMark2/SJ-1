/*2152988 计科 杨恺铭*/
#include <iostream>
using namespace std;
int tj_strlen(const char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int cnt = 0;
	while (str[cnt] != '\0') {
		cnt++;
	}
	return cnt; //return值可根据需要修改
}
const int N = 33;

int main()
{
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	char str[N], * p = str;
	cin.getline(str, N);
	p = p + tj_strlen(str) - 1;
	unsigned int ans = 0,tmp=1;
	for (int bit = 0; bit < tj_strlen(str);
		bit++,p--,tmp*=2) {
		ans += (*p-'0') * tmp;
	}
	cout << ans << endl;
	return 0;
}