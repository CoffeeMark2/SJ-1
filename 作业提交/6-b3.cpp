/*2152988 �ƿ� ������*/
#include <iostream>
using namespace std;
int tj_strlen(const char str[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int cnt = 0;
	while (str[cnt] != '\0') {
		cnt++;
	}
	return cnt; //returnֵ�ɸ�����Ҫ�޸�
}
const int N = 33;

int main()
{
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
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