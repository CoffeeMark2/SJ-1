/*2152988 �ƿ� ������*/
#include <iostream>
#include <time.h>
using namespace std;
static const char other[] = "~!@#$%^&*()-_=+[],.?";
const int N = 10, LENM = 17;

int input_check(int length, int upper, int lower, int num, int other)
{
	if (length < 12 || length>16)
		cout << "���볤��[" << length << "]����ȷ" << endl;
	else if (upper < 2)
		cout << "��д��ĸ����[" << upper << "]����ȷ" << endl;
	else if (lower < 2)
		cout << "Сд��ĸ����[" << lower << "]����ȷ" << endl;
	else if (num < 2)
		cout << "���ָ���[" << num << "]����ȷ" << endl;
	else if (other < 2)
		cout << "�������Ÿ���[" << other << "]����ȷ" << endl;
	else if (upper + lower + num + other > length) {
		cout << "�����ַ�����֮��[" << upper << '+' << lower << '+' 
			<< num << '+' << other<< "]���������볤��[" << length << ']' << endl;
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

		//���ü���������������������������ж��Ƿ�Ϸ������Ϸ����������
		//���ڼ���������ٶȺܿ죬f��С���ģС���Ӹ����۽ǶȲ�����̫���Ӱ��
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
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� "
		"Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> length >> upper >> lower >> num >> other;

	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
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