/*2152988 计科 杨恺铭*/
#include <iostream>
#include <time.h>
using namespace std;
static const char other[] = "~!@#$%^&*()-_=+[],.?";
const int N = 10, LENM = 17;

int input_check(int length, int upper, int lower, int num, int other)
{
	if (length < 12 || length>16)
		cout << "密码长度[" << length << "]不正确" << endl;
	else if (upper < 2)
		cout << "大写字母个数[" << upper << "]不正确" << endl;
	else if (lower < 2)
		cout << "小写字母个数[" << lower << "]不正确" << endl;
	else if (num < 2)
		cout << "数字个数[" << num << "]不正确" << endl;
	else if (other < 2)
		cout << "其它符号个数[" << other << "]不正确" << endl;
	else if (upper + lower + num + other > length) {
		cout << "所有字符类型之和[" << upper << '+' << lower << '+' 
			<< num << '+' << other<< "]大于总密码长度[" << length << ']' << endl;
	}
	else
		return 1;

	return 0;
}

int illegal_check(int length, int upper, int lower, int num, int other1, char password[LENM])
{
	int upper_cur = 0, lower_cur = 0, num_cur = 0, other_cur = 0;
	for (int i = 0; i < length; i++) {
		if (password[i] >= 'A' && password[i] <= 'Z')
			upper_cur++;
		else if (password[i] >= 'a' && password[i] <= 'z')
			lower_cur++;
		else if (password[i] >= '0' && password[i] <= '9')
			num_cur++;
		else
			other_cur++;
	}
	if (upper_cur >= upper && lower_cur >= lower
		&& num_cur >= num && other_cur >= other1)
		return 1;
	return 0;
}
void generate(int length, int upper, int lower, int num, int other1, char password[][LENM])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < length; j++) {

			int k = rand() % 94 + 33;
			if ((k >= 'A' && k <= 'Z') 
				|| (k >= 'a' && k <= 'z') || (k >= '0' && k <= '9')) {
				password[i][j] = k;
			}
			else {
				k = rand() % 20;
				password[i][j] = other[k];
			}
		}
		password[i][length] = '\0';

		//不用加入生成限制条件，可以做完后判断是否合法，不合法重新输出，
		//由于计算机运算速度很快，f本小题规模小，从概率论角度不会有太大的影响
		if (!illegal_check(length, upper, lower, num, other1, password[i])) {
			i--;
		}

	}
	
}

int main()
{
	srand((unsigned int)(time(0)));

	char password[N][LENM];
	int length, upper, lower, num, other;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， "
		"小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length >> upper >> lower >> num >> other;

	if (cin.fail()) {
		cout << "输入非法" << endl;
		return -1;
	}
	else if (!(input_check(length, upper, lower, num, other))) {
		return -1;
	}

	cout << length << ' ' << upper << ' '
		<< lower << ' ' << num << ' ' << other << endl;
	generate(length, upper, lower, num, other, password);

	for (int i = 0; i < N; i++) {
		cout << password[i] << endl;
	}

	return 0;
}