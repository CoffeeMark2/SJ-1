/*2152988 计科 杨恺铭*/
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

const int ROW = 10, LINE = 26, MINE = 50;
int main()
{
	srand((unsigned int)(time(0)));
	int cnt = 0;
	char map[ROW][LINE] = { '\0' };
	while (cnt < MINE) {
		int x = rand() % ROW, y = rand() % LINE;
		if (map[x][y] != '*') {
			map[x][y] = '*';
			cnt++;
		}
	}

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < LINE; j++) {
			if (map[i][j] != '*') {
				int cnt = 0;
				for (int x = i - 1; x < i - 1 + 3; x++) {
					for (int y = j - 1; y < j - 1 + 3; y++) {
						if ((x<0 || x>ROW - 1) ||
							(y<0 || y>LINE - 1) ||
							(x == i && y == j)) {
							continue;//越界问题
						}
						if ('*' == map[x][y]) {
							cnt++;
						}
					}
				}
				map[i][j] = char(cnt) + '0';
			}
		}
	}

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < LINE; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
