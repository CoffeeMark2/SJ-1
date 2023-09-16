/*2152988 计科 杨恺铭*/
// 2151753 彭坤宇 2152180 文溪 2152472 司盛宇 2152085 孙亦菲 2153323 张语

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

const int N = 16;//一行十六个字符值
const int LINE_M = 80;//一行文本长度，加上0D0A

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

//字符串十六进制转十进制
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
	clog << "文件名以下形式均可以:" << endl;
	clog << "    a.txt                     : 不带路径形式" << endl;
	clog << "    ..\\data\\b.dat             : 相对路径形式" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	clog << "请输入要转换的hex格式文件名 : ";

	char path_in[100];
	cin.getline(path_in, sizeof(path_in));

	ifstream in(path_in, ios::in | ios::binary);
	if (!in.is_open()) {
		cerr << "输入文件 " << path_in
			<< "打开失败!" << endl;
		return -1;
	}

	clog << "请输入转换后的文件名        : ";

	char path_out[100];
	cin.getline(path_out, sizeof(path_out));

	ofstream out(path_out, ios::out | ios::binary);
	if (!out.is_open()) {
		cerr << "输入文件 " << path_out
			<< "打开失败!" << endl;
		in.close();
		return -1;
	}

	//使用getline来整行读取，避免使用read出现.fail的情况
	int cnt = 0;
	while (in.peek() != EOF) {
		char tmp[LINE_M + 1];
		in.getline(tmp, sizeof(tmp));

		//验证偏移量，直接比较字符串很麻烦，转换为求和会简单
		const int H = 8;
		char head[H + 1];
		tj_strncpy(head, tmp, H);
		head[H] = 0;
		
		int sum_h = trans(head,H);
		if (sum_h != cnt * 16) {
			cerr << "最左侧的偏移量0x" << head << "不是期望值0x";
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
		if (deviation <= N/2) {  //缺八个及以下字符
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