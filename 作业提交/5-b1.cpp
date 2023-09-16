/* 2152988 计科 杨恺铭 */
#include <iostream>
using namespace std;
const int M = 21;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int num, i = 0;
	int array[M];
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	cin >> num;
	while (num >= 0 && i < 20) {
		array[i++] = num;
		cin >> num;
	}
	if (0 == i) {
		cout << "无有效输入" << endl;
		return -1;
	}
	if (i >= 20)
		cin.ignore(1024, '\n');
	int size = i;
	cout << "原数组为：" << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;



	cout << "请输入要插入的正整数" << endl;
	cin >> num;
	int j;
	for (j = 0; j < size; j++) {
		if (array[j] >= num)
			break;
	}
	for (int i = size - 1; i >= j; i--) {
		array[i + 1] = array[i];
	}
	array[j] = num;
	size++;
	cout << "插入后的数组为：" << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	return 0;
}