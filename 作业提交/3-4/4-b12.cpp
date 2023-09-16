/*2152988 �ƿ� ������*/
#include <iostream>
#include <iomanip>
using namespace std;

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
	cout << setw(2) << n << "# " 
		<< src << "-->" << dst << endl;
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
	char src, dst,tmp;
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (n >= 1 && n <= 10) {
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
		else if ((src >= 'A' && src <= 'C')){
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
	cout << "�ƶ�����Ϊ:" << endl;
	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);

}