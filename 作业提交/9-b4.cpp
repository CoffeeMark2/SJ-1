/*2152988 �ƿ� ������*/

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	int i1 = 0, i2 = 0;//��һ��ѡ��or�ڶ���ѡ��
	friend class stu_list;
public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* ���������private���ݳ�Ա�ͳ�Ա���� */
	int n = 0;
public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */
	void sort();
};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
char* tj_strcpy(char* s1, const char* s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */

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
int stu_list::read(const char* filename, const int append)
{
	if (append == 0) {
		n = 0;
	}
	ifstream in(filename, ios::in);
	if (!in.is_open()) {
		cerr << "�ļ�["<<filename<< "]��ʧ��!" << endl;
		return -1;
	}
	//�㷨��̫��
	while (in.peek() != EOF) {
		//����buff����������һ��һ�еĶ�
		int no;
		char name[MAX_NAME_LEN];
		in >> no >> name;
		if (in.fail()) {
			//�����endl�޷���while�����˳�
			//cerr << "��ȡ����" << endl;
			in.clear();
			in.close();
			return 0;
		}
		int i = 0;
		if (append) {
			for (i = 0; i < n; i++) {
				if (no == stu[i].stu_no) {
					stu[i].i2 = 1;
					break;
				}
			}
		}	
		if (append==0 || i == n) {
			stu[n].stu_no = no;
			tj_strcpy(stu[n].stu_name, name);
			if (append == 0) {
				stu[n].i1 = 1;
			}
			++n;
		}
	}
	if (append == 1) {
		sort();
	}
	in.close();
	return 0;
}
void stu_list::sort()
{
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (stu[j].stu_no > stu[j + 1].stu_no) {
				stu_info tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = tmp;
			}

		}
	}
}
int stu_list::print(const char* prompt )
{
	cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
	cout << "===========================================================" << endl;
	cout << setiosflags(ios::left);
	for (int i = 0; i < n; ++i) {
		cout << setw(4) << i + 1;
		cout << ' ';
		cout << setw(7) << stu[i].stu_no;
		cout << ' ';
		cout << setw(MAX_NAME_LEN) << stu[i].stu_name;
		cout << ' ';
		
		if (stu[i].i1) {
			cout << setw(7) << "Y";
			if (stu[i].i2) {
				cout << "Y";
			}
			else {
				cout << "�˿�";
			}
		}
		else {
			cout << setw(7) << "/";
			cout << "��ѡ";
		}
		cout << endl;
	}
	cout << "===========================================================" << endl;
	return 0;
}//��ӡ��ǰ�����ѡ������

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}