/*2152988 计科 杨恺铭*/
#include <iostream>
using namespace std;
const int STR = 3;
const int M = 128;
int main()
{
	char str[STR][M];
	for (int i = 0; i < STR; i++) {
		cout << "请输入第" << i+1 << "行" << endl;
		cin.getline(str[i], M);
	}
	int daxie = 0, xiaoxie = 0, 
		num = 0, space = 0, other = 0;
	for (int i = 0; i < STR; i++) {
		for (int j = 0; str[i][j]; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
				daxie++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
				xiaoxie++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9') {
				num++;
			}
			else if (str[i][j] == ' ') {
				space++;
			}
			else {
				other++;
			}
		}
	}
	cout << "大写 : " << daxie << endl;
	cout << "小写 : " << xiaoxie << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;

	return 0;
}