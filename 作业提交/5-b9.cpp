/*2152988 计科 杨恺铭*/
#include <iostream>
#include <cmath>
using namespace std;

const int N = 9;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
  ***************************************************************************/
int main()
{
	int sudoku[N][N];
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			while (1) {
				cin >> sudoku[i][j];
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (sudoku[i][j] >= 1 
					&& sudoku[i][j] <= N) {
					break;
				}
				cout << "请重新输入第" << i+1<<"行" << j+1
					<< "列(行列均从1开始计数)的值" << endl;
			}
		}
	}
	
	int ret = 1;
	for (int i = 0; i < N; i++) {
		int num[N + 1] = { -1 };
		for (int j = 0; j < N; j++) {
			num[sudoku[i][j]] = 1;
		}
		for (int k = 1; k <= N; k++) {
			if (num[k] == 0) {
				ret = 0;
				break;
			}
		}
	}
	if (ret) {
		for (int i = 0; i < N; i++) {
			int num[N + 1] = { -1 };
			for (int j = 0; j < N; j++) {
				num[sudoku[j][i]] = 1;
			}
			for (int k = 1; k <= N; k++) {
				if (num[k] == 0) {
					ret = 0;
					break;
				}
			} 
		}
	}
	if (ret) {
		for (int row = 0; row < N; row += 3) {
			for (int line = 0; line < N; line += 3) {
				
				int num[N + 1] = { -1 };
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						num[sudoku[row + a][line + b]] = 1;
					}
				}

				for (int k = 1; k <= N; k++) {
					if (num[k] == 0) {
						ret = 0;
						break;
					}
				}
			}
		}
	}

	if (ret) {
		cout << "是数独的解" << endl;
	}
	else {
		cout << "不是数独的解" << endl;
	}

	return 0;
}