/*21529988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int a, b1, b2, b3, b4, b5;
	scanf("%d", &a);
	b1 = a % 10;
	b2 = a / 10 % 10;
	b3 = a / 100 % 10;
	b4 = a / 1000 % 10;
	b5 = a / 10000 % 10;
	printf("万位 : %d\n", b5);
	printf("千位 : %d\n", b4);
	printf("百位 : %d\n", b3);
	printf("十位 : %d\n", b2);
	printf("个位 : %d\n", b1);
    return 0;
}
