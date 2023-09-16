/*2152988 计科 杨恺铭*/
#include <iostream>
#include<iomanip>
using namespace std;

const int M = 1000;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	int a, num = 0;
	int array[M];
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	cin >> a;
	while (a >= 0 && num < M) {
		array[num++] = a;
		cin >> a;
	}
	if (0 == num) {
		cout << "无有效输入" << endl;
		return -1;
	}
	cout << "输入的数组为:" << endl;
	int i;
	for (i = 0; i < num; i++) {
		cout << array[i] << ' ';
		if ((i+1) % 10 == 0)
			cout << endl;
	}
	if ((i + 1) % 10 != 1) {
		cout << endl;
	}

	for (int i = 0; i < num-1 ; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (array[j] < array[j + 1]) {
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}

	}

	cout << "分数与名次的对应关系为:" << endl;
	int grade = array[0], cnt = 0, rank = 1;
	for (int i = 0; i < num; i++) {
		if (grade != array[i]) {
			grade = array[i];
			rank = cnt+1;
		}
		cout << grade << ' ' << rank << endl;
		cnt++;
	}

	return 0;
}