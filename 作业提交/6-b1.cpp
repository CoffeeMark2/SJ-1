/*2152988 �ƿ� ������*/
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
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
			//ʲôʱ���ƶ���*p��������֮ǰ����
			pnum++;
			pa++;
			is_num = false;
		}
	}
	//!!!�ж��������������
	if (is_num)
		pnum++;
	cout << "����" << pnum - a << "������" << endl;
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