/*2152988 �ƿ� ������*/
#include <iostream>
using namespace std;

const int N = 81;
int tj_strlen(const char str[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int cnt = 0;
	while (str[cnt] != '\0') {
		cnt++;
	}
	return cnt; //returnֵ�ɸ�����Ҫ�޸�
}
int main()
{
	char str[N], * p1 = str, * p2 = str;
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, N, stdin);
	p2 = p2 + tj_strlen(str) - 1;
	//����س�
	//ֻ����δ����������²Ż��лس�
	//�������ֱ��
	if (*p2 == '\n') {
		*p2 = 0;
		p2--;
	}
	//���ǿմ��͵���
	//�մ��޷���������
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