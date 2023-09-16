/*2152988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;
const int N_STACK = 3;
int cnt = 0;
int stack [N_STACK][N];
int top[N_STACK];
//int stack_a[N], stack_b[N], stack_c[N];//��¼����ջ
//int top_a, top_b, top_c;//ջ��ָ�루ָ�����Ԫ�ص���һ����

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void operate(char src, char dst)
{
	int pop = src - 'A';
	int push = dst - 'A';
	stack[push][top[push]++] = stack[pop][--top[pop]];

} 
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void output_stack(void) {
	for (int j = 0; j < N_STACK; j++) {
		cout << char(j + 'A') << ":";
		for (int i = 0; i < top[j]; i++) {
			cout << setw(2) << stack[j][i];
		}
		cout << setw(2 * (N - top[j])) << "";
		cout << ' ';
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
			char src����ʼ��
			char tmp���м���
			char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 0)
		return;
	hanoi(n - 1, src, dst, tmp);
	cout << "��" << setw(4) << ++cnt
		<< " ��(" << setw(2) << n << "): "
		<< src << "-->" << dst << ' ';

	operate(src, dst);
	output_stack();
	cout << endl;

	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
			2�������������ʱ������ʹ��ѭ��
			3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp;
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (n >= 1 && n <= N) {
			break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');
	while (1) {
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;
		if (src >= 'a' && src <= 'c')
			src -= 32;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if ((src >= 'A' && src <= 'C')) {
			break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');
	while (1) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		dst = (dst >= 'a' && dst <= 'c') ? dst - 32 : dst;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if ((dst >= 'A' && dst <= 'C')) {
			if (dst == src)
				cout << "Ŀ����(" << dst
				<< ")��������ʼ��(" << src << ")��ͬ\n";
			else
				break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');


	for (int i = 0; i < n; i++) {
		stack[src-'A'][i] = n - i;
	}
	top[src-'A'] = n;

	cout << "��ʼ:" << setw(16) << "";
	output_stack();
	cout << endl;

	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);
	return 0;
}