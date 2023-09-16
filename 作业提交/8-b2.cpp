/*2152988 �ƿ� ������*/
// 2151753 ������ 2152180 ��Ϫ 2152472 ˾ʢ�� 2152085 ����� 2153323 ����

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

const int N = 16;//һ��ʮ�����ַ�ֵ
const int LINE_M = 80;//һ���ı����ȣ�����0D0A

char* tj_strncpy(char* s1, const char* s2, const int len)
{
	if (s1 == NULL || s2 == NULL) {
		return s1;
	}

	char* p1 = s1;
	const char* p2 = s2;

	while (*p2 && p2 - s2 < len) {
		*p1++ = *p2++;
	}
	return s1;
}

//�ַ���ʮ������תʮ����
int trans(char* c, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++) {

		if (c[i] >= 'A' && c[i] <= 'F') {
			sum = sum * 16 + c[i] - 'A' + 10;
		}
		else if (c[i] >= '0' && c[i] <= '9') {
			sum = sum * 16 + c[i] - '0';
		}
		else
			return -1;
	}
	return sum;
}

int main()
{
	clog << "�ļ���������ʽ������:" << endl;
	clog << "    a.txt                     : ����·����ʽ" << endl;
	clog << "    ..\\data\\b.dat             : ���·����ʽ" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
	clog << "������Ҫת����hex��ʽ�ļ��� : ";

	char path_in[100];
	cin.getline(path_in, sizeof(path_in));

	ifstream in(path_in, ios::in | ios::binary);
	if (!in.is_open()) {
		cerr << "�����ļ� " << path_in
			<< "��ʧ��!" << endl;
		return -1;
	}

	clog << "������ת������ļ���        : ";

	char path_out[100];
	cin.getline(path_out, sizeof(path_out));

	ofstream out(path_out, ios::out | ios::binary);
	if (!out.is_open()) {
		cerr << "�����ļ� " << path_out
			<< "��ʧ��!" << endl;
		in.close();
		return -1;
	}

	//ʹ��getline�����ж�ȡ������ʹ��read����.fail�����
	int cnt = 0;
	while (in.peek() != EOF) {
		char tmp[LINE_M + 1];
		in.getline(tmp, sizeof(tmp));

		//��֤ƫ������ֱ�ӱȽ��ַ������鷳��ת��Ϊ��ͻ��
		const int H = 8;
		char head[H + 1];
		tj_strncpy(head, tmp, H);
		head[H] = 0;
		
		int sum_h = trans(head,H);
		if (sum_h != cnt * 16) {
			cerr << "������ƫ����0x" << head << "��������ֵ0x";
			cerr << hex << setiosflags(ios::uppercase);
			cerr << setfill('0');
			cerr << setw(8) << cnt;
			cerr << setfill(' ');
			cerr << endl;
			in.close();
			out.close();
			return -1;
		}

		cnt++;

		int end = 0;
		int deviation = LINE_M - 1 - strlen(tmp);
		if (deviation == 0) {
			end = 61;
		}
		if (deviation <= N/2) {  //ȱ�˸��������ַ�
			end = 61 - deviation * 3;
		}
		else if (deviation < N) {
			end = 61 - (deviation + 1) * 3;
		}


		for (int i = 11; i < end; i += 3) {
			if (35 == i) {
				i -= 1;
				continue;
			}
			int x = (trans(&tmp[i], 2));
			char c = char(x);
			out.write(&c, 1);
		}

	}

	in.close();
	out.close();
	return 0;
}