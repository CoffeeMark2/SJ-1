/*2152988 �ƿ� ������*/
// 2151753 ������ 2152472 ˾ʢ�� 2152871 ���� 2152085 ����� 2153323 ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 10
#define LINE 26
#define MINE 50
int main()
{
	srand((unsigned int)(time(0)));
	int cnt = 0;
	char map[ROW][LINE] = { '\0' };
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < LINE; j++) {
			scanf("%c ", &map[i][j]);
			if ('*' == map[i][j]) {
				cnt++;
			}
		}
	}
	if (cnt != MINE) {
		printf("����1\n");
		return -1;
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
							continue;//Խ������
						}
						if ('*' == map[x][y]) {
							cnt++;
						}
					}
				}
				if (map[i][j] != (char)(cnt)+'0') {
					printf("����2\n");
					return -1;
				}
			}
		}
	}

	//for (int i = 0; i < ROW; i++) {
	//	for (int j = 0; j < LINE; j++) {
	//		printf("%c ",map[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("��ȷ\n");
	return 0;
}