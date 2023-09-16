/*2152988 计科 杨恺铭*/
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

#define N 10

void input(string num[N], string name[N], int grade[N])
{
	for (int i = 0; i < N; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> num[i] >> name[i] >> grade[i];
	}
}
//选择法会打乱输入顺序
void sort(string num[N], string name[N], int grade[N])
{
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (grade[j] > grade[j + 1]) {
				int a = grade[j + 1];
				grade[j + 1] = grade[j];
				grade[j] = a;

				string t = num[j + 1];
				num[j + 1] = num[j];
				num[j] = t;

				string t2 = name[j + 1];
				name[j + 1] = name[j];
				name[j] = t2;
			}
		}
	}
}

void output(string num[N], string name[N], int grade[N])
{
	cout << endl;
	cout << "不及格名单(成绩升序):" << endl;
	for (int i = 0; i < 10; i++) {
		if (grade[i] < 60) {
			cout << name[i] << ' ' << num[i] << ' ' << grade[i] << endl;
		}
	}
}

int main()
{
	string num[N];
	string name[N];
	int grade[N];
	input(num, name, grade);
	sort(num, name, grade);
	output(num, name, grade);
	return 0;
}
