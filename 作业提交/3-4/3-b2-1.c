/*21529988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[1..30000]�������:\n");
	int a, b1, b2, b3, b4, b5;
	scanf("%d", &a);
	b1 = a % 10;
	b2 = a / 10 % 10;
	b3 = a / 100 % 10;
	b4 = a / 1000 % 10;
	b5 = a / 10000 % 10;
	printf("��λ : %d\n", b5);
	printf("ǧλ : %d\n", b4);
	printf("��λ : %d\n", b3);
	printf("ʮλ : %d\n", b2);
	printf("��λ : %d\n", b1);
    return 0;
}
