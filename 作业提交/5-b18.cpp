/*2152988 计科 杨恺铭*/
#include <iostream>
#include <time.h>
using namespace std;
static const char other[] = "~!@#$%^&*()-_=+[],.?";
const int N = 10, LENM = 17;

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
	if (upper_cur == upper && lower_cur == lower
		&& num_cur == num && other_cur == other1)
		return 1;
	return 0;
}

int main()
{
	char password[N][LENM];
	int length, upper, lower, num, other_n;
	int ret = 1;
	while (getchar() != '\n')
		;

	cin >> length >> upper >> lower >> num >> other_n;
	if (!(length >= 12 && length <= 16 && upper >= 2 
		&& lower >= 2 && num >= 2 && other_n >= 2
		&& (length == upper + lower + num + other_n)))
		ret = 0;
	else {
		for (int i = 0; i < N; i++) {
			cin.getline(password[i], LENM, '\n');
			if (!illegal_check(length, upper, lower, num, other_n, password[i])) {
				ret = 0;
			}
		}
	}

	if (ret)
		cout << "正确" << endl;
	else
		cout << "错误" << endl;

	return 0;
}