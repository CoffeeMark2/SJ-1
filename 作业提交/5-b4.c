/*2152988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define M 1000
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
	printf( "请输入成绩（最多1000个），以-1结束" "\n");
	scanf("%d", &a);
	while (a >= 0 && num < M) {
		array[num++] = a;
		scanf("%d", &a);
	}
	if (0 == num) {
		printf( "无有效输入" "\n");
		return -1;
	}
	printf( "输入的数组为:" "\n");
	int i;
	for (i = 0; i < num; i++) {
		printf("%d ",array[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	if ((i + 1) % 10 != 1) {
		printf("\n");
	}

	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (array[j] < array[j + 1]) {
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}

	}

	printf( "分数与人数的对应关系为:" "\n");
	int grade = array[0], cnt = 0;
	for (int i = 0; i < num; i++) {
		if (grade != array[i]) {
			printf("%d %d\n",grade,cnt);
			grade = array[i];
			cnt = 0;
		}
		cnt++;
	}
	printf("%d %d\n", grade, cnt);

	return 0;
}